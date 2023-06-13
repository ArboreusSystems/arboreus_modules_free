// ----------------------------------------------------------
/*!
    \class AApplicationMetatypes
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 17:28:58
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "aapplicationmetatypes.h"

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

AApplicationMetatypes::AApplicationMetatypes(QObject* parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

AApplicationMetatypes::~AApplicationMetatypes(void) {}


// -----------
/*!
	\fn

	Doc.
*/

void AApplicationMetatypes::mInit(void) {

	qmlRegisterType<ARB::AEnumsApplicationStatus>("Arboreus", 1, 0, "AEnumsApplicationStatus");
	qRegisterMetaType<ARB::AEnumsApplicationStatus::Status>("ARB::AEnumsApplicationStatus::Status");
}

