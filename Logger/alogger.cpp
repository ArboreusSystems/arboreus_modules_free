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
#include <aclientbackend.h>

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ALogger::ALogger(QObject *parent) : AThreadTemplate<ALoggerService>(new ALoggerService, parent) {

	QObject::connect(
		this,&ALogger::sgInit,
		this->mService(),&ALoggerService::slInit
	);
	QObject::connect(
		this,&ALogger::sgWriteToDB,
		this->mService(),&ALoggerService::slWriteToDB
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

	pBackend = &AClientBackend::mInstance();
	this->start(QThread::Priority::LowPriority);
	emit sgInit();

	_A_DEBUG << "ALogger initiated";
}


// -----------
/*!
	\fn

	Doc.
*/

void ALogger::mWriteToDB(ALoggerMessageModel* inMessageModel) {

	emit sgWriteToDB(inMessageModel);
}

