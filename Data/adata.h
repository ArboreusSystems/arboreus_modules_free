// ----------------------------------------------------------
/*!
    \headerfile AData
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 16/06/2023 at 19:48:12
    \endlist
*/
// ----------------------------------------------------------

#ifndef ADATA_H
#define ADATA_H

// System includes

// Precompiled includes
#include <adatapch.h>

// Application includes
#include <athreadtemplate.h>
#include <athreadobjectcontrollertemplate.h>
#include <aloggerglobal.h>
#include <adataservice.h>
#include <adatavalidatevalueagent.h>
#include <adatavalidatestructureagent.h>

// Constants and definitions

// Namespace
namespace ARB {

// Classes
class ABackend;

// Class definitions
class AData : public AThreadTemplate<ADataService> {

	Q_OBJECT

	public:

		explicit AData(QObject* parent = nullptr);
		virtual ~AData(void);
		Q_DISABLE_COPY(AData)

		void mInit(void);
		ADataReplyValidate mValidateValueHandler(
			_A_ENUMS_DATA_TYPE inType,QVariant inValue,QVariantMap inProperties
		);
		ADataReplyValidate mValidateStructureHandler(
			_A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE inType,
			QVariant inModel,QVariant inStructure
		);
		ADataReplyValidate mValidateListHandler(void);

	public slots:

		void slInitiated(void);

		QVariantMap mValidateValue(
			_A_ENUMS_DATA_TYPE inType,QVariant inValue,QVariantMap inProperties = {}
		);
		QVariantMap mValidateStructure(
			_A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE inType,
			QVariant inModel,QVariant inStructure
		);
		QVariantMap mValidateList(
			QVariantMap inModel,QVariantList inList,QVariantMap inProperties = {}
		);

	signals:

		void sgInit(void);
		void sgInitiated(void);

	private:

		ABackend* pBackend = nullptr;
};

} // namespace ARB

#endif // ADATA_H
