// ----------------------------------------------------------
/*!
	\class AUsersService
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 27/02/2022 at 15:17:17
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "ausersservice.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AUsersService::AUsersService(QObject* parent) : AThreadServiceTemplate(parent) {

	_A_DEBUG << "AUsersService created";
}


// -----------
/*!
	\fn

	Doc.
*/

AUsersService::~AUsersService(void) {

	_A_DEBUG << "AUsersService deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersService::slInit(void) {

	_A_DEBUG << "AUsersService initiated";

	emit sgInitiated();
}
