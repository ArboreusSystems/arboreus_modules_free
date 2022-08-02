// ----------------------------------------------------------
/*!
	\class ALogger
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 28/04/2021 at 19:50:47
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "alogger.h"

// Forwarded classes
#include <abackend.h>

// Namespace
using namespace ARB;


// -----------
// Global functions

// -----------
/*!
	\fn

	Doc.
*/
void __attribute__((unused)) fLoggerWriteToLogbook(ARB::ALoggerMessageModel* inModel) {

	ABackend::mInstance().pLogger->mWriteToLogbook(inModel);
}


// -----------
// Class definition

// -----------
/*!
	\fn

	Doc.
*/

ALogger::ALogger(QObject* parent) : AThreadTemplate<ALoggerService>(new ALoggerService, parent) {

	QObject::connect(
		this,&ALogger::sgInit,
		this->mService(),&ALoggerService::slInit
	);
	QObject::connect(
		this->mService(),&ALoggerService::sgInitiated,
		this,&ALogger::sgInitiated
	);
	QObject::connect(
		this,&ALogger::sgWriteToLogbook,
		this->mService(),&ALoggerService::slWriteToLogbook
	);

	_A_DEBUG << "ALogger created";
}


// -----------
/*!
	\fn

	Doc.
*/

ALogger::~ALogger(void) {

	_A_DEBUG << "ALogger deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void ALogger::mInit(void) {

	pBackend = &ABackend::mInstance();
	pConfig = qobject_cast<ALoggerConfig*>(pBackend->pGlobalConfigObject);

	this->setPriority(pConfig->ALoggerConfig_ThreadPriority());

	QString oPathLoggerData = pBackend->pProperties->mGetPathDataCache() + "/Logs";
	if (ADir::mEnsure(oPathLoggerData)) {
		_A_DEBUG << "Ensured path for logs:" << oPathLoggerData;
		emit sgInit(oPathLoggerData,pBackend->pGlobalConfigObject);
	} else {
		_A_CRITICAL << "Failed to ensure path for logs:" << oPathLoggerData;
	}

	_A_DEBUG << "ALogger initiated";
}


// -----------
/*!
	\fn

	Doc.
*/

void ALogger::mWriteToLogbook(ALoggerMessageModel* inMessageModel) {

	emit sgWriteToLogbook(inMessageModel);
}


// -----------
/*!
	\fn

	Doc.
*/

void ALogger::slInitiated(void) {

	emit sgInitiated();
}

