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

void ALoggerService::slInit(QString inPathLoggerData) {

	pPathLoggerData = inPathLoggerData;

	ADBSqlCipherProperties* oDBProperties = new ADBSqlCipherProperties(this);
	oDBProperties->Name = "log_" + QString::number(QDateTime::currentMSecsSinceEpoch());
	oDBProperties->Path = pPathLoggerData + "/" + oDBProperties->Name + ".db";

	pDB = new ADBSqlCipher(this);
	pDB->mStart(oDBProperties);

	_A_DEBUG << "ALoggerService initiated";
}


// -----------
/*!
	\fn

	Doc.
*/

void ALoggerService::slWriteToDB(ALoggerMessageModel* inMessageModel) {


}
