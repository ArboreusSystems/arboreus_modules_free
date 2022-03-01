// ----------------------------------------------------------
/*!
	\headerfile AUsersService
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 27/02/2022 at 15:17:17
	\endlist
*/
// ----------------------------------------------------------

#ifndef AUSERSSERVICE_H
#define AUSERSSERVICE_H

// System includes

// Precompiled includes
#include <auserspch.h>

// Application includes
#include <athreadservicetemplate.h>
#include <ausersdatamodels.h>
#include <aloggerglobal.h>
#include <adbsqlitecipher.h>
#include <adir.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AUsersService : public AThreadServiceTemplate {

	Q_OBJECT

	public:

		explicit AUsersService(QObject* parent = nullptr);
		virtual ~AUsersService(void);

	public slots:

		void slInit(AUsersModuleProperties inProperties);

	signals:

		void sgInitiated(void);

	private:

		ADBSqliteCipher* pDB = nullptr;
		QString pPathData = "NoDefinedPathData";
		QString pPathCache = "NoDefinedPathCache";

		void mInitDB(QString inDBName);
};

} // namespace ARB

#endif // AUSERSSERVICE_H
