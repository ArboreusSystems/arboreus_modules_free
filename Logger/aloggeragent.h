// ----------------------------------------------------------
/*!
	\headerfile ALoggerAgent
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 03/08/2022 at 15:08:45
	\endlist
*/
// ----------------------------------------------------------

#ifndef ALOGGERAGENT_H
#define ALOGGERAGENT_H

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
class ALoggerAgent :
	public QObject,
	public ARB::ALoggerAgentInterface {

	Q_OBJECT
	Q_INTERFACES(
		ARB::ALoggerAgentInterface
	)

	public:

		explicit ALoggerAgent(QObject* parent = nullptr);
		virtual ~ALoggerAgent(void);

		void mInit(ALoggerServiceProperties inProperties);
		void mWriteToLogbook(ALoggerMessageModel inMessageModel);
};

} // namespace ARB

#endif // ALOGGERAGENT_H
