// ----------------------------------------------------------
/*!
	\class ANetworkService
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 04/05/2021 at 13:32:13
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "anetworkservice.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ANetworkService::ANetworkService(QObject* parent) : AThreadServiceTemplate(parent) {

	_A_DEBUG << "ANetworkService created";
}


// -----------
/*!
	\fn

	Doc.
*/

ANetworkService::~ANetworkService(void) {

	_A_DEBUG << "ANetworkService deleted";
}




// -----------
/*!
	\fn

	Doc.
*/

void ANetworkService::slInit(void) {

	emit sgInitiated();
}
