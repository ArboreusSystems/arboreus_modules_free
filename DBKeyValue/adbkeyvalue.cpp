// ----------------------------------------------------------
/*!
	\class ADBKeyValue
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 09/03/2023 at 13:49:01
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "adbkeyvalue.h"

// Namespace definition
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ADBKeyValue::ADBKeyValue(QObject* parent) : QObject(parent) {

	_A_DEBUG << "ADBKeyValue created";
}


// -----------
/*!
	\fn

	Doc.
*/

ADBKeyValue::~ADBKeyValue(void) {

	_A_DEBUG << "ADBKeyValue deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

bool ADBKeyValue::mInit(ADBKeyValueProperties inProperties) {

	pProperties = new ADBKeyValueProperties(this);
	inProperties.mCopy(pProperties);

	ADBSqliteCipherProperties oDBproperties;
	oDBproperties.Name = pProperties->Name;
	oDBproperties.Path = pProperties->Path;

	if (pProperties->Encrypted) oDBproperties.Value = pProperties->Value;

	pDB = new ADBSqliteCipher(this);
	pDB->mStart(&oDBproperties);

	QString oSQL = \
		"CREATE TABLE IF NOT EXISTS " + pProperties->NameTable + " " +
		"(key STRING (25) PRIMARY KEY UNIQUE NOT NULL,value BLOB);";

	ADBSqliteReply oCreatingReply = pDB->mStringExecute(oSQL);
	if (!oCreatingReply.Status) {
		_A_CRITICAL << "Creating DBKeyValue failed for:" << pProperties->Path;
	} else {
		_A_DEBUG << "DBKeyValue storage created:" << pProperties->Path;
		return true;
	}

	return false;
}


// -----------
/*!
	\fn

	Doc.
*/

bool ADBKeyValue::mIsKey(QString inKey) {

	bool oOutput = false;

	ADBKeyValueReply oCheckingReply = this->mRead(inKey);
	switch (oCheckingReply.Status) {
		case _A_ENUM_DB_KEY_VALUE_REPLY_STATUS::Ok:
			oOutput = true;
			break;
		default:
			break;
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADBKeyValueReply ADBKeyValue::mRead(QString inKey) {

	ADBKeyValueReply oOutput;
	oOutput.Status = _A_ENUM_DB_KEY_VALUE_REPLY_STATUS::Error;

	QString oSQL = \
		"SELECT value FROM " + pProperties->NameTable + " " +
		"WHERE key='" + inKey + "';";

	ADBSqliteReply oReply = pDB->mStringExecute(oSQL);
	if (!oReply.Status) {
		_A_CRITICAL << "Reading from DBKeyValue failed for key:" << inKey << "in DB:" << pProperties->Path;
		return oOutput;
	} else {
		if (oReply.Output.length() == 0) {
			oOutput.Status = _A_ENUM_DB_KEY_VALUE_REPLY_STATUS::NotExisted;
		} else {
			oOutput.Status = _A_ENUM_DB_KEY_VALUE_REPLY_STATUS::Ok;
			oOutput.Data = qvariant_cast<QVariant>(oReply.Output[0]);
		}
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADBKeyValueReply ADBKeyValue::mReadAll(void) {

	ADBKeyValueReply oOutput;
	oOutput.Status = _A_ENUM_DB_KEY_VALUE_REPLY_STATUS::Error;

	ADBSqliteReply oReply = pDB->mStringExecute("SELECT * FROM " + pProperties->NameTable + ";");
	if (!oReply.Status) {
		_A_CRITICAL << "Reading all data from DBKeyValue failed:" << pProperties->Path;
		return oOutput;
	} else {
		oOutput.Status = _A_ENUM_DB_KEY_VALUE_REPLY_STATUS::Ok;
		oOutput.Data = oReply.Output;
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADBKeyValueReply ADBKeyValue::mWrite(QString inKey, QVariant inValue) {

	ADBKeyValueReply oReply;
	oReply.Status = _A_ENUM_DB_KEY_VALUE_REPLY_STATUS::Error;

	QString oSQL = \
		"INSERT OR REPLACE INTO " + pProperties->NameTable + " (key,value)" +
		"VALUES (:key,:value);";

	QSqlQuery oQuery(pDB->mGetDB());
	if (!oQuery.prepare(oSQL)) {
		_A_CRITICAL << "Preraring query for writing in DBKeyValue " << pProperties->NameTable << "failed";
		return oReply;
	}
	oQuery.bindValue(":key",inKey);
	oQuery.bindValue(":value",inValue);

	ADBSqliteReply oDBReply = pDB->mQueryTransaction(std::move(oQuery));
	if (!oDBReply.Status) {
		_A_CRITICAL << "Writing query in DBKeyValue " << pProperties->NameTable << "failed";
		return oReply;
	} else {
		oReply.Status = _A_ENUM_DB_KEY_VALUE_REPLY_STATUS::Ok;
	}

	return oReply;
}

