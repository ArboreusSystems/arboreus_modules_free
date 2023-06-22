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
#define _A_ENUMS_DATA_STRING_SIZE_TYPE ARB::AEnumsDataStringSizeType::StringSizeType


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

			Boolean, TrueBoolean, FalseBoolean,

			Integer, PositiveInteger, NegativeInteger, RangedInteger,
			Double, PositiveDouble, NegativeDouble, RangedDouble,

			String, StringWithoutSymbols, StringOfSize,	StringByRegex,
			StringMd, StringEmail, StringIPv4, StringIPv6
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

class AEnumsDataStringSizeType: public QObject {

	Q_OBJECT

	public:

		enum class StringSizeType: int {

			Undefined,
			Equal,
			Less,
			LessOrEqual,
			Greater,
			GreaterOrEqual,
			InRange
		};
		Q_ENUM(StringSizeType)
};

} // namespace ARB


// Namespace
namespace ARB {

class ADataReplyValidateBoolean {

	public:

		bool IsValid = false;
		bool Value = false;

		explicit ADataReplyValidateBoolean() {}
		virtual ~ADataReplyValidateBoolean(void) {}

		QVariantMap mToVariantMap(void) {

			QVariantMap oOutput;
			oOutput.insert("IsValid",IsValid);
			oOutput.insert("Value",Value);

			return oOutput;
		}
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::ADataReplyValidateBoolean)


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


// Namespace
namespace ARB {

class ADataReplyValidateDouble {

	public:

		bool IsValid = false;
		double Value = 0.0;

		explicit ADataReplyValidateDouble() {}
		virtual ~ADataReplyValidateDouble(void) {}

		QVariantMap mToVariantMap(void) {

			QVariantMap oOutput;
			oOutput.insert("IsValid",IsValid);
			oOutput.insert("Value",Value);

			return oOutput;
		}
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::ADataReplyValidateDouble)


// Namespace
namespace ARB {

class ADataReplyValidateString {

	public:

		bool IsValid = false;
		QString Value = "NoDefinedValue";

		explicit ADataReplyValidateString() {}
		virtual ~ADataReplyValidateString(void) {}

		QVariantMap mToVariantMap(void) {

			QVariantMap oOutput;
			oOutput.insert("IsValid",IsValid);
			oOutput.insert("Value",Value);

			return oOutput;
		}
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::ADataReplyValidateString)


// Namespace
namespace ARB {

class ADataStringSizeProperties {

	public:

		_A_ENUMS_DATA_STRING_SIZE_TYPE Type = _A_ENUMS_DATA_STRING_SIZE_TYPE::Undefined;
		int Size = 0;
		int Range1 = 0;
		int Range2 = 0;

		explicit ADataStringSizeProperties() {}
		virtual ~ADataStringSizeProperties(void) {}
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::ADataStringSizeProperties)

#endif // ADATAMODELS_H
