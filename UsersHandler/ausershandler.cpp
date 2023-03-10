// ----------------------------------------------------------
/*!
	\class AUsersHandler
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 08/03/2023 at 09:25:18
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "ausershandler.h"

// Namespace definition
using namespace ARB;

// Forwarded includes
#include <abackend.h>


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandler::AUsersHandler(QObject* parent) : AThreadTemplate<AUsersHandlerService>(new AUsersHandlerService, parent) {

	QObject::connect(
		this,&AUsersHandler::sgInit,
		this->mService(),&AUsersHandlerService::slInit
	);
	QObject::connect(
		this->mService(),&AUsersHandlerService::sgInitiated,
		this,&AUsersHandler::slInitiated
	);

	_A_DEBUG << "AUsersHandler created";
}


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandler::~AUsersHandler(void) {

	_A_DEBUG << "AUsersHandler deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersHandler::mInit(void) {

	emit this->sgInit();
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersHandler::slInitiated(void) {

	this->mSetCurrent("11111");

	_A_DEBUG << "AUsersHandler initiated";
	emit this->sgInitiated();
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersHandler::mSetCurrent(QString inID) {

}
