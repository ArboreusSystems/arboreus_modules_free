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

#ifndef ADATATYPES_H
#define ADATATYPES_H

// System includes

// Precompiled includes
#include <adatapch.h>

// Application includes
#include <aloggerglobal.h>
#include <adatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADataTypes : public QObject {

	Q_OBJECT

	public:

		explicit ADataTypes(QObject* parent = nullptr);
		virtual ~ADataTypes(void);

		ADataReplyValidateBoolean mValidateBoolean(QVariant inValue);
		ADataReplyValidateBoolean mValidateTrueBoolean(QVariant inValue);
		ADataReplyValidateBoolean mValidateFalseBoolean(QVariant inValue);

		ADataReplyValidateInteger mValidateInteger(QVariant inValue);
		ADataReplyValidateInteger mValidatePositiveInteger(QVariant inValue);
		ADataReplyValidateInteger mValidateNegativeInteger(QVariant inValue);
		ADataReplyValidateInteger mValidateRangedInteger(QVariant inValue,int inRange1, int inRange2);

		ADataReplyValidateDouble mValidateDouble(QVariant inValue);
		ADataReplyValidateDouble mValidatePositiveDouble(QVariant inValue);
		ADataReplyValidateDouble mValidateNegativeDouble(QVariant inValue);
		ADataReplyValidateDouble mValidateRangedDouble(QVariant inValue,double inRange1, double inRange2);

		ADataReplyValidateString mValidateString(QVariant inValue);
		ADataReplyValidateString mValidateStringWithoutSymbols(QVariant inValue,QList<QString> inSymbols);
		ADataReplyValidateString mValidateStringOfSize(QVariant inValue, ADataStringSizeProperties inProperties);
		ADataReplyValidateString mValidateStringByRegex(QVariant inValue, QString inRegex);
		ADataReplyValidateString mValidateStringMd(QVariant inValue);
		ADataReplyValidateString mValidateStringEmail(QVariant inValue);
		ADataReplyValidateString mValidateStringIPv4(QVariant inValue);
		ADataReplyValidateString mValidateStringIPv6(QVariant inValue);

	public slots:

		QVariantMap mValidate(_A_ENUMS_DATA_TYPE inType,QVariant inValue,QVariantMap inProperties = {});
};

} // namespace ARB

#endif // ADATATYPES_H
