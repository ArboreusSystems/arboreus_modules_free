// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 18/03/2022 at 17:33:02
	\endlist
*/
// ----------------------------------------------------------
#ifndef ASETTINGSCONFIG_H
#define ASETTINGSCONFIG_H

// System includes

// Precompiled includes
#include <asettingspch.h>

// Application includes

// Constants and defintions

// Namespace
namespace ARB {

class ASettingsConfig {

	public:

		virtual bool ASettingsConfig_Encrypted(void) = 0;
		virtual QString ASettingsConfig_TableName(void) = 0;
		virtual QString ASettingsConfig_ModuleName(void) = 0;
};

} // namespace ARB

Q_DECLARE_INTERFACE(ARB::ASettingsConfig,"Arboreus.ASettingsConfig/1.0")

#endif // ASETTINGSCONFIG_H
