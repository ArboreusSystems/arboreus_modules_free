// ----------------------------------------------------------
/*!
	\headerfile ADevice
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 07/05/2021 at 18:44:46
	\endlist
*/
// ----------------------------------------------------------

#ifndef ADEVICE_H
#define ADEVICE_H

// System includes

// Precompiled includes
#include <adevicepch.h>

// Application includes
#include <adevicedatamodels.h>

// iOS includes
#ifdef Q_OS_IOS
#include <adeviceios.h>
#endif

// Android includes
#ifdef Q_OS_ANDROID
#include <adeviceandroid.h>
#endif

// Constants and definitions

// Namespace
namespace ARB {

// Classes
class ABackend;

// Class definitions
class ADevice : public QObject {

	Q_OBJECT

	public:

		explicit ADevice(QObject *parent = nullptr);
		virtual ~ADevice(void);
		Q_DISABLE_COPY(ADevice)

		void mInit(void);
		ADeviceSafeAreaInsets mGetSafeAreaInsets(void);

	public slots:

		QVariantMap mSafeAreaInsets(void);
		void mSetStatusBarStyle(ADeviceEnums::StatusBarStyle inStyle);
		ADeviceEnums::StatusBarStyle mGetStatusBarStyle(void);
		ADeviceEnums::Type mType(void);
		bool mIsLandscape(void);

	signals:

		void sgInitiated(void);
		void sgOrientationChanged(Qt::ScreenOrientation inOrientation);

	private:

		ABackend* pBackend = nullptr;
		ADeviceEnums::Type pType = ADeviceEnums::Type::Undefined;

		void mInitType(void);

	private slots:

		void slOrientationChanged(Qt::ScreenOrientation inOrientation);
};

} // namespace ARB

#endif // ADEVICE_H
