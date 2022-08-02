// ----------------------------------------------------------
/*!
	\headerfile ALoggerService
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 28/04/2021 at 19:52:08
	\endlist
*/
// ----------------------------------------------------------

#ifndef ALOGGERSERVICE_H
#define ALOGGERSERVICE_H

// System includes

// Precompiled includes
#include <aloggerpch.h>

// Application includes
#include <aloggerconfig.h>
#include <aloggerglobal.h>
#include <athreadservicetemplate.h>
#include <adbsqlitecipher.h>

// Constants and definitions

// Global variables

// Namespace
namespace ARB {

// Class definitions
class ALoggerService : public AThreadServiceTemplate {

	Q_OBJECT

	public:

		explicit ALoggerService(QObject* parent = nullptr);
		virtual ~ALoggerService(void);

	public slots:

		void slInit(QString inPathLoggerData,QObject* inConfigObject);
		void slWriteToLogbook(ARB::ALoggerMessageModel* inMessageModel);

	signals:

		void sgInitiated(void);

	private:

		QString pPathLoggerData = QString("NoPathLoggerData");
		ADBSqliteCipher* pDB = nullptr;
		ALoggerConfig* pConfig = nullptr;

		void mInitMessageCache(void);
};

} // namespace ARB

#endif // ALOGGERSERVICE_H
