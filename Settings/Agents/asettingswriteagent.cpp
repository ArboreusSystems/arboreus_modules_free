// ----------------------------------------------------------
/*!
    \class ASettingsWriteAgent
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 05/07/2023 at 17:55:33
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "asettingswriteagent.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ASettingsWriteAgent::ASettingsWriteAgent(
	ADBKeyValue* inDBKeyValue,
	QString inKey, QVariant inValue,
	QObject* parent
) : AThreadAgentTemplate(parent) {

	pDBKeyValue = inDBKeyValue;
	pKey = inKey;
	pValue = inValue;

	_A_DEBUG << "ASettingsWriteAgent created with properties";
}

// -----------
/*!
    \fn

    Doc.
*/

ASettingsWriteAgent::ASettingsWriteAgent(QObject* parent) : AThreadAgentTemplate(parent) {

	_A_DEBUG << "ASettingsWriteAgent created";
}


// -----------
/*!
	\fn

	Doc.
*/

ASettingsWriteAgent::~ASettingsWriteAgent(void) {

	_A_DEBUG << "ASettingsWriteAgent deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void ASettingsWriteAgent::slRun(void) {

	ADBKeyValueReply oReply = pDBKeyValue->mWrite(pKey,pValue);
	if (oReply.Status == _A_ENUMS_DB_KEY_VALUE_REPLY_STATUS::Ok) {
		pReply.Status = true;
	}

	emit this->sgFinished();
}

