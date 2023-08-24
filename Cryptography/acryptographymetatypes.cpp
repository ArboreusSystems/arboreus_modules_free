// ----------------------------------------------------------
/*!
    \class ACryptographyMetatypes
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 17:38:33
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "acryptographymetatypes.h"

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

ACryptographyMetatypes::ACryptographyMetatypes(QObject *parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

ACryptographyMetatypes::~ACryptographyMetatypes(void) {}


// -----------
/*!
	\fn

	Doc.
*/

void ACryptographyMetatypes::mInit(void) {

	qRegisterMetaType<ARB::AEnumsCryptographyAESType::AESType>("ARB::AEnumsCryptographyAESType::AESType");
	qRegisterMetaType<ARB::AEnumsCryptographyAESMode::AESMode>("ARB::AEnumsCryptographyAESMode::AESMode");
	qRegisterMetaType<ARB::AEnumsCryptographyAESPadding::AESPadding>("ARB::AEnumsCryptographyAESPadding::AESPadding");

#if !defined(A_CONSOLE_APPLICATION)
	qmlRegisterType<ARB::AEnumsCryptographyAESType>("Arboreus", 1, 0, "AEnumsCryptographyAESType");
	qmlRegisterType<ARB::AEnumsCryptographyAESMode>("Arboreus", 1, 0, "AEnumsCryptographyAESMode");
	qmlRegisterType<ARB::AEnumsCryptographyAESPadding>("Arboreus", 1, 0, "AEnumsCryptographyAESPadding");
#endif
}
