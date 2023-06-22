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

ADataReplyValidateBoolean ADataTypes::mValidateBoolean(QVariant inValue) {

	ADataReplyValidateBoolean oOutput;

	if (inValue.userType() == QMetaType::Bool) {
		 oOutput.IsValid = true;
		 oOutput.Value = qvariant_cast<bool>(inValue);
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateBoolean ADataTypes::mValidateTrueBoolean(QVariant inValue) {

	ADataReplyValidateBoolean oOutput;

	ADataReplyValidateBoolean oCheckboolean = this->mValidateBoolean(inValue);
	if (oCheckboolean.IsValid) {
		if (oCheckboolean.Value) oOutput = oCheckboolean;
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateBoolean ADataTypes::mValidateFalseBoolean(QVariant inValue) {

	ADataReplyValidateBoolean oOutput;

	ADataReplyValidateBoolean oCheckboolean = this->mValidateBoolean(inValue);
	if (oCheckboolean.IsValid) {
		if (!oCheckboolean.Value) oOutput = oCheckboolean;
	}

	return oOutput;
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

ADataReplyValidateDouble ADataTypes::mValidateDouble(QVariant inValue) {

	ADataReplyValidateDouble oOutput;

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

ADataReplyValidateDouble ADataTypes::mValidatePositiveDouble(QVariant inValue) {

	ADataReplyValidateDouble oOutput;

	ADataReplyValidateDouble oCheckFloat = this->mValidateDouble(inValue);
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

ADataReplyValidateDouble ADataTypes::mValidateNegativeDouble(QVariant inValue) {

	ADataReplyValidateDouble oOutput;

	ADataReplyValidateDouble oCheckFloat = this->mValidateDouble(inValue);
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

ADataReplyValidateDouble ADataTypes::mValidateRangedDouble(QVariant inValue, double inRange1, double inRange2) {

	ADataReplyValidateDouble oOutput;

	double oMax = 0;
	double oMin = 0;
	if (inRange1 > inRange2) {
		oMax = inRange1;
		oMin = inRange2;
	} else {
		oMax = inRange2;
		oMin = inRange1;
	}

	ADataReplyValidateDouble oCheckFloat = this->mValidateDouble(inValue);
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

ADataReplyValidateString ADataTypes::mValidateString(QVariant inValue) {

	ADataReplyValidateString oOutput;

	if (inValue.userType() == QMetaType::QString) {
		 oOutput.IsValid = true;
		 oOutput.Value = qvariant_cast<QString>(inValue);
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateString ADataTypes::mValidateStringWithoutSymbols(QVariant inValue, QList<QString> inSymbols) {

	ADataReplyValidateString oOutput;
	bool oContains = false;

	ADataReplyValidateString oCheckString = this->mValidateString(inValue);
	if (oCheckString.IsValid) {
		QList<QString>::iterator iSymbol;
		for (iSymbol = inSymbols.begin(); iSymbol != inSymbols.end(); ++iSymbol) {
			if (oCheckString.Value.contains(*iSymbol)) oContains = true;
		}
	}

	if (!oContains) oOutput = oCheckString;
	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateString ADataTypes::mValidateStringOfSize(QVariant inValue, ADataStringSizeProperties inProperties) {

	ADataReplyValidateString oOutput;

	int oSize = 0;

	int oMax = 0;
	int oMin = 0;
	if (inProperties.Range1 >= inProperties.Range2) {
		oMax = inProperties.Range1;
		oMin = inProperties.Range2;
	} else {
		oMax = inProperties.Range2;
		oMin = inProperties.Range1;
	}

	ADataReplyValidateString oCheckString = this->mValidateString(inValue);
	if (oCheckString.IsValid) {
		oSize = oCheckString.Value.size();
		switch (inProperties.Type) {
			case _A_ENUMS_DATA_STRING_SIZE_TYPE::Equal:
				if (oSize == inProperties.Size) oOutput = oCheckString;
				break;
			case _A_ENUMS_DATA_STRING_SIZE_TYPE::Less:
				if (oSize < inProperties.Size) oOutput = oCheckString;
				break;
			case _A_ENUMS_DATA_STRING_SIZE_TYPE::LessOrEqual:
				if (oSize <= inProperties.Size) oOutput = oCheckString;
				break;
			case _A_ENUMS_DATA_STRING_SIZE_TYPE::Greater:
				if (oSize > inProperties.Size) oOutput = oCheckString;
				break;
			case _A_ENUMS_DATA_STRING_SIZE_TYPE::GreaterOrEqual:
				if (oSize >= inProperties.Size) oOutput = oCheckString;
				break;
			case _A_ENUMS_DATA_STRING_SIZE_TYPE::InRange:
				if (oSize >= oMin && oSize <= oMax) oOutput = oCheckString;
				break;
			default:
				break;
			}
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateString ADataTypes::mValidateStringByRegex(QVariant inValue, QString inRegex) {

	ADataReplyValidateString oOutput;

	ADataReplyValidateString oCheckString = this->mValidateString(inValue);
	if (oCheckString.IsValid) {

		QRegularExpression oExpression(inRegex);
		QRegularExpressionMatch oMatch = oExpression.match(oCheckString.Value);
		if(oMatch.hasMatch()) {
			oOutput = oCheckString;
		}
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateString ADataTypes::mValidateStringMd(QVariant inValue) {

	return this->mValidateStringByRegex(
		inValue,
		"^[0-9A-Z]{32}$"
	);
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateString ADataTypes::mValidateStringEmail(QVariant inValue) {

	return this->mValidateStringByRegex(
		inValue,
		"^([.]{0,1}[a-zA-Z0-9-]{0,}){1,}@([.]{0,1}[a-zA-Z0-9-]{0,}){1,}$"
	);
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateString ADataTypes::mValidateStringIPv4(QVariant inValue) {

	ADataReplyValidateString oOutput;
	int oIsValid = 0;

	ADataReplyValidateString oCheckString = this->mValidateStringByRegex(
		inValue,
		"^[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}$"
	);
	if (oCheckString.IsValid) {
		QStringList oList = oCheckString.Value.split(".");
		for (int i = 0; i < oList.size(); ++i) {
			int iNumber = oList[i].toInt();
			if (iNumber >= 0 && iNumber <= 255) ++oIsValid;
		}
	}

	if (oIsValid == 4) oOutput = oCheckString;

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateString ADataTypes::mValidateStringIPv6(QVariant inValue) {

	return this->mValidateStringByRegex(
		inValue,
		"(([0-9a-fA-F]{1,4}:){7,7}[0-9a-fA-F]{1,4}|"
		"([0-9a-fA-F]{1,4}:){1,7}:|([0-9a-fA-F]{1,4}:){1,6}:[0-9a-fA-F]{1,4}|"
		"([0-9a-fA-F]{1,4}:){1,5}(:[0-9a-fA-F]{1,4}){1,2}|"
		"([0-9a-fA-F]{1,4}:){1,4}(:[0-9a-fA-F]{1,4}){1,3}|"
		"([0-9a-fA-F]{1,4}:){1,3}(:[0-9a-fA-F]{1,4}){1,4}|"
		"([0-9a-fA-F]{1,4}:){1,2}(:[0-9a-fA-F]{1,4}){1,5}|"
		"[0-9a-fA-F]{1,4}:((:[0-9a-fA-F]{1,4}){1,6})|"
		":((:[0-9a-fA-F]{1,4}){1,7}|:)|"
		"fe80:(:[0-9a-fA-F]{0,4}){0,4}%[0-9a-zA-Z]{1,}|"
		"::(ffff(:0{1,4}){0,1}:){0,1}((25[0-5]|(2[0-4]|"
		"1{0,1}[0-9]){0,1}[0-9]).){3,3}(25[0-5]|(2[0-4]|"
		"1{0,1}[0-9]){0,1}[0-9])|([0-9a-fA-F]{1,4}:){1,4}:((25[0-5]|"
		"(2[0-4]|1{0,1}[0-9]){0,1}[0-9]).){3,3}(25[0-5]|(2[0-4]|"
		"1{0,1}[0-9]){0,1}[0-9]))"
	);
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ADataTypes::mValidate(_A_ENUMS_DATA_TYPE inType, QVariant inValue, QVariantMap inProperties) {

	QVariantMap oOutput;

	switch (inType) {
		case _A_ENUMS_DATA_TYPE::Boolean:
			oOutput = this->mValidateBoolean(inValue).mToVariantMap();
			break;
		case _A_ENUMS_DATA_TYPE::TrueBoolean:
			oOutput = this->mValidateTrueBoolean(inValue).mToVariantMap();
			break;
		case _A_ENUMS_DATA_TYPE::FalseBoolean:
			oOutput = this->mValidateFalseBoolean(inValue).mToVariantMap();
			break;
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
		case _A_ENUMS_DATA_TYPE::String:
			oOutput = this->mValidateString(inValue).mToVariantMap();
			break;
		case _A_ENUMS_DATA_TYPE::StringWithoutSymbols:
			oOutput = this->mValidateStringWithoutSymbols(
				inValue,
				qvariant_cast<QList<QString>>(inProperties.value("Symbols"))
			).mToVariantMap();
			break;
		case _A_ENUMS_DATA_TYPE::StringOfSize: {

				ADataStringSizeProperties oStringSizeProperties;
				oStringSizeProperties.Type = qvariant_cast<_A_ENUMS_DATA_STRING_SIZE_TYPE>(inProperties.value("SizeType"));
				oStringSizeProperties.Range1 = qvariant_cast<int>(inProperties.value("Range1"));
				oStringSizeProperties.Range2 = qvariant_cast<int>(inProperties.value("Range2"));

				int oSize = qvariant_cast<int>(inProperties.value("Size",-1));
				if (oSize < 0) oSize = 0;
				oStringSizeProperties.Size = oSize;

				oOutput = this->mValidateStringOfSize(inValue,oStringSizeProperties).mToVariantMap();
			};
			break;
		case _A_ENUMS_DATA_TYPE::StringByRegex:
			oOutput = this->mValidateStringByRegex(
				inValue,
				qvariant_cast<QString>(inProperties.value("Regex"))
			).mToVariantMap();
			break;
		case _A_ENUMS_DATA_TYPE::StringMd:
			oOutput = this->mValidateStringMd(inValue).mToVariantMap();
			break;
		case _A_ENUMS_DATA_TYPE::StringEmail:
			oOutput = this->mValidateStringEmail(inValue).mToVariantMap();
			break;
		case _A_ENUMS_DATA_TYPE::StringIPv4:
			oOutput = this->mValidateStringIPv4(inValue).mToVariantMap();
			break;
		case _A_ENUMS_DATA_TYPE::StringIPv6:
			oOutput = this->mValidateStringIPv6(inValue).mToVariantMap();
			break;
		default:
			break;
	}

	return oOutput;
}

