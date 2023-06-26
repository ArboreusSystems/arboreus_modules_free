// ----------------------------------------------------------
/*!
    \class AData
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 16/06/2023 at 19:48:12
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "adata.h"

// Forwarded classes
#include <abackend.h>

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

AData::AData(QObject* parent) : AThreadTemplate<ADataService>(new ADataService, parent) {

	QObject::connect(
		this,&AData::sgInit,
		this->mService(),&ADataService::slInit,
		Qt::QueuedConnection
	);
	QObject::connect(
		this->mService(),&ADataService::sgInitiated,
		this,&AData::slInitiated,
		Qt::QueuedConnection
	);

	_A_DEBUG << "AData created";
}


// -----------
/*!
	\fn

	Doc.
*/

AData::~AData(void) {

	_A_DEBUG << "AData deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AData::mInit(void) {

	pBackend = &ABackend::mInstance();

	pTypes = new ADataTypes(pStructures,this);
	pStructures = new ADataStructures(pTypes,this);

	emit this->sgInit();
}


// -----------
/*!
	\fn

	Doc.
*/

void AData::slInitiated(void) {

	emit sgInitiated();
	_A_DEBUG << "AData initiated";
}

