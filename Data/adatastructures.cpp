// ----------------------------------------------------------
/*!
    \class ADataStructure
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 16/06/2023 at 19:12:09
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "adatastructures.h"

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

ADataStructures::ADataStructures(QObject* parent) : QObject(parent) {

	_A_DEBUG << "ADataStructures created";
}


// -----------
/*!
	\fn

	Doc.
*/

ADataStructures::~ADataStructures(void) {

	_A_DEBUG << "ADataStructures deleted";
}

