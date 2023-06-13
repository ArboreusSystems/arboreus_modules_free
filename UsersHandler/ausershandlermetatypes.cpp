// ----------------------------------------------------------
/*!
    \class AUserHandlerMetatypes
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 17:17:58
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "ausershandlermetatypes.h"

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

AUsersHandlerMetatypes::AUsersHandlerMetatypes(QObject* parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandlerMetatypes::~AUsersHandlerMetatypes(void) {}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersHandlerMetatypes::mInit(void) {

	qmlRegisterType<ARB::AEnumsUsersHandlerReplyStatus>("Arboreus", 1, 0, "AEnumsUsersHandlerReplyStatus");
	qRegisterMetaType<ARB::AEnumsUsersHandlerReplyStatus::ReplyStatus>("ARB::AEnumsUsersHandlerReplyStatus::ReplyStatus");
}

