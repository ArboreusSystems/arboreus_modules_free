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
#include <QObject>
#include <QDateTime>

// Application includes
#include <aloggerglobal.h>
#include <athreadservicetemplate.h>
#include <adbsqlcipher.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ALoggerService : public AThreadServiceTemplate {

	Q_OBJECT

	public:

		explicit ALoggerService(QObject* parent = nullptr);
		virtual ~ALoggerService(void);

	public slots:

		void slInit(QString inPathLoggerData);
		void slWriteToDB(ALoggerMessageModel* inMessageModel);

	signals:

		void sgInitiated(void);

	private:

		QString pPathLoggerData = QString("NoPathLoggerData");
		ADBSqlCipher* pDB = nullptr;
};

} // namespace ARB

#endif // ALOGGERSERVICE_H
