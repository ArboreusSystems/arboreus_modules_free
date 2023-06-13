// ----------------------------------------------------------
/*!
	\class AJson
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 23/07/2021 at 19:31:23
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "ajson.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AJson::AJson(QObject* parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

AJson::~AJson(void) {}


// -----------
/*!
	\fn

	Doc.
*/

bool AJson::mToBase64FileFromObject(QString inPath, QJsonObject inObject) {

	return mToBase64FileFromDocument(
		inPath,QJsonDocument(inObject)
	);
}


// -----------
/*!
	\fn

	Doc.
*/

bool AJson::mToBase64FileFromMap(QString inPath, QVariantMap inMap) {

	return mToBase64FileFromDocument(
		inPath,QJsonDocument(QJsonObject::fromVariantMap(inMap))
	);
}


// -----------
/*!
	\fn

	Doc.
*/

bool AJson::mToBase64FileFromHash(QString inPath, QVariantHash inHash) {

	return mToBase64FileFromDocument(
		inPath,QJsonDocument(QJsonObject::fromVariantHash(inHash))
	);
}


// -----------
/*!
	\fn

	Doc.
*/

bool AJson::mToBase64FileFromDocument(QString inPath, QJsonDocument inDocument) {

	QFile oFile(inPath);
	if (!oFile.open(QFile::WriteOnly)) {
		return false;
	}
	if (oFile.write(inDocument.toJson().toBase64()) >= 0) {
		oFile.close();
		return true;
	}
	return false;
}


// -----------
/*!
	\fn

	Doc.
*/

AJsonFileReply AJson::mFromBase64File(QString inPath) {

	AJsonFileReply oReply = {};

	QFile oJSONFile(inPath);
	if (!oJSONFile.exists()) {
		return oReply;
	}
	if (!oJSONFile.open(QIODevice::ReadOnly|QIODevice::Text)) {
		return oReply;
	}

	QJsonParseError oJSONParseError;
	QJsonDocument oJSONDocument = QJsonDocument::fromJson(
		QByteArray::fromBase64(oJSONFile.readAll()),&oJSONParseError
	);
	if (oJSONDocument.isNull()) {
		return oReply;
	}
	oJSONFile.close();

	oReply.Status = _A_ENUMS_APPLICATION_REPLY_STATUS::Ok;
	oReply.Json = oJSONDocument.object();
	return oReply;
}


// -----------
/*!
	\fn bool AJson::mTofileFromObject(QString inPath, QJsonObject inObject)

	Write JSON to file from QJsonObject object.
*/

bool AJson::mToFileFromObject(QString inPath, QJsonObject inObject) {

	return mToFileFromDocument(
		inPath,QJsonDocument(inObject)
	);
}


// -----------
/*!
	\fn bool AJson::mToFileFromMap(QString inPath, QVariantMap inMap)

	Write JSON to file from QVariantMap object.
*/

bool AJson::mToFileFromMap(QString inPath, QVariantMap inMap) {

	return mToFileFromDocument(
		inPath,QJsonDocument(QJsonObject::fromVariantMap(inMap))
	);
}


// -----------
/*!
	\fn bool AJson::mToFileFromHash(QString inPath, QVariantHash inHash)

	Write JSON to file from QVariantHash object.
*/

bool AJson::mToFileFromHash(QString inPath, QVariantHash inHash) {

	return mToFileFromDocument(
		inPath,QJsonDocument(QJsonObject::fromVariantHash(inHash))
	);
}


// -----------
/*!
	\fn bool AJson::mToFileFromDocument(QString inPath, QJsonDocument inDocument)

	Write JSON to file from QJsonDocument object.
*/

bool AJson::mToFileFromDocument(QString inPath, QJsonDocument inDocument) {

	QFile oFile(inPath);
	if (!oFile.open(QFile::WriteOnly)) {
		return false;
	}
	if (oFile.write(inDocument.toJson()) >= 0) {
		oFile.close();
		return true;
	}
	return false;
}


// -----------
/*!
	\fn AJsonFileReply AJson::mFromFile(QString inPath)

	Read JSON from file.
*/

AJsonFileReply AJson::mFromFile(QString inPath) {

	AJsonFileReply oReply = {};

	QFile oJSONFile(inPath);
	if (!oJSONFile.exists()) {
		return oReply;
	}
	if (!oJSONFile.open(QIODevice::ReadOnly|QIODevice::Text)) {
		return oReply;
	}

	QJsonParseError oJSONParseError;
	QJsonDocument oJSONDocument = QJsonDocument::fromJson(
		oJSONFile.readAll(),&oJSONParseError
	);
	if (oJSONDocument.isNull()) {
		return oReply;
	}
	oJSONFile.close();

	oReply.Status = _A_ENUMS_APPLICATION_REPLY_STATUS::Ok;
	oReply.Json = oJSONDocument.object();
	return oReply;
}


// -----------
/*!
	\fn

	Doc
*/

