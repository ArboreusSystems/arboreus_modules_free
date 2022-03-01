// ----------------------------------------------------------
/*!
	\headerfile ADBSqlGenerator
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 01/03/2022 at 19:46:17
	\endlist
*/
// ----------------------------------------------------------

#ifndef ADBSQLGENERATOR_H
#define ADBSQLGENERATOR_H

// System includes

// Precompiled includes
#include <adbpch.h>

// Application includes
#include <adbdatamodels.h>
#include <aloggerglobal.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADBSqlGenerator : public QObject {

	Q_OBJECT

	public:

		explicit ADBSqlGenerator(QObject* parent = nullptr);
		virtual ~ADBSqlGenerator(void);

		static QString mCreateTable(ADBTableProperties inProperties);
};

} // namespace ARB

#endif // ADBSQLGENERATOR_H
