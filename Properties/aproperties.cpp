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

// Forwarded classes
#include <abackend.h>

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AProperties::AProperties(QObject *parent) : QObject(parent) {

	_A_DEBUG << "AProperties created";
}


// -----------
/*!
	\fn

	Doc.
*/

AProperties::~AProperties(void) {

	_A_DEBUG << "AProperties deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AProperties::mInit(void) {

	pBackend = &ABackend::mInstance();
	pConfig = qobject_cast<APropertiesConfig*>(pBackend->pApplicationConfig);

	this->mInitPaths();
	this->mInitIsDesktop();

	_A_DEBUG << "AProperties initiated";

	emit sgInitiated();
}


// -----------
/*!
	\fn

	Doc.
*/

void AProperties::mInitPaths(void) {

	pPathDataApplication = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) +
		"/" + this->mNameOrganisation() + "/" + this->mNameApplication();
	if (ADir::mEnsure(pPathDataApplication)) {
		_A_DEBUG << "Ensured Application Data path:" << pPathDataApplication;
	} else {
		_A_CRITICAL << "No Application Data path:" << pPathDataApplication;
	}

	pPathDataConfig = QStandardPaths::writableLocation(QStandardPaths::GenericConfigLocation) +
		"/" + this->mNameOrganisation() + "/" + this->mNameApplication();
	if (ADir::mEnsure(pPathDataConfig)) {
		_A_DEBUG << "Ensured Config Data path:" << pPathDataConfig;
	} else {
		_A_CRITICAL << "No Config Data path:" << pPathDataConfig;
	}

	pPathDataCache = QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) +
		"/" + this->mNameOrganisation() + "/" + this->mNameApplication();
	if (ADir::mEnsure(pPathDataCache)) {
		_A_DEBUG << "Ensured Cache Data path:" << pPathDataCache;
	} else {
		_A_CRITICAL << "No Cache Data path:" << pPathDataCache;
	}
}


// -----------
/*!
	\fn

	Doc.
*/

void AProperties::mInitIsDesktop(void) {

	if (
		qGuiApp->platformName() == QString("android") ||
		qGuiApp->platformName() == QString("ios")
	) {
		pIsDesktop = false;
	} else {
		pIsDesktop = true;
	}
}


// -----------
/*!
	\fn

	Doc.
*/

QString AProperties::mNameOrganisation(void) {

	return pConfig->APropertiesConfig_NameOrganisation();
}


// -----------
/*!
	\fn

	Doc.
*/

QString AProperties::mNameDomain(void) {

	return pConfig->APropertiesConfig_NameDomain();
}


// -----------
/*!
	\fn

	Doc.
*/

QString AProperties::mNameApplication() {

	return pConfig->APropertiesConfig_NameApplication();
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


// -----------
/*!
	\fn

	Doc.
*/

bool AProperties::mIsDesktop(void) {

	return pIsDesktop;
}

