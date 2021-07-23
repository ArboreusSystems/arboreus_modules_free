// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 23/07/2021 at 19:32:56
	\endlist
*/
// ----------------------------------------------------------
#ifndef AJSONDATAMODELS_H
#define AJSONDATAMODELS_H

// System includes
#include <QObject>
#include <QJsonObject>
#include <QVariant>

// Application includes
#include <aapplicationdatamodels.h>

// Constants and defintions

// Namespace
namespace ARB {

class AJsonFileReply {

	public:

		AEnums::Status Status = AEnums::Status::Error;
		QJsonObject Json;
};

class AJsonFieldReply {

	public:

		AEnums::Status Status = AEnums::Status::Error;
		QVariant Value;
};

} // namespace ARB

#endif // AJSONDATAMODELS_H
