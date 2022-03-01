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

	this->mInitDB(inProperties.DBTableProperties.Name);

	_A_DEBUG << "AUsersService initiated";

	emit sgInitiated();
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersService::mInitDB(QString inDBName) {

	ADBSqliteCipherProperties oDBproperties;
	oDBproperties.Name = QString(inDBName);
	oDBproperties.Path = this->pPathData + "/" + oDBproperties.Name + ".db";

	pDB = new ADBSqliteCipher(this);
	pDB->mStart(&oDBproperties);
}
