// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 14/12/2019 at 18:21:07
	\endlist
*/
// ----------------------------------------------------------
#ifndef ADBDATAMODELS_H
#define ADBDATAMODELS_H

// System includes
#include <QString>
#include <QVariantList>

// Application includes

// Constants and defintions
#define A_DB_NULL_VALUE "A_DB_NULL_VALUE"
#define A_DB_NULL_VALUE_QSTRING QString(A_DB_NULL_VALUE)


namespace ARB {

struct ASqlCipherProperties {

	QString Name = A_DB_NULL_VALUE_QSTRING;
	QString Path = A_DB_NULL_VALUE_QSTRING;
	QString Value = A_DB_NULL_VALUE_QSTRING;
};

struct ASqlCipherReply {

	bool Status = false;
	QVariantList Output = {};
};

} // namespace ARB

#endif // ADBDATAMODELS_H
