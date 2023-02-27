// ----------------------------------------------------------
/*!
	\headerfile AUsersCreateAgent
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 19/08/2022 at 06:54:18
	\endlist
*/
// ----------------------------------------------------------

#ifndef AUSERSCREATEAGENT_H
#define AUSERSCREATEAGENT_H

// System includes
#include <QObject>

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
class AUsersCreateAgent : public AThreadAgentTemplate {

	Q_OBJECT

	public:

		ADBSqliteReply pReply;
		AUsersHandlerService* pService = nullptr;
		QString pTabeName = "NoTableName";
		QList<QVariantList> pData = {};

		explicit AUsersCreateAgent(QObject* parent = nullptr);
		virtual ~AUsersCreateAgent(void);

	public slots:

		void slRun(void);
};

} // namespace ARB

#endif // AUSERSCREATEAGENT_H
