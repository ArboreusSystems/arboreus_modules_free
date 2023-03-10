// ----------------------------------------------------------
/*!
	\class AUsersHandlerUserData
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 10/03/2023 at 13:53:45
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "ausershandleruserdata.h"

// Namespace definition
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandlerUserData::AUsersHandlerUserData(QVariantMap inData) : QVariantMap() {

	if (inData.contains(_A_USER_DATA_NAME_ID)) {
		this->mLoadData(inData);
		_A_DEBUG << "AUserData created for ID:" << this->mGetID();
	} else {
		_A_CRITICAL << "AUserData not created properly, no required ID";
	}
}


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandlerUserData::AUsersHandlerUserData(void) : QVariantMap() {

	_A_DEBUG << "AUserData created without data";
}


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandlerUserData::~AUsersHandlerUserData(void) {

	_A_DEBUG << "AUserData deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

QString AUsersHandlerUserData::mGetID(void) {

	QString oOutput = qvariant_cast<QString>(
		this->value(_A_USER_DATA_NAME_ID,_A_USER_DATA_NO_KEY)
	);
	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

QString AUsersHandlerUserData::mGetValueAddon(void) {

	QString oOutput = qvariant_cast<QString>(
		this->value(_A_USER_DATA_NAME_VALUE_ADDON,_A_USER_DATA_NO_KEY)
	);
	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersHandlerUserData::mLoadData(QVariantMap inData) {

	for (auto i = inData.constBegin(); i != inData.constEnd(); ++i) {
		this->insert(i.key(),i.value());
	}
}

