// ----------------------------------------------------------
/*!
	\class ADBSqlCipher
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 03/03/2021 at 17:01:32
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "adbsqlcipher.h"

// Namespaces
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ADBSqlCipher::ADBSqlCipher(QObject* inParent) : QObject(inParent) {

	A_CONSOLE_MESSAGE_DEBUG("ADBSqlCipher created");
}


// -----------
/*!
	\fn

	Doc.
*/

ADBSqlCipher::ADBSqlCipher(ASqlCipherProperties* inProperties, QObject* inParent) : QObject(inParent) {

	qDebug() << "ADBSqlCipher LoggerService:" << QThread::currentThreadId();

	this->mStart(inProperties);

	A_LOGGER_MESSAGE_INIT;
	oMessage = std::string("ADBSqlCipher created with properties: \n") +
		"Name: " + inProperties->Name.toStdString() + "\n" +
		"Path: " + inProperties->Path.toStdString();
	A_CONSOLE_MESSAGE_DEBUG(oMessage.c_str());
}


// -----------
/*!
	\fn

	Doc.
*/

ADBSqlCipher::~ADBSqlCipher(void) {

	this->mClose();
	A_CONSOLE_MESSAGE_DEBUG("ADBSqlCipher deleted");
}


// -----------
/*!
	\fn

	Doc.
*/

bool ADBSqlCipher::mStart(ASqlCipherProperties* inProperties) {

	A_LOGGER_MESSAGE_INIT;

	if (this->mCheckDriver()) {

		pDB = QSqlDatabase::addDatabase("SQLITECIPHER",inProperties->Name);
		pDB.setDatabaseName(inProperties->Path);
		if (inProperties->Value != A_DB_NULL_VALUE_QSTRING) {
			pDB.setPassword(inProperties->Value);
		}
		if (pDB.open()) {
			oMessage = std::string("Opened DB -> ") + inProperties->Path.toStdString();
			A_CONSOLE_MESSAGE_DEBUG(oMessage.c_str());
			return true;
		}

		oMessage = std::string("Opening DB Failed -> ") +
			inProperties->Name.toStdString() + ": " +
			inProperties->Path.toStdString();

	} else {
		oMessage = std::string("No SQLITECIPHER driver available");
	}

	A_CONSOLE_MESSAGE_CRITICAL(oMessage.c_str());
	return false;
}


// -----------
/*!
	\fn

	Doc.
*/

bool ADBSqlCipher::mClose(void) {

	A_LOGGER_MESSAGE_INIT;
	if (pDB.isOpen()) {pDB.close();}
	if (!pDB.isOpen()) {
		oMessage = std::string("DB Closed -> ") + pDB.connectionName().toStdString();
		A_CONSOLE_MESSAGE_DEBUG(oMessage.c_str());
		return true;
	}

	oMessage = std::string("Closing DB failed -> ") + pDB.connectionName().toStdString();
	A_CONSOLE_MESSAGE_CRITICAL(oMessage.c_str());
	return false;
}


// -----------
/*!
	\fn

	Doc.
*/

ASqlCipherReply ADBSqlCipher::mStringTransaction(QString inQueryString) {

	ASqlCipherReply oReply = {};
	A_LOGGER_MESSAGE_INIT;

	if (pDB.transaction()) {
		QSqlQuery oQuery(pDB);
		if (!oQuery.prepare(inQueryString)) {
			oMessage = std::string("Transactioned query not prepared: ") + inQueryString.toStdString();
			A_CONSOLE_MESSAGE_CRITICAL(oMessage.c_str());
			return oReply;
		}
		if (!oQuery.exec()) {
			oMessage = std::string("Transactioned query not executed: ") + inQueryString.toStdString();
			A_CONSOLE_MESSAGE_CRITICAL(oMessage.c_str());
			return oReply;
		}
		if (!pDB.commit()) {
			oMessage = std::string("Transaction not committed for query: ") + inQueryString.toStdString();
			A_CONSOLE_MESSAGE_CRITICAL(oMessage.c_str());
			if (!pDB.rollback()) {
				oMessage = std::string("Transaction not rolled back for query: ") + inQueryString.toStdString();
				A_CONSOLE_MESSAGE_CRITICAL(oMessage.c_str());
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
		oMessage = std::string("Transaction not started for query: ") + inQueryString.toStdString();
		A_CONSOLE_MESSAGE_CRITICAL(oMessage.c_str());
	}

	return oReply;
}


// -----------
/*!
	\fn

	Doc.
*/

ASqlCipherReply ADBSqlCipher::mStringExecute(QString inQueryString) {

	ASqlCipherReply oReply = {};
	A_LOGGER_MESSAGE_INIT;

	QSqlQuery oQuery(pDB);
	if (!oQuery.prepare(inQueryString)) {
		oMessage = std::string("Query not prepared: ") + inQueryString.toStdString();
		A_CONSOLE_MESSAGE_CRITICAL(oMessage.c_str());
		return oReply;
	}
	if (!oQuery.exec()) {
		oMessage = std::string("Query not executed: ") + inQueryString.toStdString();
		A_CONSOLE_MESSAGE_CRITICAL(oMessage.c_str());
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

ASqlCipherReply ADBSqlCipher::mQueryExecute(QSqlQuery inQuery) {

	ASqlCipherReply oReply = {};

	if (!inQuery.exec()) {
		A_CONSOLE_MESSAGE_CRITICAL("Query object not executed");
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

ASqlCipherReply ADBSqlCipher::mQueryTransaction(QSqlQuery inQuery) {

	ASqlCipherReply oReply = {};

	if (pDB.transaction()) {
		if (!inQuery.exec()) {
			A_CONSOLE_MESSAGE_CRITICAL("Transaction for QSqlQuery object not executed");
			return oReply;
		}
		if (!pDB.commit()) {
			A_CONSOLE_MESSAGE_CRITICAL("Transaction for QSqlQuery object not committed");
			if (!pDB.rollback()) {
				A_CONSOLE_MESSAGE_CRITICAL("Transaction for QSqlQuery object not rolled back");
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
		A_CONSOLE_MESSAGE_CRITICAL("Transaction for QSqlQuery object not started");
	}

	return oReply;
}


// -----------
/*!
	\fn

	Doc.
*/

bool ADBSqlCipher::mCheckDriver(void) {

	if (QSqlDatabase::drivers().contains("SQLITECIPHER")) {
		return true;
	}
	return false;
}
