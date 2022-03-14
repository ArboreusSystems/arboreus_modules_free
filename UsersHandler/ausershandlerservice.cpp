// ----------------------------------------------------------
/*!
	\class AUsersService
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 27/02/2022 at 15:17:17
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "ausershandlerservice.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandlerService::AUsersHandlerService(QObject* parent) : AThreadServiceTemplate(parent) {

	_A_DEBUG << "AUsersHandlerService created";
}


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandlerService::~AUsersHandlerService(void) {

	_A_DEBUG << "AUsersHandlerService deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersHandlerService::slInit(QObject* inConfig,QString inPath) {

	pUsersHandlerConfig = qobject_cast<AUsersHandlerConfig*>(inConfig);
	pApplicationConfig = qobject_cast<AApplicationConfig*>(inConfig);

	QString oPathApplication = inPath + "/";
	oPathApplication += pUsersHandlerConfig->AUsersHandlerConfig_ModuleName();

	if (ADir::mEnsure(oPathApplication)) {
		this->pPathData = oPathApplication;
		_A_DEBUG << "Ensured Users Application path:" << this->pPathData;
	} else {
		_A_CRITICAL << "No Users Application path:" << oPathApplication;
	}

	QString oPathCache = inPath + "/";
	oPathCache += pUsersHandlerConfig->AUsersHandlerConfig_ModuleName();

	if (ADir::mEnsure(oPathCache)) {
		this->pPathCache = oPathCache;
		_A_DEBUG << "Ensured Users Cache path:" << this->pPathCache;
	} else {
		_A_CRITICAL << "No Users Cache path:" << oPathCache;
	}

	this->mInitDB(
		pUsersHandlerConfig->AUsersHandlerConfig_DBTableName(),
		pUsersHandlerConfig->AUsersHandlerConfig_DBTableProperties()
	);

	_A_DEBUG << "AUsersService initiated";

	emit sgInitiated();
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersHandlerService::mInitDB(QString inDBName,ASqlCreateTableProperties inTableProperties) {

	ADBSqliteCipherProperties oDBproperties;
	oDBproperties.Name = inDBName;
	oDBproperties.Path = this->pPathData + "/" + oDBproperties.Name + ".db";

	if (pUsersHandlerConfig->AUsersHandlerConfig_Encrypted()) {
		oDBproperties.Value = pApplicationConfig->AApplicationConfig_Value();
	}

	pDB = new ADBSqliteCipher(this);
	pDB->mStart(&oDBproperties);

	ADBSqliteReply oCreatingReply = pDB->mStringExecute(
		ADBSqlGenerator::mStringCreateTable(inTableProperties)
	);
	if (!oCreatingReply.Status) {
		_A_CRITICAL << "Creating DB for users failed";
	} else {
		_A_DEBUG << "DB for users created";
	}
}
