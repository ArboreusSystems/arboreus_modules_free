// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 18/05/2021 at 22:14:35
	\endlist
*/
// ----------------------------------------------------------
#ifndef APROPERTIESCONFIG_H
#define APROPERTIESCONFIG_H

// System includes

// Precompiled includes
#include <apropertiespch.h>

// Application includes

// Constants and defintions

// Namespace
namespace ARB {

class APropertiesConfig {

	public:

		virtual QString APropertiesConfig_NameOrganisation(void) = 0;
		virtual QString APropertiesConfig_NameDomain(void) = 0;
		virtual QString APropertiesConfig_NameApplication(void) = 0;
};

} // namespace ARB

Q_DECLARE_INTERFACE(ARB::APropertiesConfig,"Arboreus.APropertiesConfig/1.0")

#endif // APROPERTIESCONFIG_H
