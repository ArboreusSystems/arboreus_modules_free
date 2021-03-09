// ----------------------------------------------------------
/*!
	\class ALoggerService
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 01/03/2021 at 15:21:57
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

ALoggerService::ALoggerService(QObject *parent) : QObject(parent) {

	A_CONSOLE_MESSAGE_DEBUG("ALoggerService created");
}


// -----------
/*!
	\fn

	Doc.
*/

ALoggerService::~ALoggerService(void) {

	A_CONSOLE_MESSAGE_DEBUG("ALoggerService deleted");
}


// -----------
/*!
	\fn

	Doc.
*/

void ALoggerService::slWriteToLog(ALoggerMessageModel* inMessage) {

	this->mWriteToDB(inMessage);

#ifdef QT_DEBUG

	fLoggerWriteToConsole(
		inMessage->Time,
		inMessage->Type.toStdString().c_str(),
		inMessage->Actor.toStdString().c_str(),
		inMessage->Message.toStdString().c_str(),
		inMessage->File.toStdString().c_str(),
		inMessage->Line.toInt(),
		inMessage->Function.toStdString().c_str()
	);

#endif

	emit sgLogUpdated();
}


// -----------
/*!
	\fn

	Doc.
*/

void ALoggerService::mWriteToDB(ALoggerMessageModel* inMessage) {

	Q_UNUSED(inMessage);
}


// -----------
/*!
	\fn

	Doc.
*/

void ALoggerService::slStartDB(ASqlCipherProperties* inProperties) {

	qDebug() << "ThreadID LoggerService:" << QThread::currentThreadId();
	qDebug() << QThread::currentThreadId() << "inProperties->Name:" << inProperties->Name;
	qDebug() << QThread::currentThreadId() << "inProperties->Path:" << inProperties->Path;
	qDebug() << QThread::currentThreadId() << "inProperties->Value:" << inProperties->Value;

	A_CONSOLE_MESSAGE_DEBUG("DB for Logger started");
}
