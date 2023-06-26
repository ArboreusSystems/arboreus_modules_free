// ----------------------------------------------------------
/*!
    \class ADataValidateValueAgent
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 26/06/2023 at 18:33:43
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "adatavalidatevalueagent.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ADataValidateValueAgent::ADataValidateValueAgent(QObject* parent) : AThreadAgentTemplate(parent) {

	_A_DEBUG << "ADataValidateValueAgent created";
}


// -----------
/*!
	\fn

	Doc.
*/

ADataValidateValueAgent::~ADataValidateValueAgent(void) {

	_A_DEBUG << "ADataValidateValueAgent deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void ADataValidateValueAgent::mInit(
	ADataService* inService, _A_ENUMS_DATA_TYPE inType,
	QVariant inValue, QVariantMap inProperties
) {

	pService = inService;
	pType = inType;
	pValue = inValue;
	pProperties = inProperties;

	_A_DEBUG << "ADataValidateValueAgent initiated";
}


// -----------
/*!
	\fn

	Doc.
*/

ADataReplyValidateValue ADataValidateValueAgent::mReply(void) {

	return pReply;
}


// -----------
/*!
	\fn

	Doc.
*/

void ADataValidateValueAgent::slRun(void) {

	pReply = pService->pValues->mValidate(pType,pValue,pProperties);

	_A_DEBUG << "ADataValidateValueAgent task finished";
	emit this->sgFinished();
}

