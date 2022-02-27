// ----------------------------------------------------------
/*!
	\class AUsers
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 27/02/2022 at 15:10:11
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "ausers.h"

// Forwarded classes
#include <abackend.h>

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AUsers::AUsers(QObject* parent) : AThreadTemplate<AUsersService>(new AUsersService,parent) {

	QObject::connect(
		this,&AUsers::sgInit,
		this->mService(),&AUsersService::slInit
	);
	QObject::connect(
		this->mService(),&AUsersService::sgInitiated,
		this,&AUsers::slInitiated
	);

	_A_DEBUG << "AUsers created";
}


// -----------
/*!
	\fn

	Doc.
*/

AUsers::~AUsers(void) {

	_A_DEBUG << "AUsers deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsers::mInit(void) {

	emit sgInit();
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsers::slInitiated(void) {

	_A_DEBUG << "AUsers initiated";

	emit sgInitiated();
}

