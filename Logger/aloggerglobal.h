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
#include <QObject>
#include <QDateTime>
#include <QDebug>
#include <QThread>
#include <string>
#include <sstream>

// Application includes

// Constants and defintions
#define _A_LOGGER_DEFAULT_STRING_DEBUG "DBG"
#define _A_LOGGER_DEFAULT_STRING_INFO "INF"
#define _A_LOGGER_DEFAULT_STRING_WARNING "WRN"
#define _A_LOGGER_DEFAULT_STRING_CRITICAL "CRT"
#define _A_LOGGER_DEFAULT_STRING_FATAL "FTL"
#define _A_LOGGER_DEFAULT_STRING_UNDEFINED "NDF"
#define _A_LOGGER_DEFAULT_STRING_SYSTEM "SYS"
#define _A_LOGGER_DEFAULT_STRING_QML "QML"
#define _A_LOGGER_DEFAULT_STRING_USER "USR"

#define _A_DEBUG qDebug()
#define _A_USER qDebug() << _A_LOGGER_DEFAULT_STRING_USER
#define _A_INFO qInfo()
#define _A_WARNING qWarning()
#define _A_CRITICAL qCritical()
#define _A_FATAL(inMessage) qFatal(inMessage)

// Namespace
namespace ARB {


// -----------
/*!
	\fn

	Doc.
*/

static void __attribute__((unused)) fLoggerMessageHandler(
	QtMsgType inType, const QMessageLogContext& inContext, const QString& inMessage
) {

	QString oThreadIDString = QString("0x%1");
	QString oThreadIDValue = oThreadIDString.arg((long)QThread::currentThread(),16);
	const char* oThreadID = oThreadIDValue.toStdString().c_str();
	const char* oFunction = inContext.function ? inContext.function : "no function";
	const char* oFile = inContext.file ? inContext.file : "no file";
	unsigned long long oTime = QDateTime::currentMSecsSinceEpoch();

#ifdef QT_DEBUG

	switch (inType) {
		case QtDebugMsg:
			fprintf(stderr,"%s %llu %s %s [%s]:[%s]:[%u]\n",
				_A_LOGGER_DEFAULT_STRING_DEBUG,
				oTime,oThreadID,inMessage.toStdString().c_str(),
				oFunction,oFile,inContext.line
			);
			break;
		case QtInfoMsg:
			fprintf(stderr,"%s %llu %s %s [%s]:[%s]:[%u]\n",
				_A_LOGGER_DEFAULT_STRING_INFO,
				oTime,oThreadID,inMessage.toStdString().c_str(),
				oFunction,oFile,inContext.line
			);
			break;
		case QtWarningMsg:
			fprintf(stderr,"%s %llu %s %s [%s]:[%s]:[%u]\n",
				_A_LOGGER_DEFAULT_STRING_WARNING,
				oTime,oThreadID,inMessage.toStdString().c_str(),
				oFunction,oFile,inContext.line
			);
			break;
		case QtCriticalMsg:
			fprintf(stderr,"%s %llu %s %s [%s]:[%s]:[%u]\n",
				_A_LOGGER_DEFAULT_STRING_CRITICAL,
				oTime,oThreadID,inMessage.toStdString().c_str(),
				oFunction,oFile,inContext.line
			);
			break;
		case QtFatalMsg:
			fprintf(stderr,"%s %llu %s %s [%s]:[%s]:[%u]\n",
				_A_LOGGER_DEFAULT_STRING_FATAL,
				oTime,oThreadID,inMessage.toStdString().c_str(),
				oFunction,oFile,inContext.line
			);
			break;
		default:
			fprintf(stderr,"%s %llu %s %s [%s]:[%s]:[%u]\n",
				_A_LOGGER_DEFAULT_STRING_UNDEFINED,
				oTime,oThreadID,inMessage.toStdString().c_str(),
				oFunction,oFile,inContext.line
			);
			break;
	}

#elif

	switch (inType) {
		case QtDebugMsg:
			break;
		case QtInfoMsg:
			fprintf(stderr,"%s %llu %s %s\n",
				_A_LOGGER_DEFAULT_STRING_INFO,
				oTime,oThreadID,inMessage.toStdString().c_str()
			);
			break;
		case QtWarningMsg:
			fprintf(stderr,"%s %llu %s %s\n",
				_A_LOGGER_DEFAULT_STRING_WARNING,
				oTime,oThreadID,inMessage.toStdString().c_str()
			);
			break;
		case QtCriticalMsg:
			fprintf(stderr,"%s %llu %s %s\n",
				_A_LOGGER_DEFAULT_STRING_CRITICAL,
				oTime,oThreadID,inMessage.toStdString().c_str()
			);
			break;
		case QtFatalMsg:
			fprintf(stderr,"%s %llu %s %s\n",
				_A_LOGGER_DEFAULT_STRING_FATAL,
				oTime,oThreadID,inMessage.toStdString().c_str()
			);
			break;
		default:
			fprintf(stderr,"%s %llu %s %s\n",
				_A_LOGGER_DEFAULT_STRING_UNDEFINED,
				oTime,oThreadID,inMessage.toStdString().c_str()
			);
			break;
	}

#endif

}

} // namespace ARB

#endif // ALOGGERGLOBAL_H
