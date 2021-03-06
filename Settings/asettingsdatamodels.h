// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 02/05/2021 at 12:26:44
	\endlist
*/
// ----------------------------------------------------------
#ifndef ASETTINGSDATAMODELS_H
#define ASETTINGSDATAMODELS_H

// System includes

// Precompiled includes
#include <asettingspch.h>

// Application includes

// Constants and defintions

// Namespace
namespace ARB {

class ASettingsProperties {

	public:

		QString Path = "NoDefinedPath";
		QObject* Config = nullptr;

		ASettingsProperties(void) {}
		~ASettingsProperties(void) {}
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::ASettingsProperties)

namespace ARB {

class ASettingsReply {

	public:

		bool Status = false;
		QVariant Data = 0;

		ASettingsReply(void) {}
		~ASettingsReply(void) {}

		QVariantMap mToVariantMap(void) {

			QVariantMap oOutput;
			oOutput.insert("Status",Status);
			oOutput.insert("Data",Data);
			return oOutput;
		}
};

} // namespace ARB

#endif // ASETTINGSDATAMODELS_H
