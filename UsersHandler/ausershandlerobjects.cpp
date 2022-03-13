// ----------------------------------------------------------
/*!
	\class AUsersHandlerObjects
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 13/03/2022 at 14:18:30
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "ausershandlerobjects.h"

// Forwarded classes
#include <abackend.h>

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandlerObjects::AUsersHandlerObjects(ABackend* inBackend, QObject* parent) : QObject(parent) {

	pConfig = qobject_cast<AUsersHandlerConfig*>(inBackend->pApplicationConfigObject);

	ASqlCreateTableProperties oProperties = pConfig->AUsersHandlerConfig_DBTableProperties();
	pUserProperties = oProperties.mSchemaToVariantMap();

	_A_DEBUG << "2222222222222222222" << pUserProperties;

	_A_DEBUG << "AUsersHandlerObjects created";
}


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandlerObjects::~AUsersHandlerObjects(void) {

	_A_DEBUG << "AUsersHandlerObjects deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap AUsersHandlerObjects::mUserPropeties(void) {

	_A_DEBUG << "333333333333333333" << pUserProperties;

	return pUserProperties;
}

