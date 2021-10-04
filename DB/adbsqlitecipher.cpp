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
#include "adbsqlitecipher.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ADBSqliteCipher::ADBSqliteCipher(QObject *parent) : ADBSqlite(parent) {

	pDriverName = "SQLITECIPHER";

	_A_DEBUG << "ADBSqliteCipher created";
}


// -----------
/*!
	\fn

	Doc.
*/

ADBSqliteCipher::~ADBSqliteCipher(void) {

	this->mRemove();

	_A_DEBUG << "ADBSqliteCipher deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

bool ADBSqliteCipher::mStart(ADBProperties* inProperties) {

	ADBSqliteCipherProperties* oProperties = static_cast<ADBSqliteCipherProperties*>(inProperties);

	pName = oProperties->Name;
	pPath = oProperties->Path;
	pValue = oProperties->Value;

	QSqlDatabase oDB = QSqlDatabase::addDatabase(pDriverName,pName);
	oDB.setDatabaseName(pPath);
	if (pValue != QString(A_DB_NULL_VALUE)) {
		oDB.setPassword(pValue);
	}

	if (oDB.open()) {
		_A_DEBUG << "Opened DB:" << pPath;
		return true;
	}

	_A_CRITICAL << "Failed to open DB:" << pPath << "With error:" << oDB.lastError().text();
	return false;
}


