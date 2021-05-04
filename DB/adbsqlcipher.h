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

#ifndef ADBSQLCIPHER_H
#define ADBSQLCIPHER_H

// System includes
#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

// Application includes
#include <aloggerglobal.h>
#include <adbdatamodels.h>

// Constants and definitions
#define A_DB_SQL_CIPHER_DRIVER "SQLITECIPHER"

// Namespace
namespace ARB {

// Class definitions
class ADBSqlCipher : public QObject {

	Q_OBJECT

	public:

		explicit ADBSqlCipher(QObject *parent = nullptr);
		virtual ~ADBSqlCipher(void);

		bool mStart(ADBSqlCipherProperties* inProperties);
		void mRemove(void);
		QString mGetDBName(void);
		QSqlDatabase mGetDB(void);
		ADBSqlCipherReply mStringExecute(QString inQueryString);
		ADBSqlCipherReply mStringTransaction(QString inQueryString);
		ADBSqlCipherReply mQueryExecute(QSqlQuery inQuery);
		ADBSqlCipherReply mQueryTransaction(QSqlQuery inQuery);

	private:

		QString pPath = QString("NoPath");
		QString pName = QString("NoName");
		QString pValue = QString(A_DB_NULL_VALUE);
};

} // namespace ARB

#endif // ADBSQLCIPHER_H
