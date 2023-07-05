// ----------------------------------------------------------
/*!
	\class SSettingsService
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 02/05/2021 at 11:50:09
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "asettingsservice.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ASettingsService::ASettingsService(QObject* parent) : AThreadServiceTemplate(parent) {

	_A_DEBUG << "ASettingsService created";
}


// -----------
/*!
	\fn

	Doc.
*/

ASettingsService::~ASettingsService(void) {

	_A_DEBUG << "ASettingsService deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

QString ASettingsService::mGetDBName(void) {

	return pDBKeyValue->mGetDBName();
}


// -----------
/*!
	\fn

	Doc.
*/

void ASettingsService::slInit(ASettingsProperties inProperties) {

	pSettingsConfig = qobject_cast<ASettingsConfig*>(inProperties.Config);
	pApplicationConfig = qobject_cast<AApplicationConfig*>(inProperties.Config);

	pDBKeyValue = new ADBKeyValue(this);
	pDBKeyValue->pProperties = new ADBKeyValueProperties(pDBKeyValue);
	pDBKeyValue->pProperties->NameTable = pSettingsConfig->ASettingsConfig_TableName();
	pDBKeyValue->pProperties->Name = QString(_A_SETTINGS_DB_NAME);
	pDBKeyValue->pProperties->Path = inProperties.Path + "/" + pDBKeyValue->pProperties->Name + ".db";
	pDBKeyValue->pProperties->Encrypted = pSettingsConfig->ASettingsConfig_Encrypted();
	if (pDBKeyValue->pProperties->Encrypted) {
		pDBKeyValue->pProperties->Value = pApplicationConfig->AApplicationConfig_Registry_Value();
	}

	if (!pDBKeyValue->mInit()) {
		_A_CRITICAL << "Initiating settings failed when creatind DBKeyValue";
	} else {
		_A_DEBUG << "ASettingsService initiated";
	}

	emit sgInitiated();
}


// -----------
/*!
	\fn

	Doc.
*/

//void ASettingsService::slUpdate(QString inKey, QVariant inValue) {

//	QSqlQuery oQuery(pDB->mGetDB());
//	if (!oQuery.prepare(
//		"INSERT OR REPLACE INTO settings (key,value)"
//		"VALUES (:key,:value);"
//	)) {
//		_A_CRITICAL << "Preraring query for writing in settings failed";
//	}
//	oQuery.bindValue(":key",inKey);
//	oQuery.bindValue(":value",inValue);

//	ADBSqliteReply oReply = pDB->mQueryTransaction(std::move(oQuery));
//	if (!oReply.Status) {
//		_A_CRITICAL << "Writing query in settings failed";
//	} else {
//		emit sgUpdated(inKey,inValue);
//	}
//}
