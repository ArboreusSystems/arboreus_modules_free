// ----------------------------------------------------------
/*!
	\class AUIConfig
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 18/05/2021 at 20:30:03
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "auiconfig.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AUIConfig::AUIConfig(QObject* parent) : QObject(parent) {

	_A_DEBUG << "AUIConfig created";
}


// -----------
/*!
	\fn

	Doc.
*/

AUIConfig::~AUIConfig(void) {

	_A_DEBUG << "AUIConfig deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AUIConfig::mInit(AUIHandlerConfig* inConfig) {

	pConfig = inConfig;

	_A_DEBUG << "AUIConfig initiated";
}


// -----------
/*!
	\fn

	Doc.
*/

int AUIConfig::mUIWidth(void) {

	return pConfig->AUIHandlerConfig_UIWidth();
}


// -----------
/*!
	\fn

	Doc.
*/

int AUIConfig::mUIHeight(void) {

	return pConfig->AUIHandlerConfig_UIHeight();
}


// -----------
/*!
	\fn

	Doc.
*/

int AUIConfig::mDesktopUIWidth(void) {

	return pConfig->AUIHandlerConfig_DesktopUIWidth();
}


// -----------
/*!
	\fn

	Doc.
*/

int AUIConfig::mDesktopUIHeight(void) {

	return pConfig->AUIHandlerConfig_DesktopUIHeight();
}


// -----------
/*!
	\fn

	Doc.
*/

int AUIConfig::mFontSizeHeader(void) {

	return pConfig->AUIHandlerConfig_FontSizeHeader();
}


// -----------
/*!
	\fn

	Doc.
*/

int AUIConfig::mFontSizeRegular(void) {

	return pConfig->AUIHandlerConfig_FontSizeRegular();
}


// -----------
/*!
	\fn

	Doc.
*/

int AUIConfig::mFontSizeTextInput(void) {

	return pConfig->AUIHandlerConfig_FontSizeTextInput();
}


// -----------
/*!
	\fn

	Doc.
*/

int AUIConfig::mBorderSize(void) {

	return pConfig->AUIHandlerConfig_BorderSize();
}


// -----------
/*!
	\fn

	Doc.
*/

int AUIConfig::mRadius(void) {

	return pConfig->AUIHandlerConfig_Radius();
}


// -----------
/*!
	\fn

	Doc.
*/

int AUIConfig::mElementHeight(void) {

	return pConfig->AUIHandlerConfig_ElementHeight();
}


// -----------
/*!
	\fn

	Doc.
*/

QMap<QString, QString> AUIConfig::mColors(void) {

	return pConfig->AUIHandlerConfig_Colors();
}


// -----------
/*!
	\fn

	Doc.
*/

QList<QString> AUIConfig::mFonts(void) {

	return pConfig->AUIHandlerConfig_Fonts();
}
