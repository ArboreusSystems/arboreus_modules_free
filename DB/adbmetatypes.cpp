// ----------------------------------------------------------
/*!
    \class ADBMetatypes
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 17:51:40
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "adbmetatypes.h"

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

ADBMetatypes::ADBMetatypes(QObject* parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

ADBMetatypes::~ADBMetatypes(void) {}


// -----------
/*!
	\fn

	Doc.
*/

void ADBMetatypes::mInit(void) {

	qRegisterMetaType<ARB::AEnumsDBFieldType::Type>("ARB::AEnumsDBFieldType::Type");

#if !defined(A_CONSOLE_APPLICATION)
	qmlRegisterType<ARB::AEnumsDBFieldType>("Arboreus", 1, 0, "AEnumsDBFieldType");
#endif
}
