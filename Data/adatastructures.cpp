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

ADataReplyValidateStructure ADataStructures::mValidateFromMap(QVariantMap inStructure, QVariantMap inModel) {

	ADataReplyValidateStructure oOutput;

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
			oOutput.Data = iNextKey;
			return oOutput;
		}

		QVariant iNextValue = inStructure.value(iNextKey);
		QVariantMap iNextModel = qvariant_cast<QVariantMap>(inModel.value(iNextKey));

		ADataReplyValidateValue iNextValueValidateMap = pTypes->mValidate(
			qvariant_cast<_A_ENUMS_DATA_TYPE>(iNextModel.value("Type")),
			iNextValue,
			qvariant_cast<QVariantMap>(iNextModel.value("Properties"))
		);
		if (!iNextValueValidateMap.IsValid) {
			oOutput.Status = _A_ENUMS_DATA_REPLY_TYPE::NotValid;
			oOutput.Data = iNextKey;
			return oOutput;
		}
	}

	oOutput.Status = _A_ENUMS_DATA_REPLY_TYPE::Ok;
	oOutput.Data = inStructure;

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateStructure ADataStructures::mValidateFromList(QVariantList inStructure, QList<QVariantMap> inModel) {

	ADataReplyValidateStructure oOutput;

	int oSizeModel = inModel.size();
	if (oSizeModel) {
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

	_A_DEBUG << 1;

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateStructure ADataStructures::mValidate(
	_A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE inType,
	QVariant inStructure,
	QVariant inModel
) {

	ADataReplyValidateStructure oOutput;

	switch (inType) {
		case _A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE::FromMap: {
				oOutput = this->mValidateFromMap(
					qvariant_cast<QVariantMap>(inStructure),
					qvariant_cast<QVariantMap>(inModel)
				);
		}; break;
		case _A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE::FromList: {
				oOutput = this->mValidateFromList(
					qvariant_cast<QVariantList>(inStructure),
					qvariant_cast<QList<QVariantMap>>(inModel)
				);
		}; break;
		default: break;
	}

	return oOutput;
}

