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

void ALoggerService::mWriteToConsole(
	uint64_t inTime, const char* inType, const char* inActor,
	const char* inMessage,
	const char* inFile,int inLine,const char* inFunction
) {

#ifdef QT_DEBUG

	std::string oType = "[" + std::string(inType) + "]:[" + std::string(inActor) +"]";
	std::string oInfo = "[" + std::string(inFile) + "]:[" + std::to_string(inLine) + "]:[" + std::string(inFunction) + "]";
	qDebug() <<	inTime << oType.c_str() << inMessage << oInfo.c_str();

#else

	Q_UNUSED(inTime);
	Q_UNUSED(inType);
	Q_UNUSED(inActor);
	Q_UNUSED(inMessage);
	Q_UNUSED(inFile);
	Q_UNUSED(inLine);
	Q_UNUSED(inFunction);

#endif
}


// -----------
/*!
	\fn

	Doc.
*/

void ALoggerService::mWriteToConsole(
	uint64_t inTime, const char* inType, const char* inActor,
	const char* inMessage
) {

	std::string oType = "[" + std::string(inType) + "]:[" + std::string(inActor) +"]";
	qDebug() <<	inTime << oType.c_str() << inMessage;

}


// -----------
/*!
	\fn

	Doc.
*/

void ALoggerService::slWriteToLog(ALoggerMessageModel* inMessage) {

	this->mWriteToDB(inMessage);

#ifdef QT_DEBUG

	ALoggerService::mWriteToConsole(
		inMessage->Time,
		inMessage->Type.toStdString().c_str(),
		inMessage->Actor.toStdString().c_str(),
		inMessage->Message.toStdString().c_str(),
		inMessage->File.toStdString().c_str(),
		inMessage->Line.toInt(),
		inMessage->Function.toStdString().c_str()
	);

#else

	ALoggerService::mWriteToConsole(
		inMessage->Time,
		inMessage->Type.toStdString().c_str(),
		inMessage->Actor.toStdString().c_str(),
		inMessage->Message.toStdString().c_str()
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
