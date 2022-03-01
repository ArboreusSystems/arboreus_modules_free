// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 27/02/2022 at 18:26:06
	\endlist
*/
// ----------------------------------------------------------
#ifndef AUSERSDATAMODELS_H
#define AUSERSDATAMODELS_H

// System includes

// Precompiled includes
#include <auserspch.h>

// Application includes
#include <adbdatamodels.h>

// Constants and defintions

// Namespace
namespace ARB {

class AUsersModuleProperties {

	public:

		QString PathCache = "NoPathUsersCache";
		QString PathApplication = "NoPathUsersApplication";
		ADBTableProperties DBTableProperties;

		explicit AUsersModuleProperties(void) {}
		virtual ~AUsersModuleProperties(void) {}
};

} // namespace ARB

#endif // AUSERSDATAMODELS_H
