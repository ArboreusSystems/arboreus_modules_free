// ----------------------------------------------------------
/*!
	\class ADeviceIOS
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 07/05/2021 at 18:59:23
	\endlist
*/
// ----------------------------------------------------------

// System includes
#include <QObject>

// Application includes
#include <adevicedatamodels.h>

// Constants and definitions

// Apple includes
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

// -----------
// IOS part
// -----------

@interface ADeviceIOSNative: NSObject


@end


// -----------
// Qt part
// -----------

QT_BEGIN_NAMESPACE

// Application includes
#include <adeviceios.h>


// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ADeviceIOS::ADeviceIOS(QObject* parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

ADeviceIOS::~ADeviceIOS(void) {}


// -----------
/*!
	\fn

	Doc.
*/

ADeviceSafeAreaInsets ADeviceIOS::mGetSafeAreaInsets(void) {

	ADeviceSafeAreaInsets oOutput;

	if (@available(iOS 11.0, *)) {

		UIWindow* oWindow = nullptr;
		NSArray* oWindows = [[UIApplication sharedApplication] windows];
		for (UIWindow* iWindow in oWindows) {
			if (iWindow.isKeyWindow) {
				oWindow = iWindow;
				break;
			}
		}

		oOutput.Top = (int)roundf(oWindow.safeAreaInsets.top);
		oOutput.Bottom = (int)roundf(oWindow.safeAreaInsets.bottom);
		oOutput.Left = (int)roundf(oWindow.safeAreaInsets.left);
		oOutput.Right = (int)roundf(oWindow.safeAreaInsets.right);
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

void ADeviceIOS::mSetStatusBarStyle(ADeviceEnums::StatusBarStyle inStyle) {

	switch (inStyle) {
		case ADeviceEnums::StatusBarStyle::Dark:
			if (@available(iOS 13, *)) {
				[UIApplication sharedApplication].statusBarStyle = UIStatusBarStyleDarkContent;
			} else {
				[UIApplication sharedApplication].statusBarStyle = UIStatusBarStyleDefault;
			}
			break;
		case ADeviceEnums::StatusBarStyle::Light:
			[UIApplication sharedApplication].statusBarStyle = UIStatusBarStyleLightContent;
			break;
		default:
			[UIApplication sharedApplication].statusBarStyle = UIStatusBarStyleDefault;
			break;
	}
}


// -----------
/*!
	\fn

	Doc.
*/

ADeviceEnums::StatusBarStyle ADeviceIOS::mGetStatusBarStyle(void) {

	ADeviceEnums::StatusBarStyle oOutput = ADeviceEnums::StatusBarStyle::Default;

	UIWindow* oWindow = nullptr;
	NSArray* oWindows = [[UIApplication sharedApplication] windows];
	for (UIWindow* iWindow in oWindows) {
		if (iWindow.isKeyWindow) {
			oWindow = iWindow;
			break;
		}
	}

	switch (oWindow.windowScene.statusBarManager.statusBarStyle) {
		case UIStatusBarStyleDarkContent:
			oOutput = ADeviceEnums::StatusBarStyle::Dark; break;
		case UIStatusBarStyleLightContent:
			oOutput = ADeviceEnums::StatusBarStyle::Light; break;
		default: break;
	}

	return oOutput;
}

QT_END_NAMESPACE
