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

class AApplicationConfig {

	public:

		virtual QString AApplicationConfig_Value(void) = 0;
		virtual QString AApplicationConfig_Salt(void) = 0;

#if defined(Q_OS_IOS)
		virtual void AApplicationConfig_DidBecomeActive(void) = 0;
		virtual void AApplicationConfig_WillResignActive(void) = 0;
		virtual void AApplicationConfig_DidReceiveMemoryWarning(void) = 0;
		virtual void AApplicationConfig_WillTerminate(void) = 0;
		virtual void AApplicationConfig_SignificantTimeChange(void) = 0;
		virtual void AApplicationConfig_DidRegisterForRemoteNotificationsWithDeviceToken(QByteArray inToken) = 0;
		virtual void AApplicationConfig_DidFailToRegisterForRemoteNotificationsWithError(void) = 0;
		virtual void AApplicationConfig_DidUpdateUserActivity(void) = 0;
		virtual void AApplicationConfig_DidEnterBackground(void) = 0;
		virtual void AApplicationConfig_WillEnterForeground(void) = 0;
#endif
};

} // namespace ARB

Q_DECLARE_INTERFACE(ARB::AApplicationConfig,"Arboreus.AApplicationConfig/1.0")

#endif // AAPPLICATIONCONFIG_H
