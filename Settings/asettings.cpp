// ----------------------------------------------------------
/*!
	\class ASettings
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 02/05/2021 at 11:36:16
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "asettings.h"

// Forwarded classes
#include <abackend.h>

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ASettings::ASettings(QObject* parent) : AThreadTemplate<ASettingsService>(new ASettingsService, parent) {

	QObject::connect(
		this,&ASettings::sgInit,
		this->mService(),&ASettingsService::slInit
	);
	QObject::connect(
		this->mService(),&ASettingsService::sgInitiated,
		this,&ASettings::slInitiated
	);

	_A_DEBUG << "ASettings created";
}


// -----------
/*!
	\fn

	Doc.
*/

ASettings::~ASettings(void) {

	_A_DEBUG << "ASettings deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void ASettings::mInit(void) {

	pBackend = &ABackend::mInstance();
	this->start(QThread::Priority::LowestPriority);

	QString oPathSettingsData = pBackend->pProperties->mGetPathDataApplication() + "/Settings";
	if (ADir::mEnsure(oPathSettingsData)) {
		_A_DEBUG << "Ensured path for settings:" << oPathSettingsData;
		emit sgInit(oPathSettingsData);
	} else {
		_A_CRITICAL << "Failed to ensure path for settings:" << oPathSettingsData;
	}
}


// -----------
/*!
	\fn

	Doc.
*/

void ASettings::slInitiated(void) {

	_A_DEBUG << "ASettings initiated";

	emit sgInitiated();
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ASettings::mGet(QString inSettingsID) {

	ASettingsReply oOutput;
	oOutput.Data = pCache.value(inSettingsID,QString(A_SETTING_VALUE_NO_KEY));

	if (oOutput.Data != QString(A_SETTING_VALUE_NO_KEY)) {
		oOutput.Status = true;
		return oOutput.mToVariantMap();
	}

	oOutput = this->mGetFromDB(inSettingsID);
	if (oOutput.Status) {
		pCache.insert(inSettingsID,oOutput.Data);
	}
	return oOutput.mToVariantMap();
}


// -----------
/*!
	\fn

	Doc.
*/

ASettingsReply ASettings::mGetFromDB(QString inSettingsID) {

	AThreadObjectControllerTemplate oController;

	ASettingsReply oOutput;

	return oOutput;
}
