// ----------------------------------------------------------
/*!
    \headerfile ADataValidateStructureAgent
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 27/06/2023 at 06:16:20
    \endlist
*/
// ----------------------------------------------------------

#ifndef ADATAVALIDATESTRUCTUREAGENT_H
#define ADATAVALIDATESTRUCTUREAGENT_H

// System includes

// Precompiled includes
#include <adatapch.h>

// Application includes
#include <aloggerglobal.h>
#include <athreadagenttemplate.h>
#include <adataservice.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADataValidateStructureAgent : public AThreadAgentTemplate {

	Q_OBJECT

	public:

		explicit ADataValidateStructureAgent(QObject* parent = nullptr);
		virtual ~ADataValidateStructureAgent(void);

		void mInit(
			ADataService* inService,_A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE inType,
			QVariant inModel,QVariant inStructure
		);
		ADataReplyValidateStructure mReply(void);

	public slots:

		void slRun(void);

	private:

		ADataService* pService = nullptr;
		_A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE pType = _A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE::Undefined;
		QVariant pModel = {};
		QVariant pStructure = {};
		ADataReplyValidateStructure pReply;
};

} // namespace ARB

#endif // ADATAVALIDATESTRUCTUREAGENT_H
