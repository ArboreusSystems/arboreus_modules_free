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

	qRegisterMetaType<ASettingsProperties>();

	QObject::connect(
		this,&ASettings::sgInit,
		this->mService(),&ASettingsService::slInit,
		Qt::QueuedConnection
	);
	QObject::connect(
		this->mService(),&ASettingsService::sgInitiated,
		this,&ASettings::slInitiated,
		Qt::QueuedConnection
	);
//	QObject::connect(
//		this,&ASettings::sgUpdate,
//		this->mService(),&ASettingsService::slUpdate
//	);
//	QObject::connect(
//		this->mService(),&ASettingsService::sgUpdated,
//		this,&ASettings::slUpdated
//	);

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
	pConfig = qobject_cast<ASettingsConfig*>(pBackend->pGlobalConfigObject);
	this->start(QThread::Priority::LowestPriority);

	ASettingsProperties oProperties;
	oProperties.Config = pBackend->pGlobalConfigObject;
	oProperties.Path = \
		pBackend->pProperties->mGetPathDataApplication() +
		"/" + pConfig->ASettingsConfig_ModuleName();

	if (ADir::mEnsure(oProperties.Path)) {
		_A_DEBUG << "Ensured path for settings:" << oProperties.Path;
		emit sgInit(oProperties);
	} else {
		_A_CRITICAL << "Failed to ensure path for settings:" << oProperties.Path;
	}
}


// -----------
/*!
	\fn

	Doc.
*/

ASettingsReply ASettings::mReadHandler(QString inKey) {

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

ASettingsReply ASettings::mWriteHandler(QString inKey, QVariant inValue) {

	AThreadObjectControllerTemplate oController;
	QEventLoop oEventLoop;

	ASettingsWriteAgent oAgent(this->mService()->pDBKeyValue,inKey,inValue);
	QObject::connect(
		&oAgent,&ASettingsAgent::sgFinished,
		&oEventLoop,&QEventLoop::quit
	);
	QObject::connect(
		&oController,&AThreadObjectControllerTemplate::sgRun,
		&oAgent,&ASettingsWriteAgent::slRun
	);
	oAgent.moveToThread(this);

	emit oController.sgRun();
	oEventLoop.exec();

	if (oAgent.pReply.Status) {
		emit this->sgDidWrite(oAgent.pKey,oAgent.pValue);
	}

	return oAgent.pReply;
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

QVariantMap ASettings::mRead(QString inKey) {

	return this->mReadHandler(inKey).mToVariantMap();
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ASettings::mWrite(QString inKey, QVariant inValue) {

	return this->mWriteHandler(inKey,inValue).mToVariantMap();
}


// -----------
/*!
	\fn

	Doc.
*/

//void ASettings::slUpdated(QString inKey, QVariant inValue) {

//	emit sgUpdated(inKey,inValue);
//}


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
