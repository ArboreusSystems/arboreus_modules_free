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

AApplication::AApplication(QObject *parent) : QObject(parent) {

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
	pConfig = qobject_cast<AApplicationConfig*>(pBackend->pApplicationConfigObject);
	pConstants = new AConstants(this);

	_A_DEBUG << "AApplication initiated";

	emit sgInitiated();
}


// -----------
/*!
	\fn

	Doc.
*/

void AApplication::mExit(void) {

	qApp->exit();
}
