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
void __attribute__((unused)) fLoggerWriteToLogbook(ARB::ALoggerMessageModel inModel) {

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

	ALoggerServiceProperties oProperties;
	oProperties.PathLoggerDB = pBackend->pProperties->mGetPathDataCache() + "/Logs";
	oProperties.PathLoggerFile = pBackend->pProperties->mGetPathDataDocuments() + "/Logs";
	oProperties.ConfigObject = pBackend->pGlobalConfigObject;

	bool oEnsurePathLoggerDB = ADir::mEnsure(oProperties.PathLoggerDB);
	bool oEnsurePathLoggerFile = ADir::mEnsure(oProperties.PathLoggerFile);
	if (oEnsurePathLoggerDB && oEnsurePathLoggerFile) {
		_A_DEBUG << "Ensured path for Logger DB:" << oProperties.PathLoggerDB;
		_A_DEBUG << "Ensured path for Logger File:" << oProperties.PathLoggerFile;
		emit sgInit(oProperties);
	} else {
		_A_CRITICAL << "Failed to ensure path for Logger DB:" << oProperties.PathLoggerDB;
		_A_CRITICAL << "Failed to ensure path for Logger File:" << oProperties.PathLoggerFile;
	}

	_A_DEBUG << "ALogger initiated";
}


// -----------
/*!
	\fn

	Doc.
*/

void ALogger::mWriteToLogbook(ALoggerMessageModel inMessageModel) {

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

