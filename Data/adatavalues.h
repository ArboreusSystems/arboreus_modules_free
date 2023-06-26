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

		ADataReplyValidateValue mValidateBoolean(QVariant inValue);
		ADataReplyValidateValue mValidateTrueBoolean(QVariant inValue);
		ADataReplyValidateValue mValidateFalseBoolean(QVariant inValue);

		ADataReplyValidateValue mValidateInteger(QVariant inValue);
		ADataReplyValidateValue mValidatePositiveInteger(QVariant inValue);
		ADataReplyValidateValue mValidateNegativeInteger(QVariant inValue);
		ADataReplyValidateValue mValidateRangedInteger(QVariant inValue,int inRange1, int inRange2);

		ADataReplyValidateValue mValidateDouble(QVariant inValue);
		ADataReplyValidateValue mValidatePositiveDouble(QVariant inValue);
		ADataReplyValidateValue mValidateNegativeDouble(QVariant inValue);
		ADataReplyValidateValue mValidateRangedDouble(QVariant inValue,double inRange1, double inRange2);

		ADataReplyValidateValue mValidateString(QVariant inValue);
		ADataReplyValidateValue mValidateStringWithoutSymbols(QVariant inValue,QList<QString> inSymbols);
		ADataReplyValidateValue mValidateStringOfSize(QVariant inValue, ADataStringSizeProperties inProperties);
		ADataReplyValidateValue mValidateStringByRegex(QVariant inValue, QString inRegex);
		ADataReplyValidateValue mValidateStringMd(QVariant inValue);
		ADataReplyValidateValue mValidateStringEmail(QVariant inValue);
		ADataReplyValidateValue mValidateStringIPv4(QVariant inValue);
		ADataReplyValidateValue mValidateStringIPv6(QVariant inValue);

		ADataReplyValidateValue mValidate(_A_ENUMS_DATA_TYPE inType,QVariant inValue,QVariantMap inProperties = {});

	private:

		ADataStructures* pStructures = nullptr;
};

} // namespace ARB

#endif // ADATATYPES_H
