// ----------------------------------------------------------
/*!
    \class ADataStructure
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 16/06/2023 at 19:12:09
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "adatastructures.h"

// Namespace
using namespace ARB;

// Forwarded classes
#include <adatavalues.h>


// -----------
/*!
	\fn

	Doc.
*/

ADataStructures::ADataStructures(ADataValues* inTypes, QObject* parent) : QObject(parent) {

	if (inTypes) pTypes = inTypes;

	_A_DEBUG << "ADataStructures created with types";
}


// -----------
/*!
    \fn

    Doc.
*/

ADataStructures::ADataStructures(QObject* parent) : QObject(parent) {

	_A_DEBUG << "ADataStructures created";
}


// -----------
/*!
	\fn

	Doc.
*/

ADataStructures::~ADataStructures(void) {

	_A_DEBUG << "ADataStructures deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidate ADataStructures::mValidateFromMap(QVariantMap inStructure, QVariantMap inModel) {

	ADataReplyValidate oOutput;

	QList<QString> oKeysStructure = inStructure.keys();
	if (oKeysStructure.length() == 0) {
		oOutput.Status = _A_ENUMS_DATA_REPLY_TYPE::NoStructure;
		return oOutput;
	}

	QList<QString> oKeysModel = inModel.keys();
	if (oKeysModel.length() == 0) {
		oOutput.Status = _A_ENUMS_DATA_REPLY_TYPE::NoModel;
		return oOutput;
	}

	if (oKeysModel.length() != oKeysStructure.length()) {
		oOutput.Status = _A_ENUMS_DATA_REPLY_TYPE::WrongStructure;
		return oOutput;
	}

	QListIterator<QString> iKeysModel(oKeysModel);
	while (iKeysModel.hasNext()) {

		QString iNextKey = iKeysModel.next();

		if (!oKeysStructure.contains(iNextKey)) {
			oOutput.Status = _A_ENUMS_DATA_REPLY_TYPE::NoKey;
			oOutput.Message = iNextKey;
			return oOutput;
		}

		QVariant iNextValue = inStructure.value(iNextKey);
		QVariantMap iNextModel = qvariant_cast<QVariantMap>(inModel.value(iNextKey));
		_A_ENUMS_DATA_TYPE iType = qvariant_cast<_A_ENUMS_DATA_TYPE>(iNextModel.value("Type"));
		QVariantMap iProperties = qvariant_cast<QVariantMap>(iNextModel.value("Properties"));

		if (iType == _A_ENUMS_DATA_TYPE::Structure) {

			ADataReplyValidate iCheckStructure = this->mValidate(
				qvariant_cast<_A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE>(iProperties.value("Type")),
				iNextValue,
				iProperties.value("Model")
			);
			if (iCheckStructure.Status != _A_ENUMS_DATA_REPLY_TYPE::Ok) {
				oOutput.Status = iCheckStructure.Status;
				oOutput.Message = iNextKey + "/" + qvariant_cast<QString>(iCheckStructure.Message);
				return oOutput;
			}

		} else {

			ADataReplyValidate iNextValueValidateMap = pTypes->mValidate(iType,iNextValue,iProperties);
			if (iNextValueValidateMap.Status != _A_ENUMS_DATA_REPLY_TYPE::Ok) {
				oOutput.Status = iNextValueValidateMap.Status;
				oOutput.Message = iNextKey;
				return oOutput;
			}
		}
	}

	oOutput.Status = _A_ENUMS_DATA_REPLY_TYPE::Ok;
	oOutput.Type = _A_ENUMS_DATA_TYPE::Structure;
	oOutput.Structure = inStructure;

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidate ADataStructures::mValidateFromList(QVariantList inStructure, QVariantList inModel) {

	ADataReplyValidate oOutput;

	int oSizeModel = inModel.size();
	if (oSizeModel <= 0) {
		oOutput.Status = _A_ENUMS_DATA_REPLY_TYPE::NoModel;
		return oOutput;
	}

	int oSizeStructure = inStructure.size();
	if (oSizeStructure <= 0) {
		oOutput.Status = _A_ENUMS_DATA_REPLY_TYPE::NoStructure;
		return oOutput;
	}

	if (oSizeModel != oSizeStructure) {
		oOutput.Status = _A_ENUMS_DATA_REPLY_TYPE::WrongStructure;
		return oOutput;
	}

	for (int i = 0; i < oSizeModel; ++i) {

		QVariant iValue = inStructure[i];
		QVariantMap iTypeRule = qvariant_cast<QVariantMap>(inModel[i]);
		_A_ENUMS_DATA_TYPE iType = qvariant_cast<_A_ENUMS_DATA_TYPE>(iTypeRule.value("Type"));
		QVariantMap iProperties = qvariant_cast<QVariantMap>(iTypeRule.value("Properties",QVariantMap()));

		if (iType == _A_ENUMS_DATA_TYPE::Structure) {

			ADataReplyValidate iCheckStructure = this->mValidate(
				qvariant_cast<_A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE>(iProperties.value("Type")),
				iValue,
				qvariant_cast<QVariantList>(iProperties.value("Model"))
			);
			if (iCheckStructure.Status != _A_ENUMS_DATA_REPLY_TYPE::Ok) {
				oOutput.Status = iCheckStructure.Status;
				oOutput.Message = QString::number(i) + "/" + qvariant_cast<QString>(iCheckStructure.Message);
				return oOutput;
			}

		} else {

			ADataReplyValidate iCheckValue = this->pTypes->mValidate(
				iType,iValue,iProperties
			);
			if (iCheckValue.Status != _A_ENUMS_DATA_REPLY_TYPE::Ok) {
				oOutput.Status = _A_ENUMS_DATA_REPLY_TYPE::NotValid;
				oOutput.Message.setNum(i);
				return oOutput;
			}
		}
	}

	oOutput.Status = _A_ENUMS_DATA_REPLY_TYPE::Ok;
	oOutput.Type = _A_ENUMS_DATA_TYPE::Structure;
	oOutput.Structure = inStructure;

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidate ADataStructures::mValidate(
	_A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE inType,
	QVariant inStructure,
	QVariant inModel
) {

	ADataReplyValidate oOutput;

	switch (inType) {
		case _A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE::Map: {
			oOutput = this->mValidateFromMap(
				qvariant_cast<QVariantMap>(inStructure),
				qvariant_cast<QVariantMap>(inModel)
			);
		}; break;
		case _A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE::List: {
			oOutput = this->mValidateFromList(
				qvariant_cast<QVariantList>(inStructure),
				qvariant_cast<QVariantList>(inModel)
			);
		}; break;
		default: break;
	}

	return oOutput;
}

