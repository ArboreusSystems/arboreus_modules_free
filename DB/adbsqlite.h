// ----------------------------------------------------------
/*!
	\headerfile ADBSqlite
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 04/10/2021 at 14:33:15
	\endlist
*/
// ----------------------------------------------------------

#ifndef ADBSQLITE_H
#define ADBSQLITE_H

// System includes

// Precompiled includes
#include <adbpch.h>

// Application includes
#include <aloggerglobal.h>
#include <adbdatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADBSqlite : public QObject {

	Q_OBJECT

	public:

		explicit ADBSqlite(QObject* parent = nullptr);
		virtual ~ADBSqlite(void);

		bool mStart(ADBProperties* inProperties);
		void mRemove(void);
		QString mGetDBName(void);
		QSqlDatabase mGetDB(void);
		ADBSqliteReply mGetTableInfo(QString inTableName);
		ADBSqliteReply mStringExecute(QString inQueryString);
		ADBSqliteReply mStringTransaction(QString inQueryString);
		ADBSqliteReply mQueryExecute(QSqlQuery inQuery);
		ADBSqliteReply mQueryTransaction(QSqlQuery inQuery);

	protected:

		QString pDriverName = QString("NoDriver");
		QString pPath = QString("NoPath");
		QString pName = QString("NoName");
};

} //namespace ARB

#endif // ADBSQLITE_H
