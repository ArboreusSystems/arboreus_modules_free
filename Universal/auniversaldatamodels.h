// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 11/09/2021 at 18:10:21
	\endlist
*/
// ----------------------------------------------------------
#ifndef AUNIVERSALDATAMODELS_H
#define AUNIVERSALDATAMODELS_H

// System includes

// Precompiled includes
#include <auniversalpch.h>

// Application includes
#include <aapplicationdatamodels.h>
#include <arandomdatamodels.h>

// Constants and defintions
#define _A_ENUMS_DICTIONARY_TYPE ARB::AEnumsDictionaryType::DictionaryType

// Namespace
namespace ARB {

class AEnumsDictionaryType: public QObject {

	Q_OBJECT

	public:

		enum class DictionaryType: int {

			AlphaLower, AlphaUpper, Alpha, AlphaLowerNumeric,
			AlphaUpperNumeric, AlphaNumeric, Symbols,
			Numeric
		};
		Q_ENUM(DictionaryType)
};

} // namespace ARB


// Namespace
namespace ARB {

class AJsonFileReply {

	public:

		_A_ENUMS_APPLICATION_REPLY_STATUS Status = _A_ENUMS_APPLICATION_REPLY_STATUS::Error;
		QJsonObject Json;
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::AJsonFileReply)


// Namespace
namespace ARB {

class AJsonFieldReply {

	public:

		_A_ENUMS_APPLICATION_REPLY_STATUS Status = _A_ENUMS_APPLICATION_REPLY_STATUS::Error;
		QVariant Value;
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::AJsonFieldReply)


// Namespace
namespace ARB {

class AFileReply {

	public:

		_A_ENUMS_APPLICATION_REPLY_STATUS Status = _A_ENUMS_APPLICATION_REPLY_STATUS::Error;
		QByteArray Datumn = 0;
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::AFileReply)

#endif // AUNIVERSALDATAMODELS_H
