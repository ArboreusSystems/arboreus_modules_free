// ----------------------------------------------------------
/*!
	\headerfile ALoggerDBAgent
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 03/08/2022 at 15:00:11
	\endlist
*/
// ----------------------------------------------------------

#ifndef ALOGGERDBAGENT_H
#define ALOGGERDBAGENT_H

// System includes

// Precompiled includes
#include <aloggerpch.h>

// Application includes
#include <aloggerglobal.h>
#include <aloggeragentinterface.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ALoggerDBAgent :
	public QObject,
	public ARB::ALoggerAgentInterface {

	Q_OBJECT
	Q_INTERFACES(
		ARB::ALoggerAgentInterface
	)

	public:

		explicit ALoggerDBAgent(QObject* parent = nullptr);
		virtual ~ALoggerDBAgent(void);

		void mInit(ALoggerServiceProperties inProperties);
		void mWriteToLogbook(ALoggerMessageModel inMessageModel);
};

} // namespace ARB

#endif // ALOGGERDBAGENT_H
