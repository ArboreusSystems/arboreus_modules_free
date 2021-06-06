// ----------------------------------------------------------
/*!
	\class ANetworkAgent
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 06/06/2021 at 14:00:54
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "anetworkagent.h"

// Namespace
using namespace ARB;


ANetworkAgent::ANetworkAgent(
	ANetworkRequestProperties inProperties,
	QNetworkAccessManager* inManager,
	QObject* parent
): QObject(parent) {

	pProperties = inProperties;
	pManager = inManager;

	_A_DEBUG << "ANetworkAgent created with properties";
}

// -----------
/*!
	\fn

	Doc.
*/

ANetworkAgent::ANetworkAgent(QObject *parent) : QObject(parent) {

	_A_DEBUG << "ANetworkAgent created";
}


// -----------
/*!
	\fn

	Doc.
*/

ANetworkAgent::~ANetworkAgent(void) {

	_A_DEBUG << "ANetworkAgent deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void ANetworkAgent::slPOST(void) {

	QNetworkRequest oRequest = this->mCreateRequest();
	QEventLoop oEventLoop;

	QNetworkReply* oReply = pManager->post(oRequest,pProperties.Data);
	QObject::connect(
		oReply,&QNetworkReply::finished,
		&oEventLoop,&QEventLoop::quit
	);
	oEventLoop.exec();

	if (oReply->error()) {
		_A_DEBUG << \
			"POST request failed for" << pProperties.URL.toStdString().c_str() << \
			"with error" << qPrintable(oReply->errorString());
	} else {
		pReply.Status = true;
		pReply.Data = oReply->readAll();
	}

	emit sgFinished();
	delete oReply;
}


// -----------
/*!
	\fn

	Doc.
*/

void ANetworkAgent::slGET(void) {

	QNetworkRequest oRequest = this->mCreateRequest();
	QEventLoop oEventLoop;

	QNetworkReply* oReply = pManager->get(oRequest);
	QObject::connect(
		oReply,&QNetworkReply::finished,
		&oEventLoop,&QEventLoop::quit
	);
	oEventLoop.exec();

	if (oReply->error()) {
		_A_DEBUG << \
			"GET request failed for" << pProperties.URL.toStdString().c_str() << \
			"with error" << qPrintable(oReply->errorString());
	} else {
		pReply.Status = true;
		pReply.Data = oReply->readAll();
	}

	emit sgFinished();
	delete oReply;
}


// -----------
/*!
	\fn

	Doc.
*/

QNetworkRequest ANetworkAgent::mCreateRequest(void) {

	QNetworkRequest oOutput;
	oOutput.setUrl(pProperties.URL);

	QMapIterator<QString,QString> oIterator(pProperties.Headers);
	while (oIterator.hasNext()) {
		oIterator.next();
		oOutput.setRawHeader(oIterator.key().toLocal8Bit(),oIterator.value().toLocal8Bit());
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantList ANetworkAgent::mGetHeaders(QNetworkReply* inReply) {

	QVariantList oOutput;
	foreach (QByteArray iHeader, inReply->rawHeaderList()) {
		QVariantMap oHeader;
		oHeader.insert("Header",QString(iHeader));
		oHeader.insert("Value",QString(inReply->rawHeader(iHeader)));
		oOutput.append(oHeader);
	}
	return oOutput;
}
