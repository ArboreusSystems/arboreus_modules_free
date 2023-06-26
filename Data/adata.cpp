// ----------------------------------------------------------
/*!
    \class AData
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 16/06/2023 at 19:48:12
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "adata.h"

// Forwarded classes
#include <abackend.h>

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

AData::AData(QObject* parent) : AThreadTemplate<ADataService>(new ADataService, parent) {

	QObject::connect(
		this,&AData::sgInit,
		this->mService(),&ADataService::slInit,
		Qt::QueuedConnection
	);
	QObject::connect(
		this->mService(),&ADataService::sgInitiated,
		this,&AData::slInitiated,
		Qt::QueuedConnection
	);

	_A_DEBUG << "AData created";
}


// -----------
/*!
	\fn

	Doc.
*/

AData::~AData(void) {

	_A_DEBUG << "AData deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AData::mInit(void) {

	pBackend = &ABackend::mInstance();

	emit this->sgInit();
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateValue AData::mValidateValueHandler(
	_A_ENUMS_DATA_TYPE inType, QVariant inValue, QVariantMap inProperties
) {

	AThreadObjectControllerTemplate oController;
	QEventLoop oEventLoop;

	ADataValidateValueAgent oAgent;
	oAgent.mInit(this->mService(),inType,inValue);
	QObject::connect(
		&oAgent,&ADataValidateValueAgent::sgFinished,
		&oEventLoop,&QEventLoop::quit
	);
	QObject::connect(
		&oController,&AThreadObjectControllerTemplate::sgRun,
		&oAgent,&ADataValidateValueAgent::slRun
	);
	oAgent.moveToThread(this);

	emit oController.sgRun();
	oEventLoop.exec();

	QObject::disconnect(&oAgent,nullptr,nullptr,nullptr);
	QObject::disconnect(&oController,nullptr,nullptr,nullptr);
	QObject::disconnect(&oEventLoop,nullptr,nullptr,nullptr);

	return oAgent.mReply();
}


// -----------
/*!
	\fn

	Doc.
*/

void AData::slInitiated(void) {

	emit sgInitiated();
	_A_DEBUG << "AData initiated";
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap AData::mValidateValue(
	_A_ENUMS_DATA_TYPE inType, QVariant inValue,QVariantMap inProperties
) {

	ADataReplyValidateValue oReply = this->mValidateValueHandler(inType,inValue,inProperties);
	return oReply.mToVariantMap();
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap AData::mValidateStructure(
	QVariantMap inModel, QVariant inStructure, QVariantMap inProperties
) {

	QVariantMap oOutput;
	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap AData::mValidateList(
	QVariantMap inModel, QVariantList inList, QVariantMap inProperties
) {

	QVariantMap oOutput;
	return oOutput;
}

