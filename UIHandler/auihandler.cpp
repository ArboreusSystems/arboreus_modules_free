// ----------------------------------------------------------
/*!
	\class AUIHandler
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 08/05/2021 at 15:08:35
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "auihandler.h"

// Forwarded classes
#include <abackend.h>

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AUIHandler::AUIHandler(QObject* parent) : QObject(parent) {

}


// -----------
/*!
	\fn

	Doc.
*/

AUIHandler::~AUIHandler(void) {

}


// -----------
/*!
	\fn

	Doc.
*/

void AUIHandler::mInit(void) {

	pBackend = &ABackend::mInstance();

	pFonts = new AFonts(this);
	pFonts->mInit();

	_A_DEBUG << "AUIHandler initiated";

	emit sgInitiated();
}

