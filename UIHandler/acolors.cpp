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

void AColors::mInit(QMap<QString,QString> inColorStrings) {

	this->mInitColors(inColorStrings);

	_A_DEBUG << "AColors initiated";
}


// -----------
/*!
	\fn

	Doc.
*/

void AColors::mInitColors(QMap<QString, QString> inColorStrings) {

	pColorStrings = inColorStrings;

	QMapIterator<QString,QString> iColorStrings(pColorStrings);
	while (iColorStrings.hasNext()) {
		iColorStrings.next();
		pColors.insert(iColorStrings.key(),QColor(iColorStrings.value()));
	}

	emit sgColorsInitiated();
}


// -----------
/*!
	\fn

	Doc.
*/

QColor AColors::mGetColor(QString inKey) {

	QColor oOutput(pDefaultColor);
	if (pColors.contains(inKey)) oOutput = pColors.value(inKey);
	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

QString AColors::mGetString(QString inKey) {

	QString oOutput = pDefaultColor;
	if (pColorStrings.contains(inKey)) oOutput = pColorStrings.value(inKey);
	return oOutput;
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
