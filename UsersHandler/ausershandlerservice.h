// ----------------------------------------------------------
/*!
	\headerfile AUsersHandlerService
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 08/03/2023 at 09:26:06
	\endlist
*/
// ----------------------------------------------------------

#ifndef AUSERSHANDLERSERVICE_H
#define AUSERSHANDLERSERVICE_H

// System includes

// Precompiled includes
#include <ausershandlerpch.h>

// Application includes
#include <aloggerglobal.h>
#include <athreadservicetemplate.h>
//#include <adbkeyvalue.h>

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

		void slInit(void);

	signals:

		void sgInitiated(void);

	private:

//		ADBKeyValue* pDB = nullptr;
};

} // namespace ARB

#endif // AUSERSHANDLERSERVICE_H
