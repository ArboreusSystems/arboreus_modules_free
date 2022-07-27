// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 26/07/2022 at 11:11:26
	\endlist
*/
// ----------------------------------------------------------
#ifndef AAPPLICATIONDELEGATEGLOBALCONFIG_H
#define AAPPLICATIONDELEGATEGLOBALCONFIG_H

// System includes

// Application includes
#include <aapplicationdatamodels.h>

// Constants and defintions

// Namespace
namespace ARB {

// Global functions
void fAApplicationConfig_Delegate_WillFinishLaunchingWithOptions(_A_ENUM_APPLICATION_IOS_LAUNCH_OPTION inOption);
void fAApplicationConfig_Delegate_DidFinishLaunchingWithOptions(_A_ENUM_APPLICATION_IOS_LAUNCH_OPTION inOption);

} // namespace ARB

#endif // AAPPLICATIONDELEGATEGLOBALCONFIG_H
