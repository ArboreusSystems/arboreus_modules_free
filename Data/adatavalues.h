// ----------------------------------------------------------
/*!
    \headerfile ADataType
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 16/06/2023 at 19:09:54
    \endlist
*/
// ----------------------------------------------------------

#ifndef ADATAVALUES_H
#define ADATAVALUES_H

// System includes

// Precompiled includes
#include <adatapch.h>

// Application includes
#include <aloggerglobal.h>
#include <adatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Classes
class ADataStructures;

// Class definitions
class ADataValues : public QObject {

	public:

		explicit ADataValues(ADataStructures* inStructures,QObject* parent = nullptr);
		explicit ADataValues(QObject* parent = nullptr);
		virtual ~ADataValues(void);

		ADataReplyValidate mValidateBoolean(QVariant inValue);
		ADataReplyValidate mValidateTrueBoolean(QVariant inValue);
		ADataReplyValidate mValidateFalseBoolean(QVariant inValue);

		ADataReplyValidate mValidateInteger(QVariant inValue);
		ADataReplyValidate mValidatePositiveInteger(QVariant inValue);
		ADataReplyValidate mValidateNegativeInteger(QVariant inValue);
		ADataReplyValidate mValidateRangedInteger(QVariant inValue,int inRange1, int inRange2);

		ADataReplyValidate mValidateDouble(QVariant inValue);
		ADataReplyValidate mValidatePositiveDouble(QVariant inValue);
		ADataReplyValidate mValidateNegativeDouble(QVariant inValue);
		ADataReplyValidate mValidateRangedDouble(QVariant inValue,double inRange1, double inRange2);

		ADataReplyValidate mValidateString(QVariant inValue);
		ADataReplyValidate mValidateStringWithoutSymbols(QVariant inValue,QList<QString> inSymbols);
		ADataReplyValidate mValidateStringOfSize(QVariant inValue, ADataStringSizeProperties inProperties);
		ADataReplyValidate mValidateStringByRegex(QVariant inValue, QString inRegex);
		ADataReplyValidate mValidateStringMd(QVariant inValue);
		ADataReplyValidate mValidateStringEmail(QVariant inValue);
		ADataReplyValidate mValidateStringIPv4(QVariant inValue);
		ADataReplyValidate mValidateStringIPv6(QVariant inValue);

		ADataReplyValidate mValidate(_A_ENUMS_DATA_TYPE inType,QVariant inValue,QVariantMap inProperties = {});

	private:

		ADataStructures* pStructures = nullptr;
};

} // namespace ARB

#endif // ADATATYPES_H
