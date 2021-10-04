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

class ADBProperties: public QObject {

	Q_OBJECT

	public:

		explicit ADBProperties(QObject* parent = nullptr) : QObject(parent) {}
		virtual ~ADBProperties(void) {}
};

class ADBSqliteProperties : public ADBProperties {

	public:

		QString Name = QString("NoName");
		QString Path = QString("NoPath");

		explicit ADBSqliteProperties(QObject* parent = nullptr) : ADBProperties(parent) {}
		virtual ~ADBSqliteProperties(void) {}
};

class ADBSqliteCipherProperties : public ADBSqliteProperties {

	public:

		QString Value = QString(A_DB_NULL_VALUE);

		explicit ADBSqliteCipherProperties(QObject* parent = nullptr) : ADBSqliteProperties(parent) {}
		virtual ~ADBSqliteCipherProperties(void) {}
};

class ADBSqliteReply {

	public:

		bool Status = false;
		QVariantList Output = {};

		ADBSqliteReply(void) {}
		virtual ~ADBSqliteReply(void) {}
};

} //namespace ARB

#endif // ADBDATAMODELS_H
