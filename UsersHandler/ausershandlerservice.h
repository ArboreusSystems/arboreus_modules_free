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

#ifndef AUSERSHANDLERSERVICE_H
#define AUSERSHANDLERSERVICE_H

// System includes

// Precompiled includes
#include <ausershandlerpch.h>

// Application includes
#include <athreadservicetemplate.h>
#include <ausershandlerdatamodels.h>
#include <ausershandlerconfig.h>
#include <aloggerglobal.h>
#include <adbsqlitecipher.h>
#include <adbsqlgenerator.h>
#include <adir.h>
#include <aapplicationconfig.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AUsersHandlerService : public AThreadServiceTemplate {

	Q_OBJECT

	public:

		explicit AUsersHandlerService(QObject* parent = nullptr);
		virtual ~AUsersHandlerService(void);

	public slots:

		void slInitHandlerService(ARB::AUsersHandlerProperties inProperties);

	signals:

		void sgInitiatedHandlerService(void);

	private:

		ADBSqliteCipher* pDB = nullptr;
		AUsersHandlerConfig* pUsersHandlerConfig = nullptr;
		AApplicationConfig* pApplicationConfig = nullptr;
		QString pPathData = "NoDefinedPathData";
		QString pPathCache = "NoDefinedPathCache";

		void mInitDB(QString inDBName,ASqlCreateTableProperties inTableProperties);
};

} // namespace ARB

#endif // AUSERSHANDLERSERVICE_H
