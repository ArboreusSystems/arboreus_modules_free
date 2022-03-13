// ----------------------------------------------------------
/*!
	\class AUsers
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 27/02/2022 at 15:10:11
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "ausershandler.h"

// Forwarded classes
#include <abackend.h>

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandler::AUsersHandler(QObject* parent)
: AThreadTemplate<AUsersHandlerService>(new AUsersHandlerService,parent) {

	QObject::connect(
		this,&AUsersHandler::sgInit,
		this->mService(),&AUsersHandlerService::slInit
	);
	QObject::connect(
		this->mService(),&AUsersHandlerService::sgInitiated,
		this,&AUsersHandler::slInitiated
	);

	_A_DEBUG << "AUsersHandler created";
}


// -----------
/*!
	\fn

	Doc.
*/

AUsersHandler::~AUsersHandler(void) {

	_A_DEBUG << "AUsersHandler deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersHandler::mInit(void) {

	pBackend = &ABackend::mInstance();
	pConfig = qobject_cast<AUsersHandlerConfig*>(pBackend->pApplicationConfigObject);
	pDBSchema = pConfig->AUsersHandlerConfig_DBTableProperties().Schema;
	pObjects = new AUsersHandlerObjects(pBackend,this);

	AUsersHandlerProperties oProperties;
	oProperties.PathCache = pBackend->pProperties->mGetPathDataCache();
	oProperties.PathApplication = pBackend->pProperties->mGetPathDataApplication();
	oProperties.Config = pBackend->pApplicationConfigObject;

	emit sgInit(oProperties);
}


// -----------
/*!
	\fn

	Doc.
*/

QList<ADBFieldProperties> AUsersHandler::mDBSchema(void) {

	return pDBSchema;
}


// -----------
/*!
	\fn

	Doc.
*/

QList<QVariantList> AUsersHandler::mAll(void) {

	QList<QVariantList> oOutput;
	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ADBSqliteReply AUsersHandler::mCreate(ASqlInsertIntoProperties inProperties) {

	_A_DEBUG << "!!!!!!!!!!!!!!" << inProperties.Data;
	_A_DEBUG << "!!!!!!!!!!!!!!" << inProperties.TableName;

	ADBSqliteReply oReply;
	return oReply;
}


// -----------
/*!
	\fn

	Doc.
*/

ADBSqliteReply AUsersHandler::mRead(QString inID) {

	Q_UNUSED(inID)

	ADBSqliteReply oReply;
	return oReply;
}


// -----------
/*!
	\fn

	Doc.
*/

ADBSqliteReply AUsersHandler::mUpdate(ASqlInsertIntoProperties inProperties) {

	Q_UNUSED(inProperties)

	ADBSqliteReply oReply;
	return oReply;
}


// -----------
/*!
	\fn

	Doc.
*/

ADBSqliteReply AUsersHandler::mDelete(QString inID) {

	Q_UNUSED(inID)

	ADBSqliteReply oReply;
	return oReply;
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantList AUsersHandler::mGetDBSchema(void) {

	QVariantList oOutput;

	for (int i = 0; i < pDBSchema.length(); i++) {
		QVariantMap iField;
		iField.insert("Name",pDBSchema[i].Name);
		iField.insert("UserName",pDBSchema[i].UserName);
		oOutput.append(iField);
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantList AUsersHandler::mGetAll(void) {

	QVariantList oOutput;
	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsersHandler::slInitiated(void) {

	_A_DEBUG << "AUsers initiated";

	emit sgInitiated();
}

