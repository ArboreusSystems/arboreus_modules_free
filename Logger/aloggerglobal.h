// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 28/04/2021 at 19:57:54
	\endlist
*/
// ----------------------------------------------------------
#ifndef ALOGGERGLOBAL_H
#define ALOGGERGLOBAL_H

// System includes

// Precompiled includes
#include <aloggerpch.h>

// Application includes
#include <aloggerdatamodels.h>
//#include <alogger.h>

// Constants and defintions
#define _A_LOGGER_DEFAULT_STRING_DEBUG "DBG"
#define _A_LOGGER_DEFAULT_STRING_INFO "INF"
#define _A_LOGGER_DEFAULT_STRING_WARNING "WRN"
#define _A_LOGGER_DEFAULT_STRING_CRITICAL "CRT"
#define _A_LOGGER_DEFAULT_STRING_FATAL "FTL"
#define _A_LOGGER_DEFAULT_STRING_UNDEFINED "NDF"
#define _A_LOGGER_DEFAULT_STRING_SYSTEM "SYS"
#define _A_LOGGER_DEFAULT_STRING_USER "USR"
#define _A_LOGGER_DEFAULT_STRING_NETWORK "NET"

#define _A_DEBUG qDebug()
#define _A_USER qDebug() << _A_LOGGER_DEFAULT_STRING_USER
#define _A_INFO qInfo()
#define _A_WARNING qWarning()
#define _A_CRITICAL qCritical()
#define _A_FATAL(inMessage) qFatal(inMessage)

#define _A_CONSOLE_DEBUG(inMessage) fLogger_MessageHandlerConsole( \
	QtMsgType::QtDebugMsg, \
	inMessage, \
	__LINE__, \
	__FILE__, \
	__FUNCTION__ \
)
#define _A_CONSOLE_INFO(inMessage) fLogger_MessageHandlerConsole( \
	QtMsgType::QtInfoMsg, \
	inMessage, \
	__LINE__, \
	__FILE__, \
	__FUNCTION__ \
)
#define _A_CONSOLE_WARNING(inMessage) fLogger_MessageHandlerConsole( \
	QtMsgType::QtWarningMsg, \
	inMessage, \
	__LINE__, \
	__FILE__, \
	__FUNCTION__ \
)
#define _A_CONSOLE_CRITICAL(inMessage) fLogger_MessageHandlerConsole( \
	QtMsgType::QtCriticalMsg, \
	inMessage, \
	__LINE__, \
	__FILE__, \
	__FUNCTION__ \
)

// Global variables
extern QList<ARB::ALoggerMessageModel> gLoggerMessageCache;
extern bool gLoggerIsInitiated;
extern bool gLoggerIsWriteToFileDirectly;
extern FILE* gLoggerLogbookFile;

// Global functions
void __attribute__((unused)) fLogger_WriteToLogbook(ARB::ALoggerMessageModel inModel);
void __attribute__((unused)) fLogger_Lifecycle_WillQuit(void);
void __attribute__((unused)) fLogger_Application_Exit(void);

