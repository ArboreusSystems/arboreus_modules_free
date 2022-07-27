// ----------------------------------------------------------
/*!
	\class AApplicationHeartbeat
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 27/07/2022 at 13:44:04
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "aapplicationheartbeat.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AApplicationHeartbeat::AApplicationHeartbeat(AApplicationConfig* inConfig,QObject* parent) : QObject(parent) {

	if (inConfig) pConfig = inConfig;

	_A_DEBUG << "AApplicationHeartbeat created";
}


// -----------
/*!
	\fn

	Doc.
*/

AApplicationHeartbeat::~AApplicationHeartbeat(void) {

	_A_DEBUG << "AApplicationHeartbeat deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AApplicationHeartbeat::slInit(void) {

	pTimer = new QTimer(this);
	pTime = pConfig->AApplicationConfig_Heartbeat_DefaultTime();

	QObject::connect(
		pTimer,&QTimer::timeout,
		this,&AApplicationHeartbeat::slOnBeat
	);

	if (pConfig->AApplicationConfig_Heartbeat_DefaultAutostart()) {
		this->mStart();
	}

	_A_DEBUG << "AApplicationHeartbeat initiated";
}


// -----------
/*!
	\fn

	Doc.
*/

void AApplicationHeartbeat::mSetTime(int inTime) {

	pTime = inTime;
	if (pTimer->isActive()) {
		pTimer->stop();
		pTimer->start(pTime);
	}
}


// -----------
/*!
	\fn

	Doc.
*/

void AApplicationHeartbeat::mStart(void) {

	if (pTimer->isActive()) this->mStop();
	pTimer->start(pTime);

	_A_INFO << "AApplicationHeartbeat started";
}


// -----------
/*!
	\fn

	Doc.
*/

void AApplicationHeartbeat::mStartWithTime(int inTime) {

	pTime = inTime;
	if (pTimer->isActive()) pTimer->stop();
	pTimer->start(pTime);

	_A_INFO << "AApplicationHeartbeat started with time:" << pTime;
}


// -----------
/*!
	\fn

	Doc.
*/

void AApplicationHeartbeat::mStop(void) {

	if (pTimer->isActive()) pTimer->stop();

	_A_INFO << "AApplicationHeartbeat stopped";
}


// -----------
/*!
	\fn

	Doc.
*/

void AApplicationHeartbeat::slOnBeat(void) {

	pConfig->AApplicationConfig_Heartbeat_OnBeat();
	emit this->sgOnBeat();
}

