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
#ifndef AUSERSHANDLERDATAMODELS_H
#define AUSERSHANDLERDATAMODELS_H

// System includes

// Precompiled includes
#include <ausershandlerpch.h>

// Application includes
#include <adbdatamodels.h>
#include <ausershandlerconfig.h>

// Constants and defintions

// Namespace
namespace ARB {

class AUsersHandlerProperties {

	public:

		QString PathCache = "NoPathUsersCache";
		QString PathApplication = "NoPathUsersApplication";
		QObject* Config = nullptr;

		explicit AUsersHandlerProperties(void) {}
		virtual ~AUsersHandlerProperties(void) {}
};

} // namespace ARB

#endif // AUSERSHANDLERDATAMODELS_H
