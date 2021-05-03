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

ASettingsAgent::ASettingsAgent(QString* inDbName, QObject* parent) : QObject(parent) {


}


// -----------
/*!
	\fn

	Doc.
*/

ASettingsAgent::ASettingsAgent(QObject *parent) : QObject(parent) {

}


// -----------
/*!
	\fn

	Doc.
*/

ASettingsAgent::~ASettingsAgent(void) {

}


// -----------
/*!
	\fn

	Doc.
*/

void ASettingsAgent::slGet(QString inSettingsID) {

	emit sgFinished();
}
