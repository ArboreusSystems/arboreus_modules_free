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
#include <aloggerglobal.h>

// Constants and defintions
#define _A_ENUMS_DATA_REPLY_TYPE ARB::AEnumsDataReplyType::ReplyType
#define _A_ENUMS_DATA_TYPE ARB::AEnumsDataType::DataType
#define _A_ENUMS_DATA_DICTIONARY_TYPE ARB::AEnumsDataDictionaryType::DictionaryType
#define _A_ENUMS_DATA_STRING_SIZE_TYPE ARB::AEnumsDataStringSizeType::StringSizeType
#define _A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE ARB::AEnumsDataStructureValidationType::ValidationType


// Namespace
namespace ARB {

class AEnumsDataReplyType: public QObject {

	Q_OBJECT

	public:

		enum class ReplyType: int {

			Error = 0,
			Ok,
			NotValid,
			WrongStructure,
			WrongRule,
			NoStructure,
			NoModel,
			NoKey
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
			StringMd, StringEmail, StringIPv4, StringIPv6,

			Structure
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

class AEnumsDataStructureValidationType: public QObject {

	Q_OBJECT

	public:

		enum class ValidationType: int {

			Undefined,
			Map,
			List
		};
		Q_ENUM(ValidationType)
};

} // namespace ARB


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


// Namespace
namespace ARB {

class ADataReplyValidate {

	public:

		_A_ENUMS_DATA_REPLY_TYPE Status = _A_ENUMS_DATA_REPLY_TYPE::Error;
		_A_ENUMS_DATA_TYPE Type = _A_ENUMS_DATA_TYPE::Undefined;
		QString Message = "NoDefinedMessage";
		int Integer = 0;
		double Double = 0.0;
		bool Boolean = false;
		QString String = "NoDefinedString";
		QVariant Structure = {};

		explicit ADataReplyValidate() {}
		virtual ~ADataReplyValidate(void) {}

		QVariantMap mToVariantMap(void) {

			QVariantMap oOutput;
			oOutput.insert("Status",static_cast<int>(Status));
			oOutput.insert("Type",static_cast<int>(Type));
			oOutput.insert("Message",Message);

			QVariant oData = 0;
			if (
				this->Type == _A_ENUMS_DATA_TYPE::Integer ||
				this->Type == _A_ENUMS_DATA_TYPE::NegativeInteger ||
				this->Type == _A_ENUMS_DATA_TYPE::PositiveInteger ||
				this->Type == _A_ENUMS_DATA_TYPE::RangedInteger
			) {
				oData = this->Integer;
			} else if (
				this->Type == _A_ENUMS_DATA_TYPE::Boolean ||
				this->Type == _A_ENUMS_DATA_TYPE::FalseBoolean ||
				this->Type == _A_ENUMS_DATA_TYPE::TrueBoolean
			) {
				oData = this->Boolean;
			} else if (
				this->Type == _A_ENUMS_DATA_TYPE::Double ||
				this->Type == _A_ENUMS_DATA_TYPE::NegativeDouble ||
				this->Type == _A_ENUMS_DATA_TYPE::PositiveDouble ||
				this->Type == _A_ENUMS_DATA_TYPE::RangedDouble
			) {
				oData = this->Double;
			} else if (
				this->Type == _A_ENUMS_DATA_TYPE::String ||
				this->Type == _A_ENUMS_DATA_TYPE::StringByRegex ||
				this->Type == _A_ENUMS_DATA_TYPE::StringEmail ||
				this->Type == _A_ENUMS_DATA_TYPE::StringIPv4 ||
				this->Type == _A_ENUMS_DATA_TYPE::StringIPv6 ||
				this->Type == _A_ENUMS_DATA_TYPE::StringMd ||
				this->Type == _A_ENUMS_DATA_TYPE::StringOfSize ||
				this->Type == _A_ENUMS_DATA_TYPE::StringWithoutSymbols
			) {
				oData = this->String;
			} else if (
				this->Type == _A_ENUMS_DATA_TYPE::Structure
			) {
				oData = this->Structure;
			}
			oOutput.insert("Data",oData);


			return oOutput;
		}
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::ADataReplyValidate)

#endif // ADATAMODELS_H
