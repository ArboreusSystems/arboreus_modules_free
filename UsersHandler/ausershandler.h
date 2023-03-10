// ----------------------------------------------------------
/*!
	\headerfile AUsersHandler
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 08/03/2023 at 09:25:18
	\endlist
*/
// ----------------------------------------------------------

#ifndef AUSERSHANDLER_H
#define AUSERSHANDLER_H

// System includes

// Precompiled includes
#include <ausershandlerpch.h>

// Application includes
#include <aloggerglobal.h>
#include <athreadtemplate.h>
#include <ausershandlerservice.h>
#include <ausershandleruserdata.h>
#include <ausershandlerobjects.h>

// Constants and definitions

// Namespace
namespace ARB {

// Classes
class ABackend;

// Class definitions
class AUsersHandler : public AThreadTemplate<AUsersHandlerService> {

	Q_OBJECT

	public:

		AUsersHandlerObjects* pObjects = nullptr;

		explicit AUsersHandler(QObject* parent = nullptr);
		virtual ~AUsersHandler(void);
		Q_DISABLE_COPY(AUsersHandler)

		virtual void mInit(void);

	public slots:

		void slInitiated(void);
		void mSetCurrent(QString inID);

	signals:

		void sgInit(void);
		void sgInitiated(void);
		void sgDidSetCurrent(void);

	private:

		ABackend* pBackend = nullptr;
		AUsersHandlerUserData* pCurrent = nullptr;
};

} // namespace ARB

#endif // AUSERSHANDLER_H
