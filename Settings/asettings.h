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
#include <asettingsconfig.h>
#include <athreadobjectcontrollertemplate.h>
#include <asettingswriteagent.h>
#include <asettingsreadagent.h>

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

		ASettingsConfig* pConfig = nullptr;

		explicit ASettings(QObject* parent = nullptr);
		virtual ~ASettings(void);
		Q_DISABLE_COPY(ASettings)

		void mInit(void);
		ASettingsReply mReadHandler(QString inKey);
		ASettingsReply mWriteHandler(QString inKey, QVariant inValue);

	public slots:

		QVariantMap mRead(QString inKey);
		QVariantMap mWrite(QString inKey,QVariant inValue);
		bool mIsKey(QString inKey);

		void slInitiated(void);

	signals:

		void sgInit(ASettingsProperties inProperties);
		void sgInitiated(void);
		void sgDidWrite(QString inKey,QVariant inValue);

	private:

		ABackend* pBackend = nullptr;
		QVariantMap pCache = {};

		ASettingsReply mReadFromDB(QString inSettingsID);

	private slots:

		void slDidWrite(QString inKey,QVariant inValue);
};

} // namespace ARB

#endif // ASETTINGS_H
