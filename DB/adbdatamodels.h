// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 01/05/2021 at 14:00:04
	\endlist
*/
// ----------------------------------------------------------
#ifndef ADBDATAMODELS_H
#define ADBDATAMODELS_H

// System includes

// Precompiled includes
#include <adbpch.h>

// Application includes

// Constants and defintions
#define A_DB_NULL_VALUE "A_DB_NULL_VALUE"

// Namespace
namespace ARB {

class ADBSqlCipherProperties : public QObject {

	Q_OBJECT

	public:

		QString Name = QString("NoName");
		QString Path = QString("NoPath");
		QString Value = QString(A_DB_NULL_VALUE);

		explicit ADBSqlCipherProperties(QObject* parent = nullptr) : QObject(parent) {}
		virtual ~ADBSqlCipherProperties(void) {}
};

class ADBSqlCipherReply {

	public:

		bool Status = false;
		QVariantList Output = {};

		ADBSqlCipherReply(void) {}
		virtual ~ADBSqlCipherReply(void) {}
};

} //namespace ARB

#endif // ADBDATAMODELS_H
