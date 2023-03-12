// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 12/03/2023 at 14:10:04
	\endlist
*/
// ----------------------------------------------------------
#ifndef AUSERSHANDLERCONFIG_H
#define AUSERSHANDLERCONFIG_H

// System includes

// Precompiled includes
#include <ausershandlerpch.h>

// Application includes

// Constants and defintions

// Namespace
namespace ARB {

// Interface
class AUsersHandlerConfig {

	public:

		virtual QString AUsersHandlerConfig_ModuleName(void) = 0;
		virtual QVariantMap AUsersHandlerConfig_DataModel(void) = 0;
		virtual QVariantMap AUsersHandlerConfig_DataModelObject(void) = 0;
};

} // namespace ARB

Q_DECLARE_INTERFACE(ARB::AUsersHandlerConfig,"Arboreus.AUsersHandlerConfig/1.0")

#endif // AUSERSHANDLERCONFIG_H
