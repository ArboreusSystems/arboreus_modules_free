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
#include "ausersservice.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AUsersService::AUsersService(QObject* parent) : AThreadServiceTemplate(parent) {

	_A_DEBUG << "AUsersService created";
}


// -----------
/*!
	\fn

	Doc.
*/

AUsersService::~AUsersService(void) {

	_A_DEBUG << "AUsersService deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersService::slInit(AUsersModuleProperties inProperties) {

	pConfig = inProperties.Config;

	QString oPathApplication = inProperties.PathApplication + "/Users";
	if (ADir::mEnsure(oPathApplication)) {
		this->pPathData = oPathApplication;
		_A_DEBUG << "Ensured Users Application path:" << this->pPathData;
	} else {
		_A_CRITICAL << "No Users Application path:" << oPathApplication;
	}

	QString oPathCache = inProperties.PathCache + "/Users";
	if (ADir::mEnsure(oPathCache)) {
		this->pPathCache = oPathCache;
		_A_DEBUG << "Ensured Users Cache path:" << this->pPathCache;
	} else {
		_A_CRITICAL << "No Users Cache path:" << oPathCache;
	}

	this->mInitDB(
		pConfig->AUsersConfig_DBTableName(),
		pConfig->AUsersConfig_DBTableProperties()
	);

	_A_DEBUG << "AUsersService initiated";

	emit sgInitiated();
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersService::mInitDB(QString inDBName,ADBTableProperties inTableProperties) {

	ADBSqliteCipherProperties oDBproperties;
	oDBproperties.Name = inDBName;
	oDBproperties.Path = this->pPathData + "/" + oDBproperties.Name + ".db";

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
