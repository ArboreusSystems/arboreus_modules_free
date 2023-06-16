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

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

AData::AData(QObject* parent) : QObject(parent) {

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

