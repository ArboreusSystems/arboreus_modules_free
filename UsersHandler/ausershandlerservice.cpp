// ----------------------------------------------------------
/*!
	\class AUsersHandlerService
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 08/03/2023 at 09:26:06
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "ausershandlerservice.h"

// Namespace definition
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandlerService::AUsersHandlerService(QObject* parent) : AThreadServiceTemplate(parent) {

	_A_DEBUG << "AUserHandlerService created";
}


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandlerService::~AUsersHandlerService(void) {

	_A_DEBUG << "AUserHandlerService deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersHandlerService::slInit(void) {

	_A_DEBUG << "AUserHandlerService initiated";
	emit this->sgInitiated();
}
