// ----------------------------------------------------------
/*!
    \class ASettingsReadAgent
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 05/07/2023 at 18:40:37
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "asettingsreadagent.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ASettingsReadAgent::ASettingsReadAgent(
	ADBKeyValue* inDBKeyValue,
	QString inKey,
	QObject* parent
) : AThreadAgentTemplate(parent) {

	pDBKeyValue = inDBKeyValue;
	pKey = inKey;

	_A_DEBUG << "ASettingsReadAgent created with properties";
}


// -----------
/*!
    \fn

    Doc.
*/

ASettingsReadAgent::ASettingsReadAgent(QObject* parent) : AThreadAgentTemplate(parent) {

	_A_DEBUG << "ASettingsReadAgent created";
}


// -----------
/*!
	\fn

	Doc.
*/

ASettingsReadAgent::~ASettingsReadAgent(void) {

	_A_DEBUG << "ASettingsReadAgent created";
}


// -----------
/*!
	\fn

	Doc.
*/

void ASettingsReadAgent::slRun(void) {

	ADBKeyValueReply oReply = pDBKeyValue->mRead(pKey);
	pReply.Status = oReply.Status;
	pReply.Data = oReply.Data;

	emit this->sgFinished();
}

