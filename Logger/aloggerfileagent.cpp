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

//	delete pFileTextStream;

//	if (pFile->isOpen()) pFile->close();
	fclose(pFile);
	delete pFile;

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

	const char* oType;
	switch (inMessageModel.Type) {
		case QtDebugMsg: oType = _A_LOGGER_DEFAULT_STRING_DEBUG; break;
		case QtInfoMsg: oType = _A_LOGGER_DEFAULT_STRING_INFO; break;
		case QtWarningMsg: oType = _A_LOGGER_DEFAULT_STRING_WARNING; break;
		case QtCriticalMsg: oType = _A_LOGGER_DEFAULT_STRING_CRITICAL; break;
		case QtFatalMsg: oType = _A_LOGGER_DEFAULT_STRING_FATAL; break;
		default: oType = _A_LOGGER_DEFAULT_STRING_UNDEFINED; break;
	}

	fprintf(pFile,"%s:%s %llu %s %s [%s]:[%s]:[%u]\n",
		oType,
		inMessageModel.Author,
		inMessageModel.Time,
		inMessageModel.ThreadID.constData(),
		inMessageModel.Message.constData(),
		inMessageModel.Function,
		inMessageModel.File,
		inMessageModel.Line
	);
	fflush(pFile);
}
