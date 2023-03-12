// ----------------------------------------------------------
/*!
	\class AUsersHandlerObjects
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 10/03/2023 at 16:03:57
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "ausershandlerobjects.h"

// Namespace definition
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandlerObjects::AUsersHandlerObjects(AUsersHandlerConfig* inConfig, QObject* parent) {

	if (inConfig) {
		pConfig = inConfig;
	} else {
		_A_WARNING << "No config when creating AUsersHandlerObjects";
	}

	_A_DEBUG << "AUsersHandlerObjects created";
}


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandlerObjects::AUsersHandlerObjects(QObject* parent) : QObject(parent) {

	_A_DEBUG << "AUsersHandlerObjects created without config";
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

QVariantMap AUsersHandlerObjects::mUserData(void) {

	return pConfig->AUsersHandlerConfig_DataModelObject();
}

