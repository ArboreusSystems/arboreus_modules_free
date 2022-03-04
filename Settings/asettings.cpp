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
	QObject::connect(
		this,&ASettings::sgUpdate,
		this->mService(),&ASettingsService::slUpdate
	);
	QObject::connect(
		this->mService(),&ASettingsService::sgUpdated,
		this,&ASettings::slUpdated
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

ASettingsReply ASettings::mGet(QString inKey) {

	ASettingsReply oOutput;
	oOutput.Data = pCache.value(inKey,QString(A_SETTING_VALUE_NO_KEY));

	if (oOutput.Data != QString(A_SETTING_VALUE_NO_KEY)) {
		oOutput.Status = true;
		return oOutput;
	}

	oOutput = this->mGetFromDB(inKey);
	if (oOutput.Status) {
		pCache.insert(inKey,oOutput.Data);
	}
	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

void ASettings::mUpdate(QString inKey, QVariant inValue) {

	emit sgUpdate(inKey,inValue);
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

QVariantMap ASettings::mGetByKey(QString inKey) {

	return this->mGet(inKey).mToVariantMap();
}


// -----------
/*!
	\fn

	Doc.
*/

void ASettings::mUpdateByKey(QString inKey, QVariant inValue) {

	this->mUpdate(inKey,inValue);
}


// -----------
/*!
	\fn

	Doc.
*/

void ASettings::slUpdated(QString inKey, QVariant inValue) {

	emit sgUpdated(inKey,inValue);
}


// -----------
/*!
	\fn

	Doc.
*/

ASettingsReply ASettings::mGetFromDB(QString inKey) {

	AThreadObjectControllerTemplate oController;
	QEventLoop oEventLoop;

	ASettingsAgent oAgent(this->mService(),inKey);
	QObject::connect(
		&oAgent,&ASettingsAgent::sgFinished,
		&oEventLoop,&QEventLoop::quit
	);
	QObject::connect(
		&oController,&AThreadObjectControllerTemplate::sgRun,
		&oAgent,&ASettingsAgent::slRun
	);
	oAgent.moveToThread(this);

	emit oController.sgRun();
	oEventLoop.exec();

	return oAgent.pReply;
}


// -----------
/*!
	\fn

	Doc.
*/

bool ASettings::mIsKey(QString inKey) {

	QVariant oValue = pCache.value(inKey,QString(A_SETTING_VALUE_NO_KEY));
	if (oValue != QString(A_SETTING_VALUE_NO_KEY)) return true;

	ASettingsReply oOutput = this->mGetFromDB(inKey);
	return oOutput.Status;
}
