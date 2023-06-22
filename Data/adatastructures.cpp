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


// -----------
/*!
	\fn

	Doc.
*/

ADataStructures::ADataStructures(ADataTypes* inTypes, QObject* parent) : QObject(parent) {

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

ADataStructureReply ADataStructures::mValidateFromMap(QVariantMap inStructure, QVariantMap inModel) {

	ADataStructureReply oOutput;

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ADataStructures::mValidate(
	_A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE inType,
	QVariant inStructure,
	QVariantMap inProperties
) {

	ADataStructureReply oOutput;

	switch (inType) {
		case _A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE::FromMap: {

			if (inStructure.userType() == QMetaType::QVariantMap) {
				oOutput = this->mValidateFromMap(
					qvariant_cast<QVariantMap>(inStructure),
					inProperties
				);
			}
		}; break;
		default:
			break;
	}

	return oOutput.mToVariantMap();
}

