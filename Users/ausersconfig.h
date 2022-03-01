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
#ifndef AUSERSCONFIG_H
#define AUSERSCONFIG_H

// System includes

// Precompiled includes
#include <auserspch.h>

// Application includes
#include <adbdatamodels.h>

// Constants and defintions

// Namespace
namespace ARB {

class AUsersConfig {

	public:

		virtual ADBTableProperties AUsersConfig_DBTableProperties(void) = 0;
};

} // namespace ARB

Q_DECLARE_INTERFACE(ARB::AUsersConfig,"Arboreus.AUsersConfig/1.0")

#endif // AUSERSCONFIG_H
