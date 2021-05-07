// ----------------------------------------------------------
/*!
	\class ADevice
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 07/05/2021 at 18:44:46
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "adevice.h"

// Forwarded classes
#include <abackend.h>

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ADevice::ADevice(QObject *parent) : QObject(parent) {

	_A_DEBUG << "ADevice created";
}


// -----------
/*!
	\fn

	Doc.
*/

ADevice::~ADevice(void) {

	_A_DEBUG << "ADevice deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void ADevice::mInit(void) {

	pBackend = &ABackend::mInstance();

	_A_DEBUG << "ADevice initiated";
}


// -----------
/*!
	\fn

	Doc.
*/

ADeviceSafeAreaInsets ADevice::mGetSafeAreaInsets(void) {

		ADeviceSafeAreaInsets oOutput;

	#ifdef Q_OS_IOS
		oOutput = ADeviceIOS::mGetSafeAreaInsets();
	#elif defined(Q_OS_ANDROID)
		oOutput = ADeviceAndroid::mGetSafeAreaInsets();
	#endif

		return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ADevice::mSafeAreaInsets(void) {

	return this->mGetSafeAreaInsets().mToVariantMap();
}



