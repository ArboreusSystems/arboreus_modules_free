// ----------------------------------------------------------
/*!
    \class AUniversalMetatypes
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 19:11:32
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "auniversalmetatypes.h"

// Namespace
using namespace ARB;

// -----------
/*!
    \fn

    Doc.
*/

AUniversalMetatypes::AUniversalMetatypes(QObject* parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

AUniversalMetatypes::~AUniversalMetatypes(void) {}


// -----------
/*!
	\fn

	Doc.
*/

void AUniversalMetatypes::mInit(void) {

	qmlRegisterType<ARB::AEnumsDictionaryType>("Arboreus", 1, 0, "AEnumsDictionaryType");
	qRegisterMetaType<ARB::AEnumsDictionaryType::DictionaryType>("ARB::AEnumsDictionaryType::DictionaryType");
}
