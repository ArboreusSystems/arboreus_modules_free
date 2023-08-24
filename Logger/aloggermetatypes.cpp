// ----------------------------------------------------------
/*!
    \class ALoggerMetatypes
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 18:14:55
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "aloggermetatypes.h"

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

ALoggerMetatypes::ALoggerMetatypes(QObject* parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

ALoggerMetatypes::~ALoggerMetatypes(void) {}


// -----------
/*!
	\fn

	Doc.
*/

void ALoggerMetatypes::mInit(void) {

	qRegisterMetaType<ARB::AEnumsLoggerLogbookType::Type>("ARB::AEnumsLoggerLogbookType::Type");

#if !defined(A_CONSOLE_APPLICATION)
	qmlRegisterType<ARB::AEnumsLoggerLogbookType>("Arboreus", 1, 0, "AEnumsLoggerLogbookType");
#endif
}
