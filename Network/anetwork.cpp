// ----------------------------------------------------------
/*!
	\class ANetwork
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 04/05/2021 at 13:31:50
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "anetwork.h"

// Forwarded classes
#include <abackend.h>

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ANetwork::ANetwork(QObject* parent) : AThreadTemplate<ANetworkService>(new ANetworkService, parent) {

	QObject::connect(
		this,&ANetwork::sgInit,
		this->mService(),&ANetworkService::slInit,
		Qt::QueuedConnection
	);
	QObject::connect(
		this->mService(),&ANetworkService::sgInitiated,
		this,&ANetwork::slInitiated,
		Qt::QueuedConnection
	);

	_A_DEBUG << "ANetwork created";
}


// -----------
/*!
	\fn

	Doc.
*/

ANetwork::~ANetwork(void) {

	_A_DEBUG << "ANetwork deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void ANetwork::mInit(void) {

	pBackend = &ABackend::mInstance();
	this->start(QThread::Priority::LowPriority);

	emit sgInit();
}


// -----------
/*!
	\fn

	Doc.
*/

ANetworkReply ANetwork::mPOSTRequest(ANetworkRequestProperties inProperties) {

	AThreadObjectControllerTemplate oController;
	QEventLoop oEventLoop;

	ANetworkAgent oAgent(inProperties,this->mService()->mGetNetworkManager());
	QObject::connect(
		&oAgent,&ANetworkAgent::sgFinished,
		&oEventLoop,&QEventLoop::quit
	);
	QObject::connect(
		&oController,&AThreadObjectControllerTemplate::sgRun,
		&oAgent,&ANetworkAgent::slPOST
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

ANetworkReply ANetwork::mGETRequest(ANetworkRequestProperties inProperties) {

	AThreadObjectControllerTemplate oController;
	QEventLoop oEventLoop;

	ANetworkAgent oAgent(inProperties,this->mService()->mGetNetworkManager());
	QObject::connect(
		&oAgent,&ANetworkAgent::sgFinished,
		&oEventLoop,&QEventLoop::quit
	);
	QObject::connect(
		&oController,&AThreadObjectControllerTemplate::sgRun,
		&oAgent,&ANetworkAgent::slGET
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

void ANetwork::slInitiated(void) {

	_A_DEBUG << "ANetwork initiated";

	emit sgInitiated();
}
