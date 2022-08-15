// ----------------------------------------------------------
/*!
	\class ALoggerDBAgent
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 03/08/2022 at 15:00:11
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "aloggerdbagent.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ALoggerDBAgent::ALoggerDBAgent(QObject* parent) : QObject(parent) {

	_A_DEBUG << "ALoggerDBAgent created";
}


// -----------
/*!
	\fn

	Doc.
*/

ALoggerDBAgent::~ALoggerDBAgent(void) {

	_A_DEBUG << "ALoggerDBAgent deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void ALoggerDBAgent::mInit(ALoggerServiceProperties inProperties) {

	Q_UNUSED(inProperties)
	_A_DEBUG << "ALoggerDBAgent initiated";
}


// -----------
/*!
	\fn

	Doc.
*/

void ALoggerDBAgent::mWriteToLogbook(ALoggerMessageModel inMessageModel) {

	Q_UNUSED(inMessageModel)
}

