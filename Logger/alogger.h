// ----------------------------------------------------------
/*!
	\headerfile ALogger
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 28/04/2021 at 19:50:47
	\endlist
*/
// ----------------------------------------------------------

#ifndef ALOGGER_H
#define ALOGGER_H

// System includes
#include <QObject>

// Application includes
#include <athreadtemplate.h>
#include <aloggerservice.h>
#include <aloggerglobal.h>
#include <adir.h>

// Constants and definitions

// Namespace
namespace ARB {

// Classes
class ABackend;

// Class definitions
class ALogger : public AThreadTemplate<ALoggerService> {

	Q_OBJECT

	public:

		explicit ALogger(QObject* parent = nullptr);
		virtual ~ALogger(void);
		Q_DISABLE_COPY(ALogger)

		void mInit(void);
		void mWriteToDB(ALoggerMessageModel* inMessageModel);

	signals:

		void sgInit(QString inPathLoggerData);
		void sgInitiated(void);
		void sgWriteToDB(ALoggerMessageModel* inMessageModel);

	public slots:

		void slInitiated(void);

	private:

		ABackend* pBackend = nullptr;
};

} // namespace ARB

#endif // ALOGGER_H
