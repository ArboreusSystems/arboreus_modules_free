// ----------------------------------------------------------
/*!
	\class ADBSqlite
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 04/10/2021 at 14:33:15
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "adbsqlite.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ADBSqlite::ADBSqlite(QObject* parent) : QObject(parent) {

	pDriverName = "SQLITE";

	_A_DEBUG << "ADBSqlite created";
}


// -----------
/*!
	\fn

	Doc.
*/

ADBSqlite::~ADBSqlite(void) {

	this->mRemove();

	_A_DEBUG << "ADBSqlite deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

bool ADBSqlite::mStart(ADBProperties* inProperties) {

	ADBSqliteProperties* oProperties = static_cast<ADBSqliteProperties*>(inProperties);

	pName = oProperties->Name;
	pPath = oProperties->Path;

	QSqlDatabase oDB = QSqlDatabase::addDatabase(pDriverName,pName);
	oDB.setDatabaseName(pPath);

	if (oDB.open()) {
		_A_DEBUG << "Opened DB:" << pPath;
		return true;
	}

	_A_CRITICAL << "Failed to open DB:" << pPath << "With error:" << oDB.lastError().text();
	return false;
}



// -----------
/*!
	\fn

	Doc.
*/

void ADBSqlite::mRemove(void) {

	{
		QSqlDatabase oDB = this->mGetDB();
		oDB.close();
		if (!oDB.isOpen()) {
			_A_DEBUG << "Closed DB:" << pPath;
		} else {
			_A_CRITICAL << "Failed to close DB:" << pPath << "With error:" << oDB.lastError().text();
		}
	}

	QSqlDatabase::removeDatabase(pName);
}


// -----------
/*!
	\fn

	Doc.
*/

QString ADBSqlite::mGetDBName(void) {

	return pName;
}


// -----------
/*!
	\fn

	Doc.
*/

QSqlDatabase ADBSqlite::mGetDB(void) {

	QSqlDatabase oDB = QSqlDatabase::database(pName);
	return oDB;
}


// -----------
/*!
	\fn

	Doc.
*/

ADBSqliteReply ADBSqlite::mGetTableInfo(QString inTableName) {

	QString oSQLString = "PRAGMA table_info(" + inTableName + ");";
	ADBSqliteReply oOutput = this->mStringExecute(oSQLString);
	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADBSqliteReply ADBSqlite::mStringExecute(QString inQueryString) {

	ADBSqliteReply oReply = {};

	QSqlDatabase oDB = this->mGetDB();

	QSqlQuery oQuery(oDB);
	if (!oQuery.prepare(inQueryString)) {
		_A_CRITICAL << "Query not prepared:" << inQueryString \
			<< "With error" << oDB.lastError().text();
		return oReply;
	}
	if (!oQuery.exec()) {
		_A_CRITICAL << "Query not executed:" << inQueryString \
			<< "With error" << oDB.lastError().text();
		return oReply;
	}

	QVariantList oOutput = {};
	int oCounter = 0;
	while (oQuery.next()) {
		QList<QVariant> oRecord = {};
		for (int i = 0; i < QSqlRecord(oQuery.record()).count(); ++i) {
			oRecord.insert(i,oQuery.value(i));
		}
		oOutput.insert(oCounter,oRecord);
		++oCounter;
	}

	oReply.Status = true;
	oReply.Output = oOutput;

	return oReply;
}


// -----------
/*!
	\fn

	Doc.
*/

ADBSqliteReply ADBSqlite::mStringTransaction(QString inQueryString) {

	ADBSqliteReply oReply = {};

	QSqlDatabase oDB = this->mGetDB();

	if (oDB.transaction()) {
		QSqlQuery oQuery(oDB);
		if (!oQuery.prepare(inQueryString)) {
			_A_CRITICAL << "Transactioned query not prepared:" << inQueryString \
				<< "with error:" << oDB.lastError().text();
			return oReply;
		}
		if (!oQuery.exec()) {
			_A_CRITICAL << "Transactioned query not executed:" << inQueryString \
				<< "with error:" << oDB.lastError().text();
			return oReply;
		}
		if (!oDB.commit()) {
			_A_CRITICAL << "Transaction not committed for query:" << inQueryString \
				<< "with error:" << oDB.lastError().text();
			if (!oDB.rollback()) {
				_A_CRITICAL << "Transaction not rolled back for query:" << inQueryString \
					<< "with error:" << oDB.lastError().text();
			}
			return oReply;
		}
		QVariantList oOutput = {};
		int oCounter = 0;
		while (oQuery.next()) {
			QList<QVariant> oRecord = {};
			for (int i = 0; i < QSqlRecord(oQuery.record()).count(); ++i) {
				oRecord.insert(i,oQuery.value(i));
			}
			oOutput.insert(oCounter,oRecord);
			++oCounter;
		}
		oReply.Status = true;
		oReply.Output = oOutput;
	} else {
		_A_CRITICAL << "Transaction not started for query:" << inQueryString \
			<< "with error:" << oDB.lastError().text();
	}

	return oReply;
}


// -----------
/*!
	\fn

	Doc.
*/

ADBSqliteReply ADBSqlite::mQueryExecute(QSqlQuery inQuery) {

	ADBSqliteReply oReply = {};

	if (!inQuery.exec()) {
		_A_CRITICAL << "Query object not executed with error:" << inQuery.lastError().text();
		return oReply;
	}

	QVariantList oOutput = {};
	int oCounter = 0;
	while (inQuery.next()) {
		QList<QVariant> oRecord = {};
		for (int i = 0; i < QSqlRecord(inQuery.record()).count(); ++i) {
			oRecord.insert(i,inQuery.value(i));
		}
		oOutput.insert(oCounter,oRecord);
		++oCounter;
	}

	oReply.Status = true;
	oReply.Output = oOutput;

	return oReply;
}


// -----------
/*!
	\fn

	Doc.
*/

ADBSqliteReply ADBSqlite::mQueryTransaction(QSqlQuery inQuery) {

	ADBSqliteReply oReply = {};

	QSqlDatabase oDB = this->mGetDB();

	if (oDB.transaction()) {
		if (!inQuery.exec()) {
			_A_CRITICAL << "Transaction for QSqlQuery object not executed with error:" \
				<< oDB.lastError().text();
			return oReply;
		}
		if (!oDB.commit()) {
			_A_CRITICAL << "Transaction for QSqlQuery object not committed with error:" \
				<< oDB.lastError().text();
			if (!oDB.rollback()) {
				_A_CRITICAL << "Transaction for QSqlQuery object not rolled back with error:" \
					<< oDB.lastError().text();
			}
			return oReply;
		}
		QVariantList oOutput = {};
		int oCounter = 0;
		while (inQuery.next()) {
			QList<QVariant> oRecord = {};
			for (int i = 0; i < QSqlRecord(inQuery.record()).count(); ++i) {
				oRecord.insert(i,inQuery.value(i));
			}
			oOutput.insert(oCounter,oRecord);
			++oCounter;
		}
		oReply.Status = true;
		oReply.Output = oOutput;
	} else {
		_A_CRITICAL << "Transaction for QSqlQuery object not started with error:" \
			<< oDB.lastError().text();
	}

	return oReply;
}
