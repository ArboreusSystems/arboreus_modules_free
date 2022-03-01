// ----------------------------------------------------------
/*!
	\headerfile SSettingsService
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 02/05/2021 at 11:50:09
	\endlist
*/
// ----------------------------------------------------------

#ifndef ASETTINGSSERVICE_H
#define ASETTINGSSERVICE_H

// System includes

// Precompiled includes
#include <asettingspch.h>

// Application includes
#include <athreadservicetemplate.h>
#include <aloggerglobal.h>
#include <asettingsdatamodels.h>
#include <adbsqlitecipher.h>

// Constants and definitions
#define _A_SETTINGS_DB_NAME "settings"

// Namespace
namespace ARB {

// Class definitions
class ASettingsService : public AThreadServiceTemplate {

	Q_OBJECT

	public:

		ADBSqliteCipher* pDB = nullptr;

		explicit ASettingsService(QObject* parent = nullptr);
		virtual ~ASettingsService(void);

		QString mGetDBName(void);

	public slots:

		void slInit(QString inPathSettingsData);
		void slUpdate(QString inKey,QVariant inValue);

	signals:

		void sgInitiated(void);
		void sgUpdated(QString inKey,QVariant inValue);
};

} // namespace ARB

#endif // ASETTINGSSERVICE_H
