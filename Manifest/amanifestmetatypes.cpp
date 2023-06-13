// ----------------------------------------------------------
/*!
    \class AManifestMetatypes
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 18:21:35
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "amanifestmetatypes.h"

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

AManifestMetatypes::AManifestMetatypes(QObject *parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

AManifestMetatypes::~AManifestMetatypes(void) {}


// -----------
/*!
	\fn

	Doc.
*/

void AManifestMetatypes::mInit(void) {

	qmlRegisterType<ARB::AEnumsManifestDataType>("Arboreus", 1, 0, "AEnumsManifestDataType");
	qRegisterMetaType<ARB::AEnumsManifestDataType::DataType>("ARB::AEnumsManifestDataType::DataType");

	qmlRegisterType<ARB::AEnumsManifestReplyStatus>("Arboreus", 1, 0, "AEnumsManifestReplyStatus");
	qRegisterMetaType<ARB::AEnumsManifestReplyStatus::ReplyStatus>("ARB::AEnumsManifestReplyStatus::ReplyStatus");
}

