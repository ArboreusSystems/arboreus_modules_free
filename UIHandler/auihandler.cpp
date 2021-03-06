// ----------------------------------------------------------
/*!
	\class AUIHandler
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 08/05/2021 at 15:08:35
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "auihandler.h"

// Forwarded classes
#include <abackend.h>

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AUIHandler::AUIHandler(QObject* parent) : QObject(parent) {

	_A_DEBUG << "AUIHandler created";
}


// -----------
/*!
	\fn

	Doc.
*/

AUIHandler::~AUIHandler(void) {

	_A_DEBUG << "AUIHandler deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AUIHandler::mInit(void) {

	pBackend = &ABackend::mInstance();

	pConfig = new AUIConfig(this);
	pConfig->mInit(qobject_cast<AUIHandlerConfig*>(pBackend->pGlobalConfigObject));

	pFonts = new AFonts(this);
	pFonts->mInit(pConfig->mFonts());

	pColors = new AColors(this);
	pColors->mInit(pConfig->mColors());

	pSignals = new AUISignals(this);
	pSignals->mInit();

	_A_DEBUG << "AUIHandler initiated";

	emit sgInitiated();
}


// -----------
/*!
	\fn

	Doc.
*/

QString AUIHandler::mComponentContent(QString inName) {

	return this->mComponentString(pConfig->mQMLImport(),inName);
}


// -----------
/*!
	\fn

	Doc.
*/

QString AUIHandler::mComponentString(QString inImport, QString inName) {

	QString oOutput = QString(A_UI_IMPORT_QT_QUICK) + inImport + inName + " {}";
	return oOutput;
}

