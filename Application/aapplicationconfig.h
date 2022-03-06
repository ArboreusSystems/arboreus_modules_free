// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 03/03/2022 at 18:43:42
	\endlist
*/
// ----------------------------------------------------------
#ifndef AAPPLICATIONCONFIG_H
#define AAPPLICATIONCONFIG_H

// System includes

// Precompiled includes
#include <aapplicationpch.h>

// Application includes

// Constants and defintions
#define _A_APPLICATION_EMPTY_REGISTRY QString("")

// Namespace
namespace ARB {

class AApplicationConfig {

	public:

		virtual void AApplicationConfig_Init(QString inInitPath) = 0;
		virtual QString AApplicationConfig_Value(void) = 0;
		virtual QString AApplicationConfig_Salt(void) = 0;
};

} // namespace ARB

Q_DECLARE_INTERFACE(ARB::AApplicationConfig,"Arboreus.AApplicationConfig/1.0")

#endif // AAPPLICATIONCONFIG_H
