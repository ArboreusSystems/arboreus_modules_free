// ----------------------------------------------------------
/*!
	\class AApplicationIOSNativedelegate
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 26/07/2022 at 09:30:56
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "aapplicationdelegateiosnative.h"

// Namespaces
using namespace ARB;
using namespace KRN;

// Class global properties
static ABackend* gBackend = nullptr;

// Constants and definitons
#define _A_APPLICATION_DELEGATE_IOS_NATIVE_CONFIG qobject_cast<AApplicationConfig*>(gBackend->pGlobalConfigObject)

// Class interface
@interface QIOSApplicationDelegate (AApplicationDelegateIOSNative)

@end


// Class definition
@implementation QIOSApplicationDelegate (AApplicationDelegateIOSNative)

// ----------------------------------
#pragma mark UIApplicationDelegate


-(BOOL) application:(UIApplication *)application willFinishLaunchingWithOptions:(NSDictionary<UIApplicationLaunchOptionsKey,id> *)launchOptions {

	#pragma unused(application)
	#pragma unused(launchOptions)
	
	gBackend = &ABackend::mInstance();
	if (gBackend) {
		_A_CONSOLE_DEBUG("ABackend assigned to global variable");
	} else {
		_A_CONSOLE_DEBUG("ABackend NOT assigned to global variable");
	}
	
	fAApplicationConfig_WillFinishLaunchingWithOptions(_A_ENUM_APPLICATION_IOS_LAUNCH_OPTION::Undefined);

	return YES;
}

-(BOOL) application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

	#pragma unused(application)
	#pragma unused(launchOptions)

	fAApplicationConfig_DidFinishLaunchingWithOptions(_A_ENUM_APPLICATION_IOS_LAUNCH_OPTION::Undefined);

	return YES;
}

-(void) applicationDidBecomeActive:(UIApplication*) application {

	#pragma unused(application)

	_A_APPLICATION_DELEGATE_IOS_NATIVE_CONFIG->AApplicationConfig_DidBecomeActive();
}

-(void) applicationWillResignActive:(UIApplication*) application {

	#pragma unused(application)

	_A_APPLICATION_DELEGATE_IOS_NATIVE_CONFIG->AApplicationConfig_WillResignActive();
}

//-(BOOL) application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {

//	_A_DEBUG << "IOS NATIVE DELEGATE" << "openURL";

//	return YES;
//}

-(void) applicationDidReceiveMemoryWarning:(UIApplication*)application {

	#pragma unused(application)

	_A_APPLICATION_DELEGATE_IOS_NATIVE_CONFIG->AApplicationConfig_DidReceiveMemoryWarning();
}

-(void) applicationWillTerminate:(UIApplication*)application {

	#pragma unused(application)

	_A_APPLICATION_DELEGATE_IOS_NATIVE_CONFIG->AApplicationConfig_WillTerminate();
}

-(void) applicationSignificantTimeChange:(UIApplication*)application {

	#pragma unused(application)

	_A_APPLICATION_DELEGATE_IOS_NATIVE_CONFIG->AApplicationConfig_SignificantTimeChange();
}

-(void) application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken {

	#pragma unused(application)

	QByteArray oData = QByteArray::fromNSData(deviceToken);
	_A_APPLICATION_DELEGATE_IOS_NATIVE_CONFIG->AApplicationConfig_DidRegisterForRemoteNotificationsWithDeviceToken(oData);
}

-(void) application:(UIApplication*)application didFailToRegisterForRemoteNotificationsWithError:(NSError*)error {

	#pragma unused(application)
	#pragma unused(error)

	_A_APPLICATION_DELEGATE_IOS_NATIVE_CONFIG->AApplicationConfig_DidFailToRegisterForRemoteNotificationsWithError();
}

//-(void) application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
//
//	NSLog(@"didReceiveRemoteNotification");
//}

-(void) application:(UIApplication*)application didUpdateUserActivity:(NSUserActivity*)userActivity {

	#pragma unused(application)
	#pragma unused(userActivity)

	_A_APPLICATION_DELEGATE_IOS_NATIVE_CONFIG->AApplicationConfig_DidUpdateUserActivity();
}

-(void) applicationDidEnterBackground:(UIApplication*)application {

	#pragma unused(application)

	_A_APPLICATION_DELEGATE_IOS_NATIVE_CONFIG->AApplicationConfig_DidEnterBackground();
}

-(void) applicationWillEnterForeground:(UIApplication*)application {

	#pragma unused(application)

	_A_APPLICATION_DELEGATE_IOS_NATIVE_CONFIG->AApplicationConfig_WillEnterForeground();
}

@end
