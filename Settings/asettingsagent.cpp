// ----------------------------------------------------------
/*!
	\class ASettingsAgent
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 03/05/2021 at 19:30:45
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "asettingsagent.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ASettingsAgent::ASettingsAgent(
	ASettingsService* inService, QString inKey,
	QVariant inValue, QObject* parent
) : QObject(parent) {

	pKey = inKey;
	pValue = inValue;
	pService = inService;

	_A_DEBUG << "ASettingsAgent created for:" << inKey;
}


// -----------
/*!
	\fn

	Doc.
*/

ASettingsAgent::ASettingsAgent(QObject* parent) : QObject(parent) {

	_A_DEBUG << "ASettingsAgent created";
}


// -----------
/*!
	\fn

	Doc.
*/

ASettingsAgent::~ASettingsAgent(void) {

	_A_DEBUG << "ASettingsAgent deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void ASettingsAgent::slGet(void) {

	ADBSqlCipherReply oDbReply = pService->pDB->mStringExecute(
		"SELECT value FROM settings WHERE key='" + pKey + "';"
	);
	if (oDbReply.Status) {
		if (oDbReply.Output.length() != 0) {
			pReply.Status = true;
			QVariantList oReplyData = qvariant_cast<QVariantList>(oDbReply.Output[0]);
			pReply.Data = oReplyData[0];
		}
	}

	emit sgFinished();
}
