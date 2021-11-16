// ----------------------------------------------------------
/*!
	\class ASession
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 15/11/2021 at 18:23:56
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "asession.h"

// Forwarded classes
#include <abackend.h>

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ASession::ASession(QObject *parent) : QObject(parent) {

	_A_DEBUG << "ASession created";
}


// -----------
/*!
	\fn

	Doc.
*/

ASession::~ASession(void) {

	_A_DEBUG << "ASession deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void ASession::mInit(void) {

	pBackend = &ABackend::mInstance();

	_A_DEBUG << "ASession initiated";

	emit sgInitiated();
}


// -----------
/*!
	\fn

	Doc.
*/

void ASession::mPut(QString inKey, QVariant inValue) {

	pSession.insert(inKey,inValue);
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ASession::mGet(QString inKey) {

	ASessionReply oReply;

	QVariant oValue = pSession.value(inKey,"NoValue");
	if (oValue != "NoValue") {
		oReply.Status = true;
		oReply.Value = oValue;
	}

	return oReply.mToVariantMap();
}


// -----------
/*!
	\fn

	Doc.
*/

void ASession::mRemove(QString inKey) {

	pSession.remove(inKey);
}

