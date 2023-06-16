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


// Namespace
namespace ARB {

class AEnumsDataReplyType: public QObject {

	Q_OBJECT

	public:

		enum class ReplyType: int {

			Error = 0,
			Ok = 1,
			NotValid = 2
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

			Integer, PositiveInteger, NegativeInteger,RangedInteger,
			Float, PositiveFloat, NegativeFloat,RangedFloat,

			String,StringWithoutSymbols,StringOfSize,
			Md5,NumericString,StringByDictionary,

			Email,IP,DNS,URL
		};
		Q_ENUM(DataType)
};

} // namespace ARB

#endif // ADATAMODELS_H
