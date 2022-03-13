// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 28/02/2022 at 16:37:02
	\endlist
*/
// ----------------------------------------------------------
#ifndef AUSERSHANDLERCONFIG_H
#define AUSERSHANDLERCONFIG_H

// System includes

// Precompiled includes
#include <ausershandlerpch.h>

// Application includes
#include <adbdatamodels.h>

// Constants and defintions

// Namespace
namespace ARB {

class AUsersHandlerConfig {

	public:

		virtual ASqlCreateTableProperties AUsersHandlerConfig_DBTableProperties(void) = 0;
		virtual QString AUsersHandlerConfig_DBTableName(void) = 0;
		virtual QString AUsersHandlerConfig_ModuleName(void) = 0;
};

} // namespace ARB

Q_DECLARE_INTERFACE(ARB::AUsersHandlerConfig,"Arboreus.AUsersHandlerConfig/1.0")

#endif // AUSERSHANDLERCONFIG_H
