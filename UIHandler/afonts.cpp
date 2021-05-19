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

void AFonts::mInit(QList<QString> inFontList) {

	this->mSetFontList(inFontList);

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

void AFonts::mSetFontList(QList<QString> inFontList) {

	QFontDatabase::removeAllApplicationFonts();
	for (int i = 0; i < inFontList.size(); ++i) {
		QFontDatabase::addApplicationFont(inFontList[i]);
	}

	pFontFamily = QFontDatabase::applicationFontFamilies(0).first();

	_A_DEBUG << "Font family:" << pFontFamily;
}

