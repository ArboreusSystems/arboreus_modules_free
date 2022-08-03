// ----------------------------------------------------------
/*!
	\class ALoggerAgent
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 03/08/2022 at 15:08:45
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "aloggeragent.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ALoggerAgent::ALoggerAgent(QObject* parent) : QObject(parent) {

	_A_DEBUG << "ALoggerAgent created";
}


// -----------
/*!
	\fn

	Doc.
*/

ALoggerAgent::~ALoggerAgent(void) {

	_A_DEBUG << "ALoggerAgent deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void ALoggerAgent::mInit(ALoggerServiceProperties inProperties) {

	Q_UNUSED(inProperties)
	_A_DEBUG << "ALoggerAgent initiated";
}


// -----------
/*!
	\fn

	Doc.
*/

void ALoggerAgent::mWriteToLogbook(ALoggerMessageModel inMessageModel) {

	Q_UNUSED(inMessageModel)
	_A_DEBUG << "ALoggerAgent mWriteToLogbook";
}

