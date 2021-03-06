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

	return pDB->mGetDBName();
}


// -----------
/*!
	\fn

	Doc.
*/

void ASettingsService::slInit(ASettingsProperties inProperties) {

	pSettingsConfig = qobject_cast<ASettingsConfig*>(inProperties.Config);
	pApplicationConfig = qobject_cast<AApplicationConfig*>(inProperties.Config);

	ADBSqliteCipherProperties oDBproperties;
	oDBproperties.Name = QString(_A_SETTINGS_DB_NAME);
	oDBproperties.Path = inProperties.Path + "/" + oDBproperties.Name + ".db";

	if (pSettingsConfig->ASettingsConfig_Encrypted()) {
		oDBproperties.Value = pApplicationConfig->AApplicationConfig_Registry_Value();
	}

	pDB = new ADBSqliteCipher(this);
	pDB->mStart(&oDBproperties);

	ADBSqliteReply oCreatingReply = pDB->mStringExecute(
		"CREATE TABLE IF NOT EXISTS settings "
		"(key STRING (25) PRIMARY KEY UNIQUE NOT NULL,value BLOB);"
	);
	if (!oCreatingReply.Status) {
		_A_CRITICAL << "Creating DB for settings failed";
	} else {
		_A_DEBUG << "DB for settings created";
	}

	_A_DEBUG << "ASettingsService initiated";

	emit sgInitiated();
}


// -----------
/*!
	\fn

	Doc.
*/

void ASettingsService::slUpdate(QString inKey, QVariant inValue) {

	QSqlQuery oQuery(pDB->mGetDB());
	if (!oQuery.prepare(
		"INSERT OR REPLACE INTO settings (key,value)"
		"VALUES (:key,:value);"
	)) {
		_A_CRITICAL << "Preraring query for writing in settings failed";
	}
	oQuery.bindValue(":key",inKey);
	oQuery.bindValue(":value",inValue);

	ADBSqliteReply oReply = pDB->mQueryTransaction(std::move(oQuery));
	if (!oReply.Status) {
		_A_CRITICAL << "Writing query in settings failed";
	} else {
		emit sgUpdated(inKey,inValue);
	}
}
