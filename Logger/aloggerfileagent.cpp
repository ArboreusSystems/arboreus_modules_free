// ----------------------------------------------------------
/*!
	\class ALoggerFileAgent
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 03/08/2022 at 14:59:47
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "aloggerfileagent.h"

// Namespace
using namespace ARB;

// Global variables
extern FILE* gLoggerLogbookFile;


// -----------
/*!
	\fn

	Doc.
*/

ALoggerFileAgent::ALoggerFileAgent(QObject* parent) : QObject(parent) {

	_A_DEBUG << "ALoggerFileAgent created";
}


// -----------
/*!
	\fn

	Doc.
*/

ALoggerFileAgent::~ALoggerFileAgent(void) {

	_A_DEBUG << "ALoggerFileAgent deleleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void ALoggerFileAgent::mInit(ALoggerServiceProperties inProperties) {

	QString oFileName = "log_" + QString::number(QDateTime::currentMSecsSinceEpoch()) + ".txt";
	QString oPathFile = inProperties.PathLoggerFile + "/" + oFileName;

	if ((pFile = fopen(oPathFile.toStdString().c_str(),"a")) != NULL) {
		_A_DEBUG << "Logbook file initiated:" << oPathFile;
		gLoggerLogbookFile = pFile;
	} else {
		_A_CRITICAL << "Failed intiation of logbook file:" << oPathFile;
	}

	_A_DEBUG << "ALoggerFileAgent initiated";
}


// -----------
/*!
	\fn

	Doc.
*/

void ALoggerFileAgent::mWriteToLogbook(ALoggerMessageModel inMessageModel) {

	fLoggerMessageHandlerFile(pFile,inMessageModel);
}
