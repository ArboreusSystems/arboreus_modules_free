// ----------------------------------------------------------
/*!
	\headerfile AProperties
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 28/02/2021 at 15:01:40
	\endlist
*/
// ----------------------------------------------------------

#ifndef APROPERTIES_H
#define APROPERTIES_H

// System includes
#include <QObject>
#include <QString>
#include <QStandardPaths>

// Application includes
#include <adir.h>
#include <aloggerglobal.h>

// Constants and definitions

// Namespace
namespace ARB {

// Classes
class ABackend;

// Class definitions
class AProperties : public QObject {

	Q_OBJECT

	public:

		explicit AProperties(QObject *parent = nullptr);
		virtual ~AProperties(void);

		void mInit(void);

		void mSetNameOrganisation(QString inName);
		QString mGetNameOrganisation(void);
		void mSetNameDomain(QString inName);
		QString mGetNameDomain(void);
		void mSetNameApplication(QString inName);
		QString mGetNameApplication(void);

		QString mGetPathDataApplication(void);
		QString mGetPathDataConfig(void);
		QString mGetPathDataCache(void);

	signals:

		void sgInitiated(void);

	private:

		ABackend* pBackend = nullptr;

		QString pNameOrganisation = "NoNameOrganisation";
		QString pNameDomain = "NoNameDomain";
		QString pNameApplication = "NoNameApplication";

		QString pPathDataApplication = "NoPathDataApplication";
		QString pPathDataConfig = "NoPathDataConfig";
		QString pPathDataCache = "NoPathDataCache";

		QString pPathLogs = "NoPathLogs";

		void mInitPaths(void);
};

} // namespace ARB

#endif // APROPERTIES_H
