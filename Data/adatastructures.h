// ----------------------------------------------------------
/*!
    \headerfile ADataStructure
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 16/06/2023 at 19:12:09
    \endlist
*/
// ----------------------------------------------------------

#ifndef ADATASTRUCTURES_H
#define ADATASTRUCTURES_H

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
class ADataValues;

// Class definitions
class ADataStructures : public QObject {

	public:

		explicit ADataStructures(ADataValues* inTypes, QObject* parent = nullptr);
		explicit ADataStructures(QObject* parent = nullptr);
		virtual ~ADataStructures(void);

		ADataReplyValidate mValidateFromMap(QVariantMap inStructure, QVariantMap inModel);
		ADataReplyValidate mValidateFromList(QVariantList inStructure, QVariantList inModel);
		ADataReplyValidate mValidate(
			_A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE inType,
			QVariant inStructure, QVariant inProperties
		);

	private:

		ADataValues* pTypes = nullptr;
};

} // namespace ARB

#endif // ADATASTRUCTURES_H
