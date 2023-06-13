// ----------------------------------------------------------
/*!
    \class AUIHandlerMetatypes
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 19:03:48
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "auihandlermetatypes.h"

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

AUIHandlerMetatypes::AUIHandlerMetatypes(QObject* parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

AUIHandlerMetatypes::~AUIHandlerMetatypes(void) {}


// -----------
/*!
	\fn

	Doc.
*/

void AUIHandlerMetatypes::mInit(void) {

	qmlRegisterType<ARB::AEnumsUIHandlerReplyStatus>("Arboreus", 1, 0, "AEnumsUIHandlerReplyStatus");
	qRegisterMetaType<ARB::AEnumsUIHandlerReplyStatus::ReplyStatus>("ARB::AEnumsUIHandlerReplyStatus::ReplyStatus");
}

