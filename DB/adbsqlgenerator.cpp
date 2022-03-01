// ----------------------------------------------------------
/*!
	\class ADBSqlGenerator
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 01/03/2022 at 19:46:17
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "adbsqlgenerator.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ADBSqlGenerator::ADBSqlGenerator(QObject* parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

ADBSqlGenerator::~ADBSqlGenerator(void) {}


// -----------
/*!
	\fn

	Doc.
*/

QString ADBSqlGenerator::mCreateTable(ADBTableProperties inProperties) {

	bool oPrimaryKey = false;
	QString oOutput = QString("") +
		"CREATE TABLE IF NOT EXISTS " +
		inProperties.Name +
		" (id INTEGER PRIMARY KEY AUTOINCREMENT, ";

	for (int i = 0; i < inProperties.Schema.length(); i++) {

		ADBFieldProperties* iField = &inProperties.Schema[i];

		oOutput += iField->Name + " ";

		switch (iField->Type) {
			case _A_ENUM_DB_SQLITE_FIELD_TYPE::Integer: oOutput += "INTEGER"; break;
			case _A_ENUM_DB_SQLITE_FIELD_TYPE::Text: oOutput += "TEXT"; break;
			case _A_ENUM_DB_SQLITE_FIELD_TYPE::Blob: oOutput += "BLOB"; break;
			case _A_ENUM_DB_SQLITE_FIELD_TYPE::Real: oOutput += "REAL"; break;
			case _A_ENUM_DB_SQLITE_FIELD_TYPE::Null: oOutput += "NULL"; break;
			default:
				_A_CRITICAL << "Wrong or undefined data type for SQL table";
				break;
		}

		if ((!oPrimaryKey) && iField->PrimaryKey) {
			oOutput += " PRIMARY KEY";
			oPrimaryKey = true;
		}

		if (iField->NotNull) oOutput += " NOT NULL";
		if (iField->Unique && oPrimaryKey) oOutput += " UNIQUE";
		if (i != (inProperties.Schema.length() - 1)) oOutput += ", ";
	}

	oOutput += ");";
	return oOutput;
}

