// ----------------------------------------------------------
/*!
	\class AUsersHandler
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 08/03/2023 at 09:25:18
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "ausershandler.h"

// Namespace definition
using namespace ARB;

// Forwarded includes
#include <abackend.h>


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandler::AUsersHandler(QObject* parent) : AThreadTemplate<AUsersHandlerService>(new AUsersHandlerService, parent) {

	QObject::connect(
		this,&AUsersHandler::sgInit,
		this->mService(),&AUsersHandlerService::slInit
	);
	QObject::connect(
		this->mService(),&AUsersHandlerService::sgInitiated,
		this,&AUsersHandler::slInitiated
	);

	_A_DEBUG << "AUsersHandler created";
}


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandler::~AUsersHandler(void) {

	_A_DEBUG << "AUsersHandler deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersHandler::mInit(void) {

	pBackend = &ABackend::mInstance();
	pConfig = qobject_cast<AUsersHandlerConfig*>(pBackend->pGlobalConfigObject);
	pObjects = new AUsersHandlerObjects(pConfig,this);

	this->mInitPaths();
	this->mInitUsers();

	emit this->sgInit();
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersHandler::slInitiated(void) {

//	this->mSetCurrent("11111");

	_A_DEBUG << "AUsersHandler initiated";
	emit this->sgInitiated();
}


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandlerReply AUsersHandler::mSetCurrentHandler(QString inID) {

    AUsersHandlerReply oOutput;
    return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandlerReply AUsersHandler::mCreateHandler(AUsersHandlerUserData inUserData) {

	_A_DEBUG << "Create user: 2";

    AUsersHandlerReply oOutput;
	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersHandler::mInitPaths(void) {

	pPathDataApplication = \
		pBackend->pProperties->mGetPathDataApplication() + "/" +
		pConfig->AUsersHandlerConfig_ModuleName();
	if (ADir::mEnsure(pPathDataApplication)) {
		_A_DEBUG << "Ensured Users Applicatoin Data path:" << pPathDataApplication;
	} else {
		_A_CRITICAL << "No Users Applicatoin Data path:" << pPathDataApplication;
	}

	pPathDataConfig = \
		pBackend->pProperties->mGetPathDataConfig() + "/" +
		pConfig->AUsersHandlerConfig_ModuleName();
	if (ADir::mEnsure(pPathDataConfig)) {
		_A_DEBUG << "Ensured Users Config Data path:" << pPathDataConfig;
	} else {
		_A_CRITICAL << "No Users Config Data path:" << pPathDataConfig;
	}

	pPathDataCache = \
		pBackend->pProperties->mGetPathDataCache() + "/" +
		pConfig->AUsersHandlerConfig_ModuleName();
	if (ADir::mEnsure(pPathDataCache)) {
		_A_DEBUG << "Ensured Users Cache Data path:" << pPathDataCache;
	} else {
		_A_CRITICAL << "No Users Cache Data path:" << pPathDataCache;
	}

	pPathDataDocuments = \
		pBackend->pProperties->mGetPathDataDocuments() + "/" +
		pConfig->AUsersHandlerConfig_ModuleName();
	if (ADir::mEnsure(pPathDataDocuments)) {
		_A_DEBUG << "Ensured Users Documents Data path:" << pPathDataDocuments;
	} else {
		_A_CRITICAL << "No Users Documents Data path:" << pPathDataDocuments;
	}
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersHandler::mInitUsers(void) {

}
