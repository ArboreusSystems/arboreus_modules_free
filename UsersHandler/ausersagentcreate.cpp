// ----------------------------------------------------------
/*!
	\class AUsersAgentCreate
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 18/03/2022 at 19:09:55
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "ausersagentcreate.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AUsersAgentCreate::AUsersAgentCreate(QObject* parent) : AThreadAgentTemplate(parent) {

	_A_DEBUG << "AUsersAgentCreate created";
}


// -----------
/*!
	\fn

	Doc.
*/

AUsersAgentCreate::~AUsersAgentCreate(void) {

	_A_DEBUG << "AUsersAgentCreate deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersAgentCreate::slRun(void) {

	_A_DEBUG << "111111111111111111111111111111";

	emit sgFinished();
}

