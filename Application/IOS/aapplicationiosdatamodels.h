// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 26/07/2022 at 09:51:23
	\endlist
*/
// ----------------------------------------------------------
#ifndef AAPPLICATIONIOSDATAMODELS_H
#define AAPPLICATIONIOSDATAMODELS_H

// System includes

// Precompiled includes
#include <aapplicationpch.h>

// Application includes

// Constants and defintions
#define _A_ENUM_APPLICATION_IOS_LAUNCH_OPTION ARB::AEnumsApplicationIOSLaunchOption::Option

// Namespace
namespace ARB {

class AEnumsApplicationIOSLaunchOption: public QObject {

	Q_OBJECT

	public:

		enum class Option: int {

			Undefined,
			BluetoothCentrals,
			BluetoothPeripherals,
			CloudKitShareMetadata,
			LocationKey,
			NewsstandDownloads,
			RemoteNotification,
			ShortcutItemKey,
			SourceApplication,
			OptionsURL,
			UserActivityDictionary,
			UserActivityType
		};
		Q_ENUM(Option)
};

//class AEnumAppllicationIOSLaunchOption : public QObject {

//	Q_OBJECT

//	public:

//		enum class Option: int {

//			Undefined,
//			BluetoothCentrals,
//			BluetoothPeripherals,
//			CloudKitShareMetadata,
//			LocationKey,
//			NewsstandDownloads,
//			RemoteNotification,
//			ShortcutItemKey,
//			SourceApplication,
//			OptionsURL,
//			UserActivityDictionary,
//			UserActivityType
//		};
//		Q_ENUM(ARB::AEnumAppllicationIOSLaunchOption)
//};

} // namespace ARB

#endif // AAPPLICATIONIOSDATAMODELS_H
