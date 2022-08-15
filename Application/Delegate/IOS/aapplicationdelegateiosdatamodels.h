// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 15/08/2022 at 09:12:41
	\endlist
*/
// ----------------------------------------------------------
#ifndef AAPPLICATIONDELEGATEIOSDATAMODELS_H
#define AAPPLICATIONDELEGATEIOSDATAMODELS_H

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

} // namespace ARB

#endif // AAPPLICATIONDELEGATEIOSDATAMODELS_H
