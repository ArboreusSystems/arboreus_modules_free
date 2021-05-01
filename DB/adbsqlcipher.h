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

// Application includes
#include <adbdatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADBSqlCipher : public QObject {

	Q_OBJECT

	public:

		explicit ADBSqlCipher(QObject *parent = nullptr);
		virtual ~ADBSqlCipher(void);

	signals:

};

} // namespace ARB

#endif // ADBSQLCIPHER_H
