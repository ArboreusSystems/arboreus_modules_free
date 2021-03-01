// ----------------------------------------------------------
/*!
	\class AProperties
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 28/02/2021 at 15:01:40
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "aproperties.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AProperties::AProperties(QObject *parent) : QObject(parent) {

}


// -----------
/*!
	\fn

	Doc.
*/

AProperties::~AProperties(void) {

}


// -----------
/*!
	\fn

	Doc.
*/

AProperties& AProperties::mInstance(void) {

	static AProperties oInstance;
	return oInstance;
}


// -----------
/*!
	\fn

	Doc.
*/

void AProperties::mInit(void) {

	this->mInitPaths();
}


// -----------
/*!
	\fn

	Doc.
*/

void AProperties::mInitPaths(void) {

	// TODO: Add console message for result of directory ensuring
	pPathDataApplication = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + "/" + pNameApplication;
	if (ADir::mEnsure(pPathDataApplication)) {

	} else {

	}

	// TODO: Add console message for result of directory ensuring
	pPathDataConfig = QStandardPaths::writableLocation(QStandardPaths::GenericConfigLocation) + "/" + pNameApplication;
	if (ADir::mEnsure(pPathDataConfig)) {

	} else {

	}

	// TODO: Add console message for result of directory ensuring
	pPathDataCache = QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + "/" + pNameApplication;
	if (ADir::mEnsure(pPathDataCache)) {

	} else {

	}
}


// -----------
/*!
	\fn

	Doc.
*/

void AProperties::mSetNameOrganisation(QString inName) {

	pNameOrganisation = inName;
}


// -----------
/*!
	\fn

	Doc.
*/

QString AProperties::mGetNameOrganisation(void) {

	return pNameOrganisation;
}


// -----------
/*!
	\fn

	Doc.
*/

void AProperties::mSetNameDomain(QString inName) {

	pNameDomain = inName;
}


// -----------
/*!
	\fn

	Doc.
*/

QString AProperties::mGetNameDomain(void) {

	return pNameDomain;
}


// -----------
/*!
	\fn

	Doc.
*/

void AProperties::mSetNameApplication(QString inName) {

	pNameApplication = inName;
}


// -----------
/*!
	\fn

	Doc.
*/

QString AProperties::mGetNameApplication() {

	return pNameApplication;
}


// -----------
/*!
	\fn

	Doc.
*/

QString AProperties::mGetPathDataApplication(void) {

	return pPathDataApplication;
}


// -----------
/*!
	\fn

	Doc.
*/

QString AProperties::mGetPathDataConfig(void) {

	return pPathDataConfig;
}


// -----------
/*!
	\fn

	Doc.
*/

QString AProperties::mGetPathDataCache(void) {

	return pPathDataCache;
}

