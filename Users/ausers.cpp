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
#include "ausers.h"

// Forwarded classes
#include <abackend.h>

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AUsers::AUsers(QObject* parent) : AThreadTemplate<AUsersService>(new AUsersService,parent) {

	QObject::connect(
		this,&AUsers::sgInit,
		this->mService(),&AUsersService::slInit
	);
	QObject::connect(
		this->mService(),&AUsersService::sgInitiated,
		this,&AUsers::slInitiated
	);

	_A_DEBUG << "AUsers created";
}


// -----------
/*!
	\fn

	Doc.
*/

AUsers::~AUsers(void) {

	_A_DEBUG << "AUsers deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AUsers::mInit(void) {

	pBackend = &ABackend::mInstance();
	pConfig = qobject_cast<AUsersConfig*>(pBackend->pApplicationConfig);
	pDBSchema = pConfig->AUsersConfig_DBTableProperties().Schema;

	AUsersModuleProperties oProperties;
	oProperties.PathCache = pBackend->pProperties->mGetPathDataCache();
	oProperties.PathApplication = pBackend->pProperties->mGetPathDataApplication();
	oProperties.Config = pConfig;

	emit sgInit(oProperties);
}


// -----------
/*!
	\fn

	Doc.
*/

QList<ADBFieldProperties> AUsers::mDBSchema(void) {

	return pDBSchema;
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantList AUsers::mGetDBSchema(void) {

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

void AUsers::slInitiated(void) {

	_A_DEBUG << "AUsers initiated";

	emit sgInitiated();
}

