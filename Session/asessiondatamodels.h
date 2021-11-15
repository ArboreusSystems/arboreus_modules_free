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
#ifndef ASESSIONDATAMODELS_H
#define ASESSIONDATAMODELS_H

// System includes

// Precompiled includes
#include <asessionpch.h>

// Application includes

// Constants and defintions

// Namespace
namespace ARB {

class ASessionReply {

	public:

		bool Status = false;
		QVariant Value;

		QVariantMap mToVariantMap(void) {

			QVariantMap oOutput = {};
			oOutput.insert("Status",Status);
			oOutput.insert("Value",Value);
			return oOutput;
		}
};

} // namespace ARB

#endif // ASESSIONDATAMODELS_H
