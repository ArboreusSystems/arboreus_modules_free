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

// Precompiled includes
#include <apropertiespch.h>

// Application includes
#include <apropertiesconfig.h>
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

		explicit AProperties(QObject* parent = nullptr);
		virtual ~AProperties(void);

		void mInit(void);

		QString mNameOrganisation(void);
		QString mNameDomain(void);
		QString mNameApplication(void);

		QString mGetPathDataApplication(void);
		QString mGetPathDataConfig(void);
		QString mGetPathDataCache(void);
		QString mGetPathDataDocuments(void);

	public slots:

		bool mIsDesktop(void);

	signals:

		void sgInitiated(void);

	private:

		ABackend* pBackend = nullptr;
		APropertiesConfig* pConfig = nullptr;
		bool pIsDesktop = false;

		QString pPathDataApplication = "NoPathDataApplication";
		QString pPathDataConfig = "NoPathDataConfig";
		QString pPathDataCache = "NoPathDataCache";
		QString pPathDataDocuments = "NoPathDataDocuments";

		QString pPathLogs = "NoPathLogs";

		void mInitPaths(void);
		void mInitIsDesktop(void);
};

} // namespace ARB

#endif // APROPERTIES_H
