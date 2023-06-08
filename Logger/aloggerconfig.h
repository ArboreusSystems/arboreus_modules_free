// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 02/08/2022 at 20:06:59
	\endlist
*/
// ----------------------------------------------------------
#ifndef ALOGGERCONFIG_H
#define ALOGGERCONFIG_H

// System includes

// Precompiled includes
#include <aloggerpch.h>

// Application includes
#include <aloggerdatamodels.h>

// Constants and defintions

// Namespace
namespace ARB {

// Interface
class ALoggerConfig {

	public:

		virtual QThread::Priority ALoggerConfig_ThreadPriority(void) = 0;
		virtual bool ALoggerConfig_Encrypted(void) = 0;
		virtual bool ALoggerConfig_LogBookInDocuments(void) = 0;
		virtual _A_ENUMS_LOGGER_LOGBOOK_TYPE ALoggerConfig_LogbookType(void) = 0;
};

} // namespace ARB

Q_DECLARE_INTERFACE(ARB::ALoggerConfig,"Arboreus.ALoggerConfig/1.0")

#endif // ALOGGERCONFIG_H
