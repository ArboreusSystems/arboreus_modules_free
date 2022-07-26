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
		this->mService(),&AApplicationService::slInit
	);
	QObject::connect(
		this->mService(),&AApplicationService::sgInitiated,
		this,&AApplication::sgInitiated
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
	pConfig = qobject_cast<AApplicationConfig*>(pBackend->pGlobalConfigObject);
	pConstants = new AConstants(this);

	emit this->sgInit();
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

	qApp->exit();
}
