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

	QObject::connect(
		pBackend->pScreen,&QScreen::orientationChanged,
		this,&ADevice::slOrientationChanged
	);

	this->mInitType();

	qmlRegisterType<ADeviceEnums>(pBackend->pConfigGlobal->mGetModuleName(),1,0,"ADeviceEnums");
	qRegisterMetaType<ADeviceEnums::StatusBarStyle>("ADeviceEnums::StatusBarStyle");
	qRegisterMetaType<ADeviceEnums::Type>("ADeviceEnums::Type");

	_A_DEBUG << "ADevice initiated";

	emit sgInitiated();
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


// -----------
/*!
	\fn

	Doc.
*/

void ADevice::mSetStatusBarStyle(ADeviceEnums::StatusBarStyle inStyle) {

#ifdef Q_OS_IOS
	ADeviceIOS::mSetStatusBarStyle(inStyle);
#elif defined(Q_OS_ANDROID)
	ADeviceAndroid::mSetStatusBarStyle(inStyle);
#else
	Q_UNUSED(inStyle);
#endif
}


// -----------
/*!
	\fn

	Doc.
*/

ADeviceEnums::StatusBarStyle ADevice::mGetStatusBarStyle(void) {

	ADeviceEnums::StatusBarStyle oOutput = ADeviceEnums::StatusBarStyle::Default;

#ifdef Q_OS_IOS
	oOutput = ADeviceIOS::mGetStatusBarStyle();
#elif defined(Q_OS_ANDROID)
	oOutput = ADeviceAndroid::mGetStatusBarStyle();
#else

#endif

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADeviceEnums::Type ADevice::mType(void) {

	return pType;
}


// -----------
/*!
	\fn

	Doc.
*/

bool ADevice::mIsLandscape(void) {

	return pBackend->pScreen->isLandscape(
		pBackend->pScreen->orientation()
	);
}


// -----------
/*!
	\fn

	Doc.
*/

void ADevice::mInitType(void) {

#ifdef Q_OS_IOS
	pType = ADeviceIOS::mType();
#elif defined(Q_OS_ANDROID)
	pType = ADeviceAndroid::mType();
#else

#endif
}


// -----------
/*!
	\fn

	Doc.
*/

void ADevice::slOrientationChanged(Qt::ScreenOrientation inOrientation) {

	emit sgOrientationChanged(inOrientation);
}



