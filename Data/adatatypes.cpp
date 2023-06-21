// ----------------------------------------------------------
/*!
    \class ADataType
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 16/06/2023 at 19:09:54
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "adatatypes.h"

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

ADataTypes::ADataTypes(QObject* parent) : QObject(parent) {

	_A_DEBUG << "ADataTypes created";
}


// -----------
/*!
	\fn

	Doc.
*/

ADataTypes::~ADataTypes(void) {

	_A_DEBUG << "ADataTypes deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateInteger ADataTypes::mValidateInteger(QVariant inValue) {

	ADataReplyValidateInteger oOutput;

	if (inValue.userType() == QMetaType::Int) {
		 oOutput.IsValid = true;
		 oOutput.Value = qvariant_cast<int>(inValue);
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/


ADataReplyValidateInteger ADataTypes::mValidatePositiveInteger(QVariant inValue) {

	ADataReplyValidateInteger oOutput;

	ADataReplyValidateInteger oCheckInteger = this->mValidateInteger(inValue);
	if (oCheckInteger.IsValid) {
		if (oCheckInteger.Value >= 0) oOutput = oCheckInteger;
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateInteger ADataTypes::mValidateNegativeInteger(QVariant inValue) {

	ADataReplyValidateInteger oOutput;

	ADataReplyValidateInteger oCheckInteger = this->mValidateInteger(inValue);
	if (oCheckInteger.IsValid) {
		if (oCheckInteger.Value < 0) oOutput = oCheckInteger;
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateInteger ADataTypes::mValidateRangedInteger(QVariant inValue, int inRange1, int inRange2) {

	ADataReplyValidateInteger oOutput;

	int oMax = 0;
	int oMin = 0;
	if (inRange1 > inRange2) {
		oMax = inRange1;
		oMin = inRange2;
	} else {
		oMax = inRange2;
		oMin = inRange1;
	}

	ADataReplyValidateInteger oCheckInteger = this->mValidateInteger(inValue);
	if (oCheckInteger.IsValid) {
		if (oCheckInteger.Value <= oMax && oCheckInteger.Value >= oMin) oOutput = oCheckInteger;
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateFloat ADataTypes::mValidateDouble(QVariant inValue) {

	ADataReplyValidateFloat oOutput;

	if (inValue.userType() == QMetaType::Double) {
		 oOutput.IsValid = true;
		 oOutput.Value = qvariant_cast<double>(inValue);
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateFloat ADataTypes::mValidatePositiveDouble(QVariant inValue) {

	ADataReplyValidateFloat oOutput;

	ADataReplyValidateFloat oCheckFloat = this->mValidateDouble(inValue);
	if (oCheckFloat.IsValid) {
		if (oCheckFloat.Value >= 0) oOutput = oCheckFloat;
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateFloat ADataTypes::mValidateNegativeDouble(QVariant inValue) {

	ADataReplyValidateFloat oOutput;

	ADataReplyValidateFloat oCheckFloat = this->mValidateDouble(inValue);
	if (oCheckFloat.IsValid) {
		if (oCheckFloat.Value < 0) oOutput = oCheckFloat;
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateFloat ADataTypes::mValidateRangedDouble(QVariant inValue, double inRange1, double inRange2) {

	ADataReplyValidateFloat oOutput;

	double oMax = 0;
	double oMin = 0;
	if (inRange1 > inRange2) {
		oMax = inRange1;
		oMin = inRange2;
	} else {
		oMax = inRange2;
		oMin = inRange1;
	}

	ADataReplyValidateFloat oCheckFloat = this->mValidateDouble(inValue);
	if (oCheckFloat.IsValid) {
		if (oCheckFloat.Value <= oMax && oCheckFloat.Value >= oMin) oOutput = oCheckFloat;
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ADataTypes::mValidate(_A_ENUMS_DATA_TYPE inType, QVariant inValue, QVariantMap inProperties) {

	QVariantMap oOutput;

	switch (inType) {
		case _A_ENUMS_DATA_TYPE::Integer:
			oOutput = this->mValidateInteger(inValue).mToVariantMap();
			break;
		case _A_ENUMS_DATA_TYPE::PositiveInteger:
			oOutput = this->mValidatePositiveInteger(inValue).mToVariantMap();
			break;
		case _A_ENUMS_DATA_TYPE::NegativeInteger:
			oOutput = this->mValidateNegativeInteger(inValue).mToVariantMap();
			break;
		case _A_ENUMS_DATA_TYPE::RangedInteger:
			oOutput = this->mValidateRangedInteger(
				inValue,
				qvariant_cast<int>(inProperties.value("Range1")),
				qvariant_cast<int>(inProperties.value("Range2"))
			).mToVariantMap();
			break;
		case _A_ENUMS_DATA_TYPE::Double:
			oOutput = this->mValidateDouble(inValue).mToVariantMap();
			break;
		case _A_ENUMS_DATA_TYPE::PositiveDouble:
			oOutput = this->mValidatePositiveDouble(inValue).mToVariantMap();
			break;
		case _A_ENUMS_DATA_TYPE::NegativeDouble:
			oOutput = this->mValidateNegativeDouble(inValue).mToVariantMap();
			break;
		case _A_ENUMS_DATA_TYPE::RangedDouble:
			oOutput = this->mValidateRangedDouble(
				inValue,
				qvariant_cast<double>(inProperties.value("Range1")),
				qvariant_cast<double>(inProperties.value("Range2"))
			).mToVariantMap();
			break;
		default:
			break;
	}

	return oOutput;
}

