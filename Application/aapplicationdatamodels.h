// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 23/07/2021 at 19:37:30
	\endlist
*/
// ----------------------------------------------------------
#ifndef AAPPLICATIONDATAMODELS_H
#define AAPPLICATIONDATAMODELS_H

// System includes
#include <QObject>

// Application includes

// Constants and defintions

// Namespace
namespace ARB {

class AEnums: public QObject {

	Q_OBJECT

	public:

		enum class Status: int {

			Error, Ok, Existed, NotExisted,
			WrongProperties, WrongValue,
			NoField
		};
		Q_ENUM(Status)
};

} // namespace ARB

#endif // AAPPLICATIONDATAMODELS_H
