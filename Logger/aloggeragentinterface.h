// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 03/08/2022 at 14:57:46
	\endlist
*/
// ----------------------------------------------------------
#ifndef ALOGGERAGENTINTERFACE_H
#define ALOGGERAGENTINTERFACE_H

// System includes

// Precompiled includes
#include <aloggerpch.h>

// Application includes
#include <aloggerdatamodels.h>

// Constants and defintions

// Namespace
namespace ARB {

// Interface
class ALoggerAgentInterface {

	public:

		virtual void mInit(ALoggerServiceProperties inProperties) = 0;
		virtual void mWriteToLogbook(ALoggerMessageModel inMessageModel) = 0;
};

} // namespace ARB

Q_DECLARE_INTERFACE(ARB::ALoggerAgentInterface,"Arboreus.ALoggerAgentInterface/1.0")

#endif // ALOGGERAGENTINTERFACE_H
