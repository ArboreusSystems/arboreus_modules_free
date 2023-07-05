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
	QObject::connect(
		this,&ASettings::sgDidWrite,
		this,&ASettings::slDidWrite
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
		oOutput.Status = _A_ENUMS_DB_KEY_VALUE_REPLY_STATUS::Ok;
		return oOutput;
	}

	oOutput = this->mReadFromDB(inKey);
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
		&oAgent,&ASettingsWriteAgent::sgFinished,
		&oEventLoop,&QEventLoop::quit
	);
	QObject::connect(
		&oController,&AThreadObjectControllerTemplate::sgRun,
		&oAgent,&ASettingsWriteAgent::slRun
	);
	oAgent.moveToThread(this);

	emit oController.sgRun();
	oEventLoop.exec();

	if (oAgent.pReply.Status == _A_ENUMS_DB_KEY_VALUE_REPLY_STATUS::Ok) {
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

bool ASettings::mIsKey(QString inKey) {

	QVariant oValue = pCache.value(inKey,QString(A_SETTING_VALUE_NO_KEY));
	if (oValue != QString(A_SETTING_VALUE_NO_KEY)) return true;

	ASettingsReply oOutput = this->mReadFromDB(inKey);
	if (oOutput.Status == _A_ENUMS_DB_KEY_VALUE_REPLY_STATUS::Ok) {
		return true;
	}
	return false;
}


// -----------
/*!
	\fn

	Doc.
*/

ASettingsReply ASettings::mReadFromDB(QString inKey) {

	AThreadObjectControllerTemplate oController;
	QEventLoop oEventLoop;

	ASettingsReadAgent oAgent(this->mService()->pDBKeyValue,inKey);
	QObject::connect(
		&oAgent,&ASettingsReadAgent::sgFinished,
		&oEventLoop,&QEventLoop::quit
	);
	QObject::connect(
		&oController,&AThreadObjectControllerTemplate::sgRun,
		&oAgent,&ASettingsReadAgent::slRun
	);
	oAgent.moveToThread(this);

	emit oController.sgRun();
	oEventLoop.exec();

	if (oAgent.pReply.Status == _A_ENUMS_DB_KEY_VALUE_REPLY_STATUS::Ok) {
		pCache.insert(inKey,oAgent.pReply.Data);
	}

	return oAgent.pReply;
}


// -----------
/*!
	\fn

	Doc.
*/

void ASettings::slDidWrite(QString inKey, QVariant inValue) {

	pCache.insert(inKey,inValue);
}

