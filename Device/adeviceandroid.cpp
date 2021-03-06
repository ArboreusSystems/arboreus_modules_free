// ----------------------------------------------------------
/*!
	\class ADeviceAndroid
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 07/05/2021 at 18:59:45
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "adeviceandroid.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ADeviceAndroid::ADeviceAndroid(QObject* parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

ADeviceAndroid::~ADeviceAndroid(void) {}


// -----------
/*!
	\fn

	Doc.
*/

ADeviceSafeAreaInsets ADeviceAndroid::mGetSafeAreaInsets(void) {

	ADeviceSafeAreaInsets oOutput;

	// TODO: Android ARBSTCL-191 Add SafeArea insets to Android version

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

void ADeviceAndroid::mSetStatusBarStyle(ADeviceEnums::StatusBarStyle inStyle) {

	Q_UNUSED(inStyle);

	// TODO: Android ARBSTCL-201 Add StatusBarStyle handling to Android version
}


// -----------
/*!
	\fn

	Doc.
*/

ADeviceEnums::StatusBarStyle ADeviceAndroid::mGetStatusBarStyle(void) {

	// TODO: Android ARBSTCL-201 Add StatusBarStyle handling to Android version

	return ADeviceEnums::StatusBarStyle::Default;
}


// -----------
/*!
	\fn

	Doc.
*/

ADeviceEnums::Type ADeviceAndroid::mType(void) {

	ADeviceEnums::Type oOutput = ADeviceEnums::Type::Undefined;

	// TODO: Android ARBSTCL-202 Add device type detection to Android version

	return oOutput;
}
