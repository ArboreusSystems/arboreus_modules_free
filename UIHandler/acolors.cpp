// ----------------------------------------------------------
/*!
	\class AColors
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 08/05/2021 at 16:41:15
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "acolors.h"

// Namespace
using namespace ARB;

// -----------
/*!
	\fn

	Doc.
*/

AColors::AColors(QObject *parent) : QObject(parent) {

	_A_DEBUG << "AColors created";
}


// -----------
/*!
	\fn

	Doc.
*/

AColors::~AColors(void) {

	_A_DEBUG << "AColors deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AColors::mInit(void) {

	_A_DEBUG << "AColors initiated";
}


// -----------
/*!
	\fn

	Doc.
*/

QString AColors::mTransparent(void) {

	QString oColor("transparent");
	return oColor;
}


// -----------
/*!
	\fn

	Doc.
*/

QString AColors::mWhiteDark(void) {

	return pWhiteDark.name();
}


// -----------
/*!
	\fn

	Doc.
*/

QString AColors::mWhite(void) {

	return pWhite.name();
}


// -----------
/*!
	\fn

	Doc.
*/

QString AColors::mWhiteLight(void) {

	return pWhiteLight.name();
}
