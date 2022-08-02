// ----------------------------------------------------------
/*!
	\class ALoggerService
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 28/04/2021 at 19:52:08
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "aloggerservice.h"

// Namespace
using namespace ARB;

// Global variables
QList<ARB::ALoggerMessageModel> gLoggerMessageCache = {};
bool gLoggerIsInitiated = false;


// -----------
/*!
	\fn

	Doc.
*/

ALoggerService::ALoggerService(QObject* parent) : AThreadServiceTemplate(parent) {

	_A_DEBUG << "ALoggerService created";
}


// -----------
/*!
	\fn

	Doc.
*/

ALoggerService::~ALoggerService(void) {

	pDB->deleteLater();

	_A_DEBUG << "ALoggerService deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void ALoggerService::slInit(QString inPathLoggerData,QObject* inConfigObject) {

	pPathLoggerData = inPathLoggerData;
	pConfig = qobject_cast<ALoggerConfig*>(inConfigObject);

	ADBSqliteCipherProperties oDBProperties;
	oDBProperties.Name = "log_" + QString::number(QDateTime::currentMSecsSinceEpoch());
	oDBProperties.Path = pPathLoggerData + "/" + oDBProperties.Name + ".db";

	QString oQueryString = QString(
		"CREATE TABLE IF NOT EXISTS log ("
			"id INTEGER PRIMARY KEY AUTOINCREMENT,"
			"time INTEGER,"
			"type VARCHAR(3),"
			"threadID VARCHAR(24),"
			"author VARCHAR(100),"
			"message VARCHAR(255)"
		")"
	);

	pDB = new ADBSqliteCipher(this);
	if (pDB->mStart(&oDBProperties)) {
		ADBSqliteReply oDBReply = pDB->mStringExecute(oQueryString);
		if (!oDBReply.Status) _A_CRITICAL << "Creating table for logs failed";
	}

	this->mInitMessageCache();

	_A_DEBUG << "ALoggerService initiated";
	emit sgInitiated();
}


// -----------
/*!
	\fn

	Doc.
*/

void ALoggerService::slWriteToLogbook(ALoggerMessageModel* inMessageModel) {

	Q_UNUSED(inMessageModel);
}


// -----------
/*!
	\fn

	Doc.
*/

void ALoggerService::mInitMessageCache(void) {

	for (int i = 0; i < gLoggerMessageCache.length(); i++) {
		ALoggerMessageModel* iModel = const_cast<ALoggerMessageModel*>(
			&(gLoggerMessageCache.at(i))
		);
		this->slWriteToLogbook(iModel);
	}
	gLoggerMessageCache.clear();
}
