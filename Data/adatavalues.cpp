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
#include "adatavalues.h"

// Namespace
using namespace ARB;

// Forwarded classes
#include <adatastructures.h>


// -----------
/*!
	\fn

	Doc.
*/

ADataValues::ADataValues(ADataStructures* inStructures,QObject* parent) : QObject(parent) {

	pStructures = inStructures;

	_A_DEBUG << "ADataTypes created with structures";
}

// -----------
/*!
    \fn

    Doc.
*/

ADataValues::ADataValues(QObject* parent) : QObject(parent) {

	_A_DEBUG << "ADataTypes created";
}


// -----------
/*!
	\fn

	Doc.
*/

ADataValues::~ADataValues(void) {

	_A_DEBUG << "ADataTypes deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateValue ADataValues::mValidateBoolean(QVariant inValue) {

	ADataReplyValidateValue oOutput;

	if (inValue.userType() == QMetaType::Bool) {
		 oOutput.IsValid = true;
		 oOutput.Type = _A_ENUMS_DATA_TYPE::Boolean;
		 oOutput.Boolean = qvariant_cast<bool>(inValue);
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateValue ADataValues::mValidateTrueBoolean(QVariant inValue) {

	ADataReplyValidateValue oOutput;

	ADataReplyValidateValue oCheckboolean = this->mValidateBoolean(inValue);
	if (oCheckboolean.IsValid) {
		if (oCheckboolean.Boolean) oOutput = oCheckboolean;
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateValue ADataValues::mValidateFalseBoolean(QVariant inValue) {

	ADataReplyValidateValue oOutput;

	ADataReplyValidateValue oCheckboolean = this->mValidateBoolean(inValue);
	if (oCheckboolean.IsValid) {
		if (!oCheckboolean.Boolean) oOutput = oCheckboolean;
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateValue ADataValues::mValidateInteger(QVariant inValue) {

	ADataReplyValidateValue oOutput;

	if (inValue.userType() == QMetaType::Int) {
		 oOutput.IsValid = true;
		 oOutput.Type = _A_ENUMS_DATA_TYPE::Integer;
		 oOutput.Integer = qvariant_cast<int>(inValue);
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/


ADataReplyValidateValue ADataValues::mValidatePositiveInteger(QVariant inValue) {

	ADataReplyValidateValue oOutput;

	ADataReplyValidateValue oCheckInteger = this->mValidateInteger(inValue);
	if (oCheckInteger.IsValid) {
		if (oCheckInteger.Integer >= 0) {
			oOutput = oCheckInteger;
			oOutput.Type = _A_ENUMS_DATA_TYPE::PositiveInteger;
		}
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateValue ADataValues::mValidateNegativeInteger(QVariant inValue) {

	ADataReplyValidateValue oOutput;

	ADataReplyValidateValue oCheckInteger = this->mValidateInteger(inValue);
	if (oCheckInteger.IsValid) {
		if (oCheckInteger.Integer < 0) {
			oOutput = oCheckInteger;
			oOutput.Type = _A_ENUMS_DATA_TYPE::NegativeInteger;
		}
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateValue ADataValues::mValidateRangedInteger(QVariant inValue, int inRange1, int inRange2) {

	ADataReplyValidateValue oOutput;

	int oMax = 0;
	int oMin = 0;
	if (inRange1 > inRange2) {
		oMax = inRange1;
		oMin = inRange2;
	} else {
		oMax = inRange2;
		oMin = inRange1;
	}

	ADataReplyValidateValue oCheckInteger = this->mValidateInteger(inValue);
	if (oCheckInteger.IsValid) {
		if (oCheckInteger.Integer <= oMax && oCheckInteger.Integer >= oMin) {
			oOutput = oCheckInteger;
			oOutput.Type = _A_ENUMS_DATA_TYPE::RangedInteger;
		}
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateValue ADataValues::mValidateDouble(QVariant inValue) {

	ADataReplyValidateValue oOutput;

	if (inValue.userType() == QMetaType::Double) {
		 oOutput.IsValid = true;
		 oOutput.Type = _A_ENUMS_DATA_TYPE::Double;
		 oOutput.Double = qvariant_cast<double>(inValue);
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateValue ADataValues::mValidatePositiveDouble(QVariant inValue) {

	ADataReplyValidateValue oOutput;

	ADataReplyValidateValue oCheckFloat = this->mValidateDouble(inValue);
	if (oCheckFloat.IsValid) {
		if (oCheckFloat.Double >= 0) {
			oOutput = oCheckFloat;
			oOutput.Type = _A_ENUMS_DATA_TYPE::PositiveDouble;
		}
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateValue ADataValues::mValidateNegativeDouble(QVariant inValue) {

	ADataReplyValidateValue oOutput;

	ADataReplyValidateValue oCheckFloat = this->mValidateDouble(inValue);
	if (oCheckFloat.IsValid) {
		if (oCheckFloat.Double < 0) {
			oOutput = oCheckFloat;
			oOutput.Type = _A_ENUMS_DATA_TYPE::NegativeDouble;
		}
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateValue ADataValues::mValidateRangedDouble(QVariant inValue, double inRange1, double inRange2) {

	ADataReplyValidateValue oOutput;

	double oMax = 0;
	double oMin = 0;
	if (inRange1 > inRange2) {
		oMax = inRange1;
		oMin = inRange2;
	} else {
		oMax = inRange2;
		oMin = inRange1;
	}

	ADataReplyValidateValue oCheckFloat = this->mValidateDouble(inValue);
	if (oCheckFloat.IsValid) {
		if (oCheckFloat.Double <= oMax && oCheckFloat.Double >= oMin) {
			oOutput = oCheckFloat;
			oOutput.Type = _A_ENUMS_DATA_TYPE::RangedDouble;
		}
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateValue ADataValues::mValidateString(QVariant inValue) {

	ADataReplyValidateValue oOutput;

	if (inValue.userType() == QMetaType::QString) {
		 oOutput.IsValid = true;
		 oOutput.Type = _A_ENUMS_DATA_TYPE::String;
		 oOutput.String = qvariant_cast<QString>(inValue);
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateValue ADataValues::mValidateStringWithoutSymbols(QVariant inValue, QList<QString> inSymbols) {

	ADataReplyValidateValue oOutput;
	bool oContains = false;

	ADataReplyValidateValue oCheckString = this->mValidateString(inValue);
	if (oCheckString.IsValid) {
		QList<QString>::iterator iSymbol;
		for (iSymbol = inSymbols.begin(); iSymbol != inSymbols.end(); ++iSymbol) {
			if (oCheckString.String.contains(*iSymbol)) oContains = true;
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

ADataReplyValidateValue ADataValues::mValidateStringOfSize(QVariant inValue, ADataStringSizeProperties inProperties) {

	ADataReplyValidateValue oOutput;

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

	ADataReplyValidateValue oCheckString = this->mValidateString(inValue);
	if (oCheckString.IsValid) {
		oSize = oCheckString.String.size();
		oCheckString.Type = _A_ENUMS_DATA_TYPE::StringOfSize;
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

ADataReplyValidateValue ADataValues::mValidateStringByRegex(QVariant inValue, QString inRegex) {

	ADataReplyValidateValue oOutput;

	ADataReplyValidateValue oCheckString = this->mValidateString(inValue);
	if (oCheckString.IsValid) {

		QRegularExpression oExpression(inRegex);
		QRegularExpressionMatch oMatch = oExpression.match(oCheckString.String);
		if(oMatch.hasMatch()) {
			oOutput = oCheckString;
			oOutput.Type = _A_ENUMS_DATA_TYPE::StringByRegex;
		}
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateValue ADataValues::mValidateStringMd(QVariant inValue) {

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

ADataReplyValidateValue ADataValues::mValidateStringEmail(QVariant inValue) {

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

ADataReplyValidateValue ADataValues::mValidateStringIPv4(QVariant inValue) {

	ADataReplyValidateValue oOutput;
	int oIsValid = 0;

	ADataReplyValidateValue oCheckString = this->mValidateStringByRegex(
		inValue,
		"^[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}$"
	);
	if (oCheckString.IsValid) {
		QStringList oList = oCheckString.String.split(".");
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

ADataReplyValidateValue ADataValues::mValidateStringIPv6(QVariant inValue) {

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

ADataReplyValidateValue ADataValues::mValidate(_A_ENUMS_DATA_TYPE inType, QVariant inValue, QVariantMap inProperties) {

	ADataReplyValidateValue oOutput;

	switch (inType) {
		case _A_ENUMS_DATA_TYPE::Boolean:
			oOutput = this->mValidateBoolean(inValue);
			break;
		case _A_ENUMS_DATA_TYPE::TrueBoolean:
			oOutput = this->mValidateTrueBoolean(inValue);
			break;
		case _A_ENUMS_DATA_TYPE::FalseBoolean:
			oOutput = this->mValidateFalseBoolean(inValue);
			break;
		case _A_ENUMS_DATA_TYPE::Integer:
			oOutput = this->mValidateInteger(inValue);
			break;
		case _A_ENUMS_DATA_TYPE::PositiveInteger:
			oOutput = this->mValidatePositiveInteger(inValue);
			break;
		case _A_ENUMS_DATA_TYPE::NegativeInteger:
			oOutput = this->mValidateNegativeInteger(inValue);
			break;
		case _A_ENUMS_DATA_TYPE::RangedInteger:
			oOutput = this->mValidateRangedInteger(
				inValue,
				qvariant_cast<int>(inProperties.value("Range1")),
				qvariant_cast<int>(inProperties.value("Range2"))
			);
			break;
		case _A_ENUMS_DATA_TYPE::Double:
			oOutput = this->mValidateDouble(inValue);
			break;
		case _A_ENUMS_DATA_TYPE::PositiveDouble:
			oOutput = this->mValidatePositiveDouble(inValue);
			break;
		case _A_ENUMS_DATA_TYPE::NegativeDouble:
			oOutput = this->mValidateNegativeDouble(inValue);
			break;
		case _A_ENUMS_DATA_TYPE::RangedDouble:
			oOutput = this->mValidateRangedDouble(
				inValue,
				qvariant_cast<double>(inProperties.value("Range1")),
				qvariant_cast<double>(inProperties.value("Range2"))
			);
			break;
		case _A_ENUMS_DATA_TYPE::String:
			oOutput = this->mValidateString(inValue);
			break;
		case _A_ENUMS_DATA_TYPE::StringWithoutSymbols:
			oOutput = this->mValidateStringWithoutSymbols(
				inValue,
				qvariant_cast<QList<QString>>(inProperties.value("Symbols"))
			);
			break;
		case _A_ENUMS_DATA_TYPE::StringOfSize: {

				ADataStringSizeProperties oStringSizeProperties;
				oStringSizeProperties.Type = qvariant_cast<_A_ENUMS_DATA_STRING_SIZE_TYPE>(inProperties.value("SizeType"));
				oStringSizeProperties.Range1 = qvariant_cast<int>(inProperties.value("Range1"));
				oStringSizeProperties.Range2 = qvariant_cast<int>(inProperties.value("Range2"));

				int oSize = qvariant_cast<int>(inProperties.value("Size",-1));
				if (oSize < 0) oSize = 0;
				oStringSizeProperties.Size = oSize;

				oOutput = this->mValidateStringOfSize(inValue,oStringSizeProperties);
			};
			break;
		case _A_ENUMS_DATA_TYPE::StringByRegex:
			oOutput = this->mValidateStringByRegex(
				inValue,
				qvariant_cast<QString>(inProperties.value("Regex"))
			);
			break;
		case _A_ENUMS_DATA_TYPE::StringMd:
			oOutput = this->mValidateStringMd(inValue);
			break;
		case _A_ENUMS_DATA_TYPE::StringEmail:
			oOutput = this->mValidateStringEmail(inValue);
			break;
		case _A_ENUMS_DATA_TYPE::StringIPv4:
			oOutput = this->mValidateStringIPv4(inValue);
			break;
		case _A_ENUMS_DATA_TYPE::StringIPv6:
			oOutput = this->mValidateStringIPv6(inValue);
			break;
		default:
			break;
	}

	return oOutput;
}

