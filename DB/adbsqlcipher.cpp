// ----------------------------------------------------------
/*!
	\class ADBSqlCipher
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 01/05/2021 at 14:00:40
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "adbsqlcipher.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ADBSqlCipher::ADBSqlCipher(QObject *parent) : QObject(parent) {

	_A_DEBUG << "ADBSqlCipher created";
}


// -----------
/*!
	\fn

	Doc.
*/

ADBSqlCipher::~ADBSqlCipher(void) {

	if (pProperties) this->mRemove();

	_A_DEBUG << "ADBSqlCipher deleted with";
}


// -----------
/*!
	\fn

	Doc.
*/

bool ADBSqlCipher::mStart(ADBSqlCipherProperties* inProperties) {

	pProperties = inProperties;

	QSqlDatabase oDB = QSqlDatabase::addDatabase(A_DB_SQL_CIPHER_DRIVER,pProperties->Name);
	oDB.setDatabaseName(pProperties->Path);
	if (pProperties->Value != QString(A_DB_NULL_VALUE)) {
		oDB.setPassword(pProperties->Value);
	}

	if (oDB.open()) {
		_A_DEBUG << "Opened DB:" << pProperties->Path;
		return true;
	}

	_A_CRITICAL << "Failed to open DB:" << pProperties->Path;
	return false;
}


// -----------
/*!
	\fn

	Doc.
*/

void ADBSqlCipher::mRemove(void) {

	{
		QSqlDatabase oDB = QSqlDatabase::database(pProperties->Name);
		oDB.close();
		if (!oDB.isOpen()) {
			_A_DEBUG << "Closed DB" << pProperties->Path;
		} else {
			_A_CRITICAL << "Failed to close DB:" << pProperties->Path;
		}
	}

	QSqlDatabase::removeDatabase(pProperties->Name);
}


// -----------
/*!
	\fn

	Doc.
*/

ADBSqlCipherReply ADBSqlCipher::mStringExecute(QString inQueryString) {

	ADBSqlCipherReply oReply = {};

	QSqlDatabase oDB = QSqlDatabase::database(pProperties->Name);

	QSqlQuery oQuery(oDB);
	if (!oQuery.prepare(inQueryString)) {
		_A_CRITICAL << "Query not prepared:" << inQueryString;
		return oReply;
	}
	if (!oQuery.exec()) {
		_A_CRITICAL << "Query not executed:" << inQueryString;
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

ADBSqlCipherReply ADBSqlCipher::mStringTransaction(QString inQueryString) {

	ADBSqlCipherReply oReply = {};

	QSqlDatabase oDB = QSqlDatabase::database(pProperties->Name);

	if (oDB.transaction()) {
		QSqlQuery oQuery(oDB);
		if (!oQuery.prepare(inQueryString)) {
			_A_CRITICAL << "Transactioned query not prepared:" << inQueryString;
			return oReply;
		}
		if (!oQuery.exec()) {
			_A_CRITICAL << "Transactioned query not executed:" << inQueryString;
			return oReply;
		}
		if (!oDB.commit()) {
			_A_CRITICAL << "Transaction not committed for query:" << inQueryString;
			if (!oDB.rollback()) {
				_A_CRITICAL << "Transaction not rolled back for query:" << inQueryString;
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
		_A_CRITICAL << "Transaction not started for query: " << inQueryString;
	}

	return oReply;
}


// -----------
/*!
	\fn

	Doc.
*/

ADBSqlCipherReply ADBSqlCipher::mQueryExecute(QSqlQuery inQuery) {

	ADBSqlCipherReply oReply = {};

	if (!inQuery.exec()) {
		_A_CRITICAL << "Query object not executed";
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

ADBSqlCipherReply ADBSqlCipher::mQueryTransaction(QSqlQuery inQuery) {

	ADBSqlCipherReply oReply = {};

	QSqlDatabase oDB = QSqlDatabase::database(pProperties->Name);

	if (oDB.transaction()) {
		if (!inQuery.exec()) {
			_A_CRITICAL << "Transaction for QSqlQuery object not executed";
			return oReply;
		}
		if (!oDB.commit()) {
			_A_CRITICAL << "Transaction for QSqlQuery object not committed";
			if (!oDB.rollback()) {
				_A_CRITICAL << "Transaction for QSqlQuery object not rolled back";
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
		_A_CRITICAL << "Transaction for QSqlQuery object not started";
	}

	return oReply;
}
