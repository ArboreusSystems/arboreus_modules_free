// ----------------------------------------------------------
/*!
    \class ADataValidateStructureAgent
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 27/06/2023 at 06:16:20
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "adatavalidatestructureagent.h"

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

ADataValidateStructureAgent::ADataValidateStructureAgent(QObject* parent) : AThreadAgentTemplate(parent) {

	_A_DEBUG << "ADataValidateStructureAgent created";
}


// -----------
/*!
	\fn

	Doc.
*/

ADataValidateStructureAgent::~ADataValidateStructureAgent(void) {

	_A_DEBUG << "ADataValidateStructureAgent deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void ADataValidateStructureAgent::mInit(
	ADataService* inService,_A_ENUMS_DATA_STRUCTURE_VALIDATION_TYPE inType,
	QVariant inModel,QVariant inStructure
) {

	pService = inService;
	pType = inType;
	pModel = inModel;
	pStructure = inStructure;

	_A_DEBUG << "ADataValidateStructureAgent initiated";
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidate ADataValidateStructureAgent::mReply(void) {

	return pReply;
}


// -----------
/*!
	\fn

	Doc.
*/

void ADataValidateStructureAgent::slRun(void) {

	pReply = pService->pStructures->mValidate(pType,pStructure,pModel);

	_A_DEBUG << "ADataValidateStructureAgent task finished";
	emit this->sgFinished();
}