bool AJson::mEncodeFromString(QString inValue, QString inPath, QString inString) {

	return mEncodeFromDocument(
		inValue,inPath,QJsonDocument::fromJson(inString.toUtf8())
	);
}


// -----------
/*!
	\fn bool AJson::mEncodeFromObject(QString inValue, QString inPath, QJsonObject inObject)

	Write encoded JSON file from QJsonObject.
*/

bool AJson::mEncodeFromObject(QString inValue, QString inPath, QJsonObject inObject) {

	return mEncodeFromDocument(
		inValue,inPath,QJsonDocument(inObject)
	);
}


// -----------
/*!
	\fn bool AJson::mEncodeFromMap(QString inValue,QString inPath,QVariantMap inMap)

	Write encoded JSON file from QVariantMap.
*/

bool AJson::mEncodeFromMap(QString inValue,QString inPath,QVariantMap inMap) {

	return mEncodeFromDocument(
		inValue,inPath,QJsonDocument(QJsonObject::fromVariantMap(inMap))
	);
}


// -----------
/*!
	\fn bool AJson::mEncodeFromHash(QString inValue,QString inPath,QVariantHash inHash)

	Write encoded JSON file from QVariantHash.
*/

bool AJson::mEncodeFromHash(QString inValue,QString inPath,QVariantHash inHash) {

	return mEncodeFromDocument(
		inValue,inPath,QJsonDocument(QJsonObject::fromVariantHash(inHash))
	);
}


// -----------
/*!
	\fn bool AJson::mEncodeFromDocument(QString inValue,QString inPath,QJsonDocument inDocument)

	Write encoded JSON file from QJsonDocument.
*/

bool AJson::mEncodeFromDocument(QString inValue,QString inPath,QJsonDocument inDocument) {

	QFile oFile(inPath);
	if (!oFile.open(QFile::WriteOnly)) {
		return false;
	}

	_A_JSON_DEFAULT_ENCRYPTION_OBJECT;
	QByteArray oDatumnEncrypted = oEncryption.mEncode(
		inDocument.toJson(),
		ACryptography::mValue(inValue),
		ACryptography::mVector(inValue)
	);

	if (oFile.write(oDatumnEncrypted) >= 0) {
		oFile.close();
		return true;
	}

	return false;
}


// -----------
/*!
	\fn AJsonFileReply AJson::mDecodeFromFile(QString inValue,QString inPath)

	Read JSON from encrypted file.
*/

AJsonFileReply AJson::mDecodeFromFile(QString inValue,QString inPath) {

	AJsonFileReply oReply = {};

	QFile oJSONFile(inPath);
	if (!oJSONFile.exists()) {
		_A_CRITICAL << "Opening JSON file for decoding not existed";
		return oReply;
	}
	if (!oJSONFile.open(QIODevice::ReadOnly|QIODevice::Text)) {
		_A_CRITICAL << "Opening JSON file for decoding failed";
		return oReply;
	}

	QByteArray oValue = ACryptography::mValue(inValue);
	QByteArray oVector = ACryptography::mVector(inValue);
	QByteArray oJSONEncrypted = oJSONFile.readAll();

	_A_JSON_DEFAULT_ENCRYPTION_OBJECT;
	QByteArray oJSONDecypted = oEncryption.mRemovePadding(
		oEncryption.mDecode(oJSONEncrypted,oValue,oVector)
	);

	QJsonParseError oJSONParseError;
	QJsonDocument oJSONDocument = QJsonDocument::fromJson(
		oJSONDecypted,&oJSONParseError
	);
	if (oJSONDocument.isNull()) {
		_A_CRITICAL << "Decode JSON from file failed with error:" << oJSONParseError.errorString();
		return oReply;
	}
	oJSONFile.close();

	oReply.Status = _A_ENUMS_APPLICATION_REPLY_STATUS::Ok;
	oReply.Json = oJSONDocument.object();

	return oReply;
}


// -----------
/*!
	\fn bool AJson::mChangeValue(QString inOldValue,QString inNewValue,QString inPath)

	Change value in existed and encrypted JSON file.
*/

bool AJson::mChangeValue(QString inOldValue,QString inNewValue,QString inPath) {

	AJsonFileReply oJSONReply = AJson::mDecodeFromFile(inOldValue,inPath);
	if (oJSONReply.Status != _A_ENUMS_APPLICATION_REPLY_STATUS::Ok) {
		return false;
	}
	return AJson::mEncodeFromObject(inNewValue,inPath,oJSONReply.Json);
}


// -----------
/*!
	\fn bool AJson::mChangeValue(QString inOldValue,QString inNewValue,QString inPath)

	Change value in existed and encrypted JSON file.
*/

bool AJson::mRemoveValue(QString inValue,QString inPath) {

	AJsonFileReply oJSONReply = AJson::mDecodeFromFile(inValue,inPath);
	if (oJSONReply.Status != _A_ENUMS_APPLICATION_REPLY_STATUS::Ok) {
		return false;
	}
	return AJson::mToFileFromObject(inPath,oJSONReply.Json);
}
