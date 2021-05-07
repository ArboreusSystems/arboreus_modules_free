// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 07/05/2021 at 19:04:38
	\endlist
*/
// ----------------------------------------------------------
#ifndef ADEVICEDATAMODELS_H
#define ADEVICEDATAMODELS_H

// System includes
#include <QVariantMap>

// Application includes

// Constants and defintions

// Namespace
namespace ARB {

class ADeviceSafeAreaInsets {

	public:

		int Top = 0;
		int Bottom = 0;
		int Left = 0;
		int Right = 0;

		ADeviceSafeAreaInsets(void) {}
		~ADeviceSafeAreaInsets(void) {}

		QVariantMap mToVariantMap(void) {

			QVariantMap oOutput = {};
			oOutput.insert("Top",Top);
			oOutput.insert("Bottom",Bottom);
			oOutput.insert("Left",Left);
			oOutput.insert("Right",Right);
			return oOutput;
		}
};

} // namespace ARB

#endif // ADEVICEDATAMODELS_H
