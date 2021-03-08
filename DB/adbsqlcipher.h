// ----------------------------------------------------------
/*!
	\headerfile ADBSqlCipher
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 14/12/2019 at 18:18:45
	\endlist
*/
// ----------------------------------------------------------
#ifndef ADBSQLCIPHER_H
#define ADBSQLCIPHER_H

// System includes
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QVariantList>
#include <QVariant>
#include <QList>

// Application includes
#include <adbdatamodels.h>
#include <alogger.h>


// Constants and definitions


namespace ARB {

class ADBSqlCipher : public QObject {

	Q_OBJECT

	public:

		explicit ADBSqlCipher(QObject *inParent = nullptr);
		explicit ADBSqlCipher(ASqlCipherProperties inProperties,QObject* inParent = nullptr);
		virtual ~ADBSqlCipher(void);

		QSqlDatabase pDB;

		bool mStart(ASqlCipherProperties inProperties);
		bool mClose(void);
		ASqlCipherReply mStringExecute(QString inQueryString);
		ASqlCipherReply mStringTransaction(QString inQueryString);
		ASqlCipherReply mQueryExecute(QSqlQuery inQuery);
		ASqlCipherReply mQueryTransaction(QSqlQuery inQuery);

	private:

		bool mCheckDriver(void);
};

} // namespace ARB

#endif // ADBSQLCIPHER_H
