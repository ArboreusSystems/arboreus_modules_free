// ----------------------------------------------------------
/*!
	\class AApplication
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 22/07/2021 at 17:15:29
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "aapplication.h"

// Forwarded classes
#include <abackend.h>

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AApplication::AApplication(QObject* parent) : AThreadTemplate<AApplicationService>(new AApplicationService, parent) {

	QObject::connect(
		this,&AApplication::sgInit,
		this->mService(),&AApplicationService::slInit,
		Qt::QueuedConnection
	);
	QObject::connect(
		this->mService(),&AApplicationService::sgInitiated,
		this,&AApplication::sgInitiated,
		Qt::QueuedConnection
	);

	_A_DEBUG << "AApplication created";
}


// -----------
/*!
	\fn

	Doc.
*/

AApplication::~AApplication(void) {

	_A_DEBUG << "AApplication deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AApplication::mInit(void) {

	pBackend = &ABackend::mInstance();
	pConstants = new AConstants(this);
	pConfig = qobject_cast<AApplicationConfig*>(pBackend->pGlobalConfigObject);

	this->setPriority(pConfig->AApplicationConfig_Application_ThreadPriority());

	pApplicationHeartbeat = new AApplicationHeartbeat(pConfig,this);
	QObject::connect(
		this,&AApplication::sgInit,
		pApplicationHeartbeat,&AApplicationHeartbeat::slInit
	);

	emit this->sgInit();
}


// -----------
/*!
	\fn

	Doc.
*/

QString AApplication::mValue(void) {

	return pConfig->AApplicationConfig_Registry_Value();
}


// -----------
/*!
	\fn

	Doc.
*/

QString AApplication::mSalt(void) {

	return pConfig->AApplicationConfig_Registry_Salt();
}


// -----------
/*!
	\fn

	Doc.
*/

void AApplication::slInitiated(void) {

	_A_DEBUG << "AApplication initiated";
	emit this->sgInitiated();
}


// -----------
/*!
	\fn

	Doc.
*/

void AApplication::mExit(void) {

	fLogger_Application_Exit();
	qApp->exit();

	_A_DEBUG << "AApplication mExit";
}
