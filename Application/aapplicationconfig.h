// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 03/03/2022 at 18:43:42
	\endlist
*/
// ----------------------------------------------------------
#ifndef AAPPLICATIONCONFIG_H
#define AAPPLICATIONCONFIG_H

// System includes

// Precompiled includes
#include <aapplicationpch.h>

// Application includes
#include <aapplicationdatamodels.h>
#include <aapplicationglobalconfig.h>

// Constants and defintions


// Namespace
namespace ARB {

// Classes
class ABackend;

// Interface
class AApplicationConfig {

	public:


		// ------------------------
		// Application

		virtual QThread::Priority AApplicationConfig_Application_ThreadPriority(void) = 0;


		// ------------------------
		// Registry

		virtual QString AApplicationConfig_Registry_Value(void) = 0;
		virtual QString AApplicationConfig_Registry_Salt(void) = 0;


		// ------------------------
		// Lifecycle

		virtual void AApplicationConfig_Lifecycle_WillLaunchUI(ABackend* inBackend) = 0;


		// ------------------------
		// Delegate

#if defined(Q_OS_IOS)
		virtual void AApplicationConfig_Delegate_DidBecomeActive(void) = 0;
		virtual void AApplicationConfig_Delegate_WillResignActive(void) = 0;
		virtual void AApplicationConfig_Delegate_DidReceiveMemoryWarning(void) = 0;
		virtual void AApplicationConfig_Delegate_WillTerminate(void) = 0;
		virtual void AApplicationConfig_Delegate_SignificantTimeChange(void) = 0;
		virtual void AApplicationConfig_Delegate_DidRegisterForRemoteNotificationsWithDeviceToken(QByteArray inToken) = 0;
		virtual void AApplicationConfig_Delegate_DidFailToRegisterForRemoteNotificationsWithError(void) = 0;
		virtual void AApplicationConfig_Delegate_DidUpdateUserActivity(void) = 0;
		virtual void AApplicationConfig_Delegate_DidEnterBackground(void) = 0;
		virtual void AApplicationConfig_Delegate_WillEnterForeground(void) = 0;
#endif


		// ------------------------
		// Heartbeat

		virtual void AApplicationConfig_Heartbeat_OnBeat(void) = 0;
		virtual int AApplicationConfig_Heartbeat_DefaultTime(void) = 0;
		virtual bool AApplicationConfig_Heartbeat_DefaultAutostart(void) = 0;
};

} // namespace ARB

Q_DECLARE_INTERFACE(ARB::AApplicationConfig,"Arboreus.AApplicationConfig/1.0")

#endif // AAPPLICATIONCONFIG_H
