// ----------------------------------------------------------
/*!
    \class ADataMetatypes
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 16/06/2023 at 19:25:03
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "adatametatypes.h"

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

ADataMetatypes::ADataMetatypes(QObject* parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

ADataMetatypes::~ADataMetatypes(void) {}


// -----------
/*!
	\fn

	Doc.
*/

void ADataMetatypes::mInit(void) {

	qmlRegisterType<ARB::AEnumsDataReplyType>("Arboreus", 1, 0, "AEnumsDataReplyType");
	qRegisterMetaType<ARB::AEnumsDataReplyType::ReplyType>("ARB::AEnumsDataReplyType::ReplyType");

	qmlRegisterType<ARB::AEnumsDataType>("Arboreus", 1, 0, "AEnumsDataType");
	qRegisterMetaType<ARB::AEnumsDataType::DataType>("ARB::AEnumsDataType::DataType");
}

