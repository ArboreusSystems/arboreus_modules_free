// ----------------------------------------------------------
/*!
	\headerfile ACryptography
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 11/09/2021 at 17:46:32
	\endlist
*/
// ----------------------------------------------------------

#ifndef ACRYPTOGRAPHY_H
#define ACRYPTOGRAPHY_H

// System includes

// Precompiled includes
#include <acryptographypch.h>

// Application includes
#include <acryptographydatamodels.h>
#include <asequencestring.h>
#include <acryptographymetatypes.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ACryptography : public QObject {

	Q_OBJECT

	public:

		explicit ACryptography(QObject* parent = nullptr);
		virtual ~ACryptography(void);

		static QByteArray mValue(QString inString);
		static QByteArray mVector(QString inString);
		static QByteArray mSignAdd(QByteArray inDatumn);
		static ACryptographySignReply mSignRemove(QByteArray inDatumn);

};

} // namespace ARB

#endif // ACRYPTOGRAPHY_H
