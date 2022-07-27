// ----------------------------------------------------------
/*!
	\headerfile AApplicationHeartbeat
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 27/07/2022 at 13:44:04
	\endlist
*/
// ----------------------------------------------------------

#ifndef AAPPLICATIONHEARTBEAT_H
#define AAPPLICATIONHEARTBEAT_H

// System includes
#include <aapplicationpch.h>

// Application includes
#include <alogger.h>
#include <aapplicationconfig.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AApplicationHeartbeat : public QObject {

	Q_OBJECT

	public:

		explicit AApplicationHeartbeat(AApplicationConfig* inConfig = nullptr,QObject* parent = nullptr);
		virtual ~AApplicationHeartbeat(void);

	public slots:

		void slInit(void);

		void mSetTime(int inTime);
		void mStart(void);
		void mStartWithTime(int inTime);
		void mStop(void);

	signals:

		void sgOnBeat(void);

	private:

		int pTime = 0;
		QTimer* pTimer = nullptr;
		AApplicationConfig* pConfig = nullptr;

	private slots:

		void slOnBeat(void);
};

} // namespace ARB

#endif // AAPPLICATIONHEARTBEAT_H
