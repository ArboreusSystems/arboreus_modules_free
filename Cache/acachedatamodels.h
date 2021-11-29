// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 15/11/2021 at 18:47:48
	\endlist
*/
// ----------------------------------------------------------
#ifndef ACACHEDATAMODELS_H
#define ACACHEDATAMODELS_H

// System includes

// Precompiled includes
#include <acachepch.h>

// Application includes

// Constants and defintions

// Namespace
namespace ARB {

class ACacheReply {

	public:

		bool Status = false;
		QVariant Data;

		QVariantMap mToVariantMap(void) {

			QVariantMap oOutput = {};
			oOutput.insert("Status",Status);
			oOutput.insert("Data",Data);
			return oOutput;
		}
};

} // namespace ARB

#endif // ACACHEDATAMODELS_H
