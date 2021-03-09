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

	A_CONSOLE_MESSAGE_DEBUG("AProperties created");
}


// -----------
/*!
	\fn

	Doc.
*/

AProperties::~AProperties(void) {

	A_CONSOLE_MESSAGE_DEBUG("AProperties deleted");
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

	A_LOGGER_MESSAGE_INIT;

	pPathDataApplication = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + "/" + pNameApplication;
	if (ADir::mEnsure(pPathDataApplication)) {
		oMessage = std::string("Ensured Application Data path -> ") + pPathDataApplication.toStdString();
		A_CONSOLE_MESSAGE_DEBUG(oMessage.c_str());
	} else {
		oMessage = std::string("No Application Data path -> ") + pPathDataApplication.toStdString();
		A_CONSOLE_MESSAGE_CRITICAL(oMessage.c_str());
	}

	pPathDataConfig = QStandardPaths::writableLocation(QStandardPaths::GenericConfigLocation) + "/" + pNameApplication;
	if (ADir::mEnsure(pPathDataConfig)) {
		oMessage = std::string("Ensured Config Data path -> ") + pPathDataConfig.toStdString();
		A_CONSOLE_MESSAGE_DEBUG(oMessage.c_str());
	} else {
		oMessage = std::string("No Config Data path -> ") + pPathDataConfig.toStdString();
		A_CONSOLE_MESSAGE_CRITICAL(oMessage.c_str());
	}

	pPathDataCache = QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + "/" + pNameApplication;
	if (ADir::mEnsure(pPathDataCache)) {
		oMessage = std::string("Ensured Cache Data path -> ") + pPathDataCache.toStdString();
		A_CONSOLE_MESSAGE_DEBUG(oMessage.c_str());
	} else {
		oMessage = std::string("No Cache Data path -> ") + pPathDataCache.toStdString();
		A_CONSOLE_MESSAGE_CRITICAL(oMessage.c_str());
	}

	pPathLogs = pPathDataCache + QString("/Logs");
	if (ADir::mEnsure(pPathLogs)) {
		oMessage = std::string("Ensured Logs path -> ") + pPathLogs.toStdString();
		A_CONSOLE_MESSAGE_DEBUG(oMessage.c_str());
	} else {
		oMessage = std::string("No Logs path -> ") + pPathLogs.toStdString();
		A_CONSOLE_MESSAGE_CRITICAL(oMessage.c_str());
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


// -----------
/*!
	\fn

	Doc.
*/

QString AProperties::mGetPathLogs(void) {

	return pPathLogs;
}


