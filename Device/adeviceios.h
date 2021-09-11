// ----------------------------------------------------------
/*!
	\headerfile ADeviceIOS
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 07/05/2021 at 18:59:23
	\endlist
*/
// ----------------------------------------------------------

#ifndef ADEVICEIOS_H
#define ADEVICEIOS_H

// System includes

// Precompiled includes
#include <adevicepch.h>

// Application includes
#include <adevicedatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADeviceIOS : public QObject {

	Q_OBJECT

	public:

		explicit ADeviceIOS(QObject* parent = nullptr);
		virtual ~ADeviceIOS(void);

		static ADeviceSafeAreaInsets mGetSafeAreaInsets(void);
		static void mSetStatusBarStyle(ADeviceEnums::StatusBarStyle inStyle);
		static ADeviceEnums::StatusBarStyle mGetStatusBarStyle(void);
		static ADeviceEnums::Type mType(void);
};

} // namespace ARB

#endif // ADEVICEIOS_H
