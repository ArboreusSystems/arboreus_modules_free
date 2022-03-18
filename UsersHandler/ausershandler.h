// ----------------------------------------------------------
/*!
	\headerfile AUsers
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 27/02/2022 at 15:10:11
	\endlist
*/
// ----------------------------------------------------------

#ifndef AUSERSHANDLER_H
#define AUSERSHANDLER_H

// System includes

// Precompiled includes
#include <ausershandlerpch.h>

// Application includes
#include <athreadtemplate.h>
#include <athreadobjectcontrollertemplate.h>
#include <ausershandlerservice.h>
#include <ausershandlerdatamodels.h>
#include <ausershandlerconfig.h>
#include <ausershandlerobjects.h>
#include <ausersagentcreate.h>

// Constants and definitions

// Namespace
namespace ARB {

// Classes
class ABackend;

// Class definitions
class AUsersHandler : public AThreadTemplate<AUsersHandlerService> {

	Q_OBJECT

	public:

		AUsersHandlerConfig* pConfig = nullptr;
		AUsersHandlerObjects* pObjects = nullptr;

		explicit AUsersHandler(QObject* parent = nullptr);
		virtual ~AUsersHandler(void);
		Q_DISABLE_COPY(AUsersHandler)

		void mInit(void);
		QList<ADBFieldProperties> mDBSchema(void);
		QList<QVariantList> mAll(void);
		ADBSqliteReply mCreate(ASqlInsertIntoProperties inProperties);
		ADBSqliteReply mRead(QString inID);
		ADBSqliteReply mUpdate(ASqlInsertIntoProperties inProperties);
		ADBSqliteReply mDelete(QString inID);

	public slots:

		void slInitiated(void);
		QVariantList mGetDBSchema(void);
		QVariantList mGetAll(void);

	signals:

		void sgInit(AUsersHandlerProperties inProperties);
		void sgInitiated(void);

	private:

		ABackend* pBackend = nullptr;
		QList<ADBFieldProperties> pDBSchema = {};
};

} // namespace ARB

#endif // AUSERSHANDLER_H
