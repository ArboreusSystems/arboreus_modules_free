// ----------------------------------------------------------
/*!
	\class AConstants
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 23/07/2021 at 18:25:26
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "aconstants.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AConstants::AConstants(QObject *parent) : QObject(parent) {

	_A_DEBUG << "AConstants created";
}


// -----------
/*!
	\fn

	Doc.
*/

AConstants::~AConstants(void) {

	_A_DEBUG << "AConstants deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

QString AConstants::mStringError(void) {

	return this->mString(_A_CONSTANT_STRING_ERROR);
}


// -----------
/*!
	\fn

	Doc.
*/

QString AConstants::mStringNormal(void) {

	return this->mString(_A_CONSTANT_STRING_NORMAL);
}


// -----------
/*!
	\fn

	Doc.
*/

QString AConstants::mStringOnClicked(void) {

	return this->mString(_A_CONSTANT_STRING_ON_CLICKED);
}


// -----------
/*!
	\fn

	Doc.
*/

QString AConstants::mStringOnPressed(void) {

	return this->mString(_A_CONSTANT_STRING_ON_PRESSED);
}


// -----------
/*!
	\fn

	Doc.
*/

QString AConstants::mString(const char* inValue) {

	QString oOutput(inValue);
	return oOutput;
}

