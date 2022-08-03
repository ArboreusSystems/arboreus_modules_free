// ----------------------------------------------------------
/*!
	\headerfile ALoggerFileAgent
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 03/08/2022 at 14:59:47
	\endlist
*/
// ----------------------------------------------------------

#ifndef ALOGGERFILEAGENT_H
#define ALOGGERFILEAGENT_H

// System includes

// Precompiled includes
#include <aloggerpch.h>

// Application includes
#include <aloggerglobal.h>
#include <aloggeragentinterface.h>
#include <afile.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ALoggerFileAgent :
	public QObject,
	public ARB::ALoggerAgentInterface {

	Q_OBJECT
	Q_INTERFACES(
		ARB::ALoggerAgentInterface
	)

	public:

		explicit ALoggerFileAgent(QObject* parent = nullptr);
		virtual ~ALoggerFileAgent(void);

		void mInit(ALoggerServiceProperties inProperties);
		void mWriteToLogbook(ALoggerMessageModel inMessageModel);

	private:

		QString pPathLoggerData = QString("NoPathLoggerData");
		FILE* pFile = nullptr;
};

} // namespace ARB

#endif // ALOGGERFILEAGENT_H
