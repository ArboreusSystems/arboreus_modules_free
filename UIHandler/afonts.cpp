// ----------------------------------------------------------
/*!
	\class AFonts
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 08/05/2021 at 15:09:47
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "afonts.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AFonts::AFonts(QObject* parent) : QObject(parent) {

	_A_DEBUG << "AFonts created";
}


// -----------
/*!
	\fn

	Doc.
*/

AFonts::~AFonts(void) {

	_A_DEBUG << "AFonts deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AFonts::mInit(void) {

	this->mInitFonts();

	_A_DEBUG << "AFonts initiated";
}


// -----------
/*!
	\fn

	Doc.
*/

QString AFonts::mFontFamily(void) {

	return pFontFamily;
}


// -----------
/*!
	\fn

	Doc.
*/

void AFonts::mSetFont(QString inFontFamily) {

	Q_UNUSED(inFontFamily);

	emit sgFontChanged();
}


// -----------
/*!
	\fn

	Doc.
*/

void AFonts::mInitFonts(void) {

	this->mSetFontFiraSansCondensed();
	pFontFamily = QFontDatabase::applicationFontFamilies(0).first();

	_A_DEBUG << "Font family:" << pFontFamily;
}


// -----------
/*!
	\fn

	Doc.
*/

void AFonts::mSetFontFiraSansCondensed(void) {

	QFontDatabase::removeAllApplicationFonts();
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-Black.ttf");
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-BlackItalic.ttf");
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-Bold.ttf");
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-BoldItalic.ttf");
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-ExtraBold.ttf");
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-ExtraBoldItalic.ttf");
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-ExtraLight.ttf");
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-ExtraLightItalic.ttf");
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-Italic.ttf");
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-Light.ttf");
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-LightItalic.ttf");
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-Medium.ttf");
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-MediumItalic.ttf");
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-Regular.ttf");
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-SemiBold.ttf");
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-SemiBoldItalic.ttf");
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-Thin.ttf");
	QFontDatabase::addApplicationFont(":/Resources/Fonts/FiraSansCondensed/FiraSansCondensed-ThinItalic.ttf");
}

