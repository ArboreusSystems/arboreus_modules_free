// ----------------------------------------------------------
/*!
	\class AUsersCreateAgent
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 19/08/2022 at 06:54:18
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "auserscreateagent.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AUsersCreateAgent::AUsersCreateAgent(QObject* parent) : AThreadAgentTemplate(parent) {

	_A_DEBUG << "AUsersCreateAgent created";
}


// -----------
/*!
	\fn

	Doc.
*/

AUsersCreateAgent::~AUsersCreateAgent(void) {

	_A_DEBUG << "AUsersCreateAgent deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersCreateAgent::slRun(void) {



	_A_DEBUG << "111111111111111111111111111111";
	_A_DEBUG << pData;

	emit sgFinished();
}
