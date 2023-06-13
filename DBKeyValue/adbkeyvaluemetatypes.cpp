// ----------------------------------------------------------
/*!
    \class ADBKeyValueMetatypes
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 18:06:33
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "adbkeyvaluemetatypes.h"

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

ADBKeyValueMetatypes::ADBKeyValueMetatypes(QObject* parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

ADBKeyValueMetatypes::~ADBKeyValueMetatypes(void) {}


// -----------
/*!
	\fn

	Doc.
*/

void ADBKeyValueMetatypes::mInit(void) {

	qmlRegisterType<ARB::AEnumsDBKeyValueReplyStatus>("Arboreus", 1, 0, "AEnumsDBKeyValueReplyStatus");
	qRegisterMetaType<ARB::AEnumsDBKeyValueReplyStatus::ReplyStatus>("ARB::AEnumsDBKeyValueReplyStatus::ReplyStatus");
}

