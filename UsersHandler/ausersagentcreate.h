// ----------------------------------------------------------
/*!
	\headerfile AUsersAgentCreate
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 18/03/2022 at 19:09:55
	\endlist
*/
// ----------------------------------------------------------

#ifndef AUSERSAGENTCREATE_H
#define AUSERSAGENTCREATE_H

// System includes

// Precompiled includes
#include <ausershandlerpch.h>

// Application includes
#include <athreadagenttemplate.h>
#include <athreadobjectcontrollertemplate.h>
#include <aloggerglobal.h>
#include <adbsqlitecipher.h>
#include <adbsqlgenerator.h>
#include <ausershandler.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AUsersAgentCreate : public AThreadAgentTemplate {

	Q_OBJECT

	public:

		ADBSqliteReply pReply;
		AUsersHandlerService* pService = nullptr;
		QString pTabeName = "NoTableName";
		QList<QVariantList> pData = {};

		explicit AUsersAgentCreate(QObject* parent = nullptr);
		virtual ~AUsersAgentCreate(void);

	public slots:

		void slRun(void);
};

} // namespace ARB

#endif // AUSERSAGENTCREATE_H
