// ----------------------------------------------------------
/*!
	\headerfile ASettings
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 02/05/2021 at 11:36:16
	\endlist
*/
// ----------------------------------------------------------

#ifndef ASETTINGS_H
#define ASETTINGS_H

// System includes

// Precompiled includes
#include <asettingspch.h>

// Application includes
#include <athreadtemplate.h>
#include <asettingsservice.h>
#include <asettingsagent.h>
#include <athreadobjectcontrollertemplate.h>

// Constants and definitions
#define A_SETTING_VALUE_NO_KEY "NoKey"

// Namespace
namespace ARB {

// Classes
class ABackend;

// Class definitions
class ASettings : public AThreadTemplate<ASettingsService> {

	Q_OBJECT

	public:

		explicit ASettings(QObject* parent = nullptr);
		virtual ~ASettings(void);
		Q_DISABLE_COPY(ASettings)

		void mInit(void);
		ASettingsReply mGet(QString inKey);
		void mUpdate(QString inKey, QVariant inValue);

	signals:

		void sgInit(QString inPathSettingsData);
		void sgInitiated(void);
		void sgGetFromDB(QString inKey);
		void sgUpdated(QString inKey,QVariant inValue);
		void sgUpdate(QString inKey,QVariant inValue);

	public slots:

		QVariantMap mGetByKey(QString inKey);
		void mUpdateByKey(QString inKey,QVariant inValue);
		bool mIsKey(QString inKey);

		void slInitiated(void);
		void slUpdated(QString inKey,QVariant inValue);

	private:

		ABackend* pBackend = nullptr;
		QVariantMap pCache = {};

		ASettingsReply mGetFromDB(QString inSettingsID);
};

} // namespace ARB

#endif // ASETTINGS_H
