// ----------------------------------------------------------
/*!
	\headerfile ADBSqlCipher
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 01/05/2021 at 14:00:40
	\endlist
*/
// ----------------------------------------------------------

#ifndef ADBSQLITECIPHER_H
#define ADBSQLITECIPHER_H

// System includes

// Precompiled includes
#include <adbpch.h>

// Application includes
#include <aloggerglobal.h>
#include <adbdatamodels.h>
#include <adbsqlite.h>

// Constants and definitions
#define A_DB_SQL_CIPHER_DRIVER "SQLITECIPHER"

// Namespace
namespace ARB {

// Class definitions
class ADBSqliteCipher : public ADBSqlite {

	public:

		explicit ADBSqliteCipher(QObject* parent = nullptr);
		virtual ~ADBSqliteCipher(void);

		bool mStart(ADBProperties* inProperties);

	private:

		QString pValue = QString(_A_DB_NULL_VALUE);
};

} // namespace ARB

#endif // ADBSQLITECIPHER_H