// Namespace
namespace ARB {


// -----------
/*!
	\fn

	Doc.
*/

static void __attribute__((unused)) fLogger_WriteToConsole(ALoggerMessageModel* inModel) {

#ifdef QT_DEBUG

	switch (inModel->Type) {
		case QtDebugMsg:
			fprintf(stderr,"%s:%s %llu %s %s [%s]:[%s]:[%u]\n",
				_A_LOGGER_DEFAULT_STRING_DEBUG,inModel->Author,
				inModel->Time,inModel->ThreadID.constData(),
				inModel->Message.constData(),
				inModel->Function,inModel->File,inModel->Line
			);
			break;
		case QtInfoMsg:
			fprintf(stderr,"%s:%s %llu %s %s [%s]:[%s]:[%u]\n",
				_A_LOGGER_DEFAULT_STRING_INFO,inModel->Author,
				inModel->Time,inModel->ThreadID.constData(),
				inModel->Message.constData(),
				inModel->Function,inModel->File,inModel->Line
			);
			break;
		case QtWarningMsg:
			fprintf(stderr,"%s:%s %llu %s %s [%s]:[%s]:[%u]\n",
				_A_LOGGER_DEFAULT_STRING_WARNING,inModel->Author,
				inModel->Time,inModel->ThreadID.constData(),
				inModel->Message.constData(),
				inModel->Function,inModel->File,inModel->Line
			);
			break;
		case QtCriticalMsg:
			fprintf(stderr,"%s:%s %llu %s %s [%s]:[%s]:[%u]\n",
				_A_LOGGER_DEFAULT_STRING_CRITICAL,inModel->Author,
				inModel->Time,inModel->ThreadID.constData(),
				inModel->Message.constData(),
				inModel->Function,inModel->File,inModel->Line
			);
			break;
		case QtFatalMsg:
			fprintf(stderr,"%s:%s %llu %s %s [%s]:[%s]:[%u]\n",
				_A_LOGGER_DEFAULT_STRING_FATAL,inModel->Author,
				inModel->Time,inModel->ThreadID.constData(),
				inModel->Message.constData(),
				inModel->Function,inModel->File,inModel->Line
			);
			break;
		default:
			fprintf(stderr,"%s:%s %llu %s %s [%s]:[%s]:[%u]\n",
				_A_LOGGER_DEFAULT_STRING_UNDEFINED,inModel->Author,
				inModel->Time,inModel->ThreadID.constData(),
				inModel->Message.constData(),
				inModel->Function,inModel->File,inModel->Line
			);
			break;
	}

#else

	switch (inModel->Type) {
		case QtDebugMsg:
			break;
		case QtInfoMsg:
			fprintf(stderr,"%s:%s %llu %s %s\n",
				_A_LOGGER_DEFAULT_STRING_INFO,inModel->Author,
				inModel->Time,inModel->ThreadID.constData(),
				inModel->Message.constData()
			);
			break;
		case QtWarningMsg:
			fprintf(stderr,"%s:%s %llu %s %s\n",
				_A_LOGGER_DEFAULT_STRING_WARNING,inModel->Author,
				inModel->Time,inModel->ThreadID.constData(),
				inModel->Message.constData()
			);
			break;
		case QtCriticalMsg:
			fprintf(stderr,"%s:%s %llu %s %s\n",
				_A_LOGGER_DEFAULT_STRING_CRITICAL,inModel->Author,
				inModel->Time,inModel->ThreadID.constData(),
				inModel->Message.constData()
			);
			break;
		case QtFatalMsg:
			fprintf(stderr,"%s:%s %llu %s %s\n",
				_A_LOGGER_DEFAULT_STRING_FATAL,inModel->Author,
				inModel->Time,inModel->ThreadID.constData(),
				inModel->Message.constData()
			);
			break;
		default:
			fprintf(stderr,"%s:%s %llu %s %s\n",
				_A_LOGGER_DEFAULT_STRING_UNDEFINED,inModel->Author,
				inModel->Time,inModel->ThreadID.constData(),
				inModel->Message.constData()
			);
			break;
	}

#endif

}


// -----------
/*!
	\fn

	Doc.
*/

static void __attribute__((unused)) fLogger_MessageHandler(
	QtMsgType inType, const QMessageLogContext& inContext, const QString& inMessage
) {

	QString oThreadIDString = QString("0x%1");
	QString oThreadIDValue = oThreadIDString.arg((long)QThread::currentThread(),0,16);

	ALoggerMessageModel oMessageModel;
	oMessageModel.Type = inType;
	oMessageModel.Time = QDateTime::currentMSecsSinceEpoch();
	oMessageModel.ThreadID = oThreadIDValue.toUtf8();
	oMessageModel.Message = inMessage.toUtf8();

	QString oAuthorString = inMessage.left(3);
	std::string oAuthor = oAuthorString.toStdString();
	if (
		oAuthor == _A_LOGGER_DEFAULT_STRING_USER ||
		oAuthor == _A_LOGGER_DEFAULT_STRING_SYSTEM ||
		oAuthor == _A_LOGGER_DEFAULT_STRING_NETWORK
	) {
		oMessageModel.Author = oAuthor.c_str();
	} else {
		oMessageModel.Author = _A_LOGGER_DEFAULT_STRING_SYSTEM;
	}

#ifdef QT_DEBUG

	oMessageModel.File = inContext.file ? inContext.file : "no file";
	oMessageModel.Function = inContext.function ? inContext.function : "no function";
	oMessageModel.Line = inContext.line;

	fLogger_WriteToConsole(&oMessageModel);

	if (gLoggerIsInitiated) {
		fLogger_WriteToLogbook(oMessageModel);
	} else {
		gLoggerMessageCache.append(oMessageModel);
	}

#else

	Q_UNUSED(inContext);

	fLoggerWriteToConsole(&oMessageModel);
	fLoggerWriteToLogbook(&oMessageModel);


#endif

}


// -----------
/*!
	\fn

	Doc.
*/

static void __attribute__((unused)) fLogger_MessageHandlerFile(FILE* inFile,ALoggerMessageModel inMessageModel){

	const char* oType;
	switch (inMessageModel.Type) {
		case QtDebugMsg: oType = _A_LOGGER_DEFAULT_STRING_DEBUG; break;
		case QtInfoMsg: oType = _A_LOGGER_DEFAULT_STRING_INFO; break;
		case QtWarningMsg: oType = _A_LOGGER_DEFAULT_STRING_WARNING; break;
		case QtCriticalMsg: oType = _A_LOGGER_DEFAULT_STRING_CRITICAL; break;
		case QtFatalMsg: oType = _A_LOGGER_DEFAULT_STRING_FATAL; break;
		default: oType = _A_LOGGER_DEFAULT_STRING_UNDEFINED; break;
	}

	fprintf(inFile,"%s:%s %llu %s %s [%s]:[%s]:[%u]\n",
		oType,
		inMessageModel.Author,
		inMessageModel.Time,
		inMessageModel.ThreadID.constData(),
		inMessageModel.Message.constData(),
		inMessageModel.Function,
		inMessageModel.File,
		inMessageModel.Line
	);
	fflush(inFile);
}


// -----------
/*!
	\fn

	Doc.
*/

static void __attribute__((unused)) fLogger_MessageHandlerConsole(
	QtMsgType inType, QString inMessage, int inLine, const char* inFile, const char* inFunction
) {

#ifdef QT_DEBUG

	QString oThreadIDString = QString("0x%1");
	QString oThreadIDValue = oThreadIDString.arg((long)QThread::currentThread(),0,16);
	std::string oThreadIDStdString = oThreadIDValue.toStdString();

	std::string oMessageStdString = inMessage.toStdString();

	ALoggerMessageModel oMessageModel;
	oMessageModel.Type = inType;
	oMessageModel.Time = QDateTime::currentMSecsSinceEpoch();
	oMessageModel.ThreadID = oThreadIDValue.toUtf8();
	oMessageModel.Message = inMessage.toUtf8();
	oMessageModel.Author = _A_LOGGER_DEFAULT_STRING_SYSTEM;
	oMessageModel.File = inFile;
	oMessageModel.Function = inFunction;
	oMessageModel.Line = inLine;

	fLogger_WriteToConsole(&oMessageModel);

	gLoggerMessageCache.append(oMessageModel);

#endif
}

} // namespace ARB

#endif // ALOGGERGLOBAL_H
