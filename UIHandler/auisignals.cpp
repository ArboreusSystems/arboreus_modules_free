// ----------------------------------------------------------
/*!
	\class AUISignals
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 13/03/2022 at 11:37:05
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "auisignals.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AUISignals::AUISignals(QObject* parent) : QObject(parent) {

	_A_DEBUG << "AUISignals created";
}


// -----------
/*!
	\fn

	Doc.
*/

AUISignals::~AUISignals(void) {

	_A_DEBUG << "AUISignals deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AUISignals::mInit(void) {

	_A_DEBUG << "AUISignals initiated";
}

