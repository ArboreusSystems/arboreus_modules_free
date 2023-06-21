// ----------------------------------------------------------
/*!
    \headerfile
    \title
    \brief Template file files/cppheader/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 16/06/2023 at 19:15:43
    \endlist
*/
// ----------------------------------------------------------
#ifndef ADATAMODELS_H
#define ADATAMODELS_H

// System includes

// Precompiled includes
#include <adatapch.h>

// Application includes

// Constants and defintions
#define _A_ENUMS_DATA_REPLY_TYPE ARB::AEnumsDataReplyType::ReplyType
#define _A_ENUMS_DATA_TYPE ARB::AEnumsDataType::DataType
#define _A_ENUMS_DATA_DICTIONARY_TYPE ARB::AEnumsDataDictionaryType::DictionaryType


// Namespace
namespace ARB {

class AEnumsDataReplyType: public QObject {

	Q_OBJECT

	public:

		enum class ReplyType: int {

			Error = 0,
			Ok = 1,
			NotValid = 2,
			WrongRule = 3
		};
		Q_ENUM(ReplyType)
};

} // namespace ARB


// Namespace
namespace ARB {

class AEnumsDataType: public QObject {

	Q_OBJECT

	public:

		enum class DataType: int {

			Undefined,

			Integer, PositiveInteger, NegativeInteger, RangedInteger,
			Float, PositiveFloat, NegativeFloat, RangedFloat,

			String, StringWithoutSymbols, StringOfSize,
			Md5, NumericString, StringByDictionary,

			Email, IP, DNS, URL
		};
		Q_ENUM(DataType)
};

} // namespace ARB


// Namespace
namespace ARB {

class AEnumsDataDictionaryType: public QObject {

	Q_OBJECT

	public:

		enum class DictionaryType: int {

			Undefined,
			Numeric,
			AlphaLowerCase,
			AlphaUpperCase,
			Exclusion
		};
		Q_ENUM(DictionaryType)
};

} // namespace ARB


// Namespace
namespace ARB {

class ADataReplyValidateInteger {

	public:

		bool IsValid = false;
		int Value = 0;

		explicit ADataReplyValidateInteger() {}
		virtual ~ADataReplyValidateInteger(void) {}

		QVariantMap mToVariantMap(void) {

			QVariantMap oOutput;
			oOutput.insert("IsValid",IsValid);
			oOutput.insert("Value",Value);

			return oOutput;
		}
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::ADataReplyValidateInteger)

#endif // ADATAMODELS_H
