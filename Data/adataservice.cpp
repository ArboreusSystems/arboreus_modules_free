// ----------------------------------------------------------
/*!
    \class ADataService
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 26/06/2023 at 11:21:53
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "adataservice.h"

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

ADataService::ADataService(QObject* parent) : AThreadServiceTemplate(parent) {

	_A_DEBUG << "ADataService created";
}


// -----------
/*!
	\fn

	Doc.
*/

ADataService::~ADataService(void) {

	_A_DEBUG << "ADataService deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void ADataService::slInit(void) {

	_A_DEBUG << "ADataService initiated";
	emit sgInitiated();
}

