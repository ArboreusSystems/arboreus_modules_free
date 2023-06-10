// ----------------------------------------------------------
/*!
    \class AManifest
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 05/06/2023 at 08:50:52
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "amanifest.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AManifest::AManifest(QObject* parent) : QObject(parent) {

	_A_DEBUG << "AManifest created";
}


// -----------
/*!
	\fn

	Doc.
*/

AManifest::~AManifest(void) {

	_A_DEBUG << "AManifest deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void AManifest::mInitWithFile(AManifestFile inFile) {

	pFile = inFile;

	this->mAddDataSystem(
		pFile.Aliases.value(_A_ENUMS_MANIFEST_DATA_TYPE::Private),
		pFile.mPathPrivate()
	);

	this->mAddDataSystem(
		pFile.Aliases.value(_A_ENUMS_MANIFEST_DATA_TYPE::Public),
		pFile.mPathPublic()
	);

	_A_DEBUG << "Manifest initiated with file:" << pFile.mPath();
}


// -----------
/*!
	\fn

	Doc.
*/

bool AManifest::mIsKey(QString inKey) 	{

	return pData.contains(inKey);
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestData AManifest::mGetDataByKey(QString inKey) 	{

	return pData.value(inKey);
}


// -----------
/*!
	\fn

	Doc.
*/

QVariant AManifest::mGetValueByKey(QString inKey) 	{

	return pData.value(inKey).Data;
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mAddDataSystem(QString inKey, QVariant inValue) {

	AManifestData oData;
	oData.Type = _A_ENUMS_MANIFEST_DATA_TYPE::System;
	oData.Data = inValue;

	this->mAddData(inKey,oData);

	return this->mSaveSystem();
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mAddDataPublic(QString inKey, QVariant inValue) {

	AManifestData oData;
	oData.Type = _A_ENUMS_MANIFEST_DATA_TYPE::Public;
	oData.Data = inValue;

	this->mAddData(inKey,oData);

	return this->mSavePublic();
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mAddDataPrivate(QString inValue,QString inKey,QVariant inDataValue) {

	AManifestData oData;
	oData.Type = _A_ENUMS_MANIFEST_DATA_TYPE::Private;
	oData.Data = inDataValue;

	this->mAddData(inKey,oData);

	return this->mSavePrivate(inValue);
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mRemoveFromSystem(QString inKey) 	{

	AManifestReply oOutput;

	QVariantMap oData = this->mSelectData(_A_ENUMS_MANIFEST_DATA_TYPE::System);
	if (!oData.contains(inKey)) {
		oOutput.Status = _A_ENUMS_MANIFEST_REPLY_STATUS::NoKey;
		return oOutput;
	}

	pData.remove(inKey);
	oOutput = this->mSaveSystem();

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mRemoveFromPublic(QString inKey) {

	AManifestReply oOutput;

	QVariantMap oData = this->mSelectData(_A_ENUMS_MANIFEST_DATA_TYPE::Public);
	if (!oData.contains(inKey)) {
		oOutput.Status = _A_ENUMS_MANIFEST_REPLY_STATUS::NoKey;
		return oOutput;
	}

	pData.remove(inKey);
	oOutput = this->mSavePublic();

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mRemoveFromPrivate(QString inValue,QString inKey) {

	AManifestReply oOutput;

	QVariantMap oData = this->mSelectData(_A_ENUMS_MANIFEST_DATA_TYPE::Private);
	if (!oData.contains(inKey)) {
		oOutput.Status = _A_ENUMS_MANIFEST_REPLY_STATUS::NoKey;
		return oOutput;
	}

	pData.remove(inKey);
	oOutput = this->mSavePrivate(inValue);

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

void AManifest::mAddData(QString inKey, AManifestData inData) {

	pData.insert(inKey,inData);
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap AManifest::mSelectData(AEnumsManifestDataType::DataType inType) {

	QVariantMap oData;

	foreach (QString iKey, pData.keys()) {
		AManifestData iData = pData.value(iKey);
		if (iData.Type == inType) {
			oData.insert(iKey,iData.Data);
		}
	}

	return oData;
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mSaveSystem(void) {

	AManifestReply oOutput;

	QVariantMap oData = this->mSelectData(_A_ENUMS_MANIFEST_DATA_TYPE::System);

	if (!ADir::mEnsure(pFile.Dir)) {
		_A_CRITICAL << "Dir for manifest not ensured:" << pFile.Dir;
	}

	if (pFile.EncodeBase64) {
		if (AJson::mToBase64FileFromMap(pFile.mPath(),oData)) {
			oOutput.Status = _A_ENUMS_MANIFEST_REPLY_STATUS::Ok;
			_A_DEBUG << "Base64 manifest written:" << pFile.mPath();
		} else {
			_A_CRITICAL << "Base64 manifest not written:" << pFile.mPath();
		}
	} else {
		if (AJson::mToFileFromMap(pFile.mPath(),oData)) {
			oOutput.Status = _A_ENUMS_MANIFEST_REPLY_STATUS::Ok;
			_A_DEBUG << "Manifest written:" << pFile.mPath();
		} else {
			_A_CRITICAL << "Manifest not written:" << pFile.mPath();
		}
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mSavePublic(void) {

	AManifestReply oOutput;

	QVariantMap oData = this->mSelectData(_A_ENUMS_MANIFEST_DATA_TYPE::Public);

	if (!ADir::mEnsure(pFile.Dir)) {
		_A_CRITICAL << "Dir for public manifest not ensured:" << pFile.Dir;
	}

	if (pFile.EncodeBase64) {
		if (AJson::mToBase64FileFromMap(pFile.mPathPublic(),oData)) {
			oOutput.Status = _A_ENUMS_MANIFEST_REPLY_STATUS::Ok;
			_A_DEBUG << "Base64 public manifest written:" << pFile.mPathPublic();
		} else {
			_A_CRITICAL << "Base64 public manifest not written:" << pFile.mPathPublic();
		}
	} else {
		if (AJson::mToFileFromMap(pFile.mPathPublic(),oData)) {
			oOutput.Status = _A_ENUMS_MANIFEST_REPLY_STATUS::Ok;
			_A_DEBUG << "Public manifest written:" << pFile.mPathPublic();
		} else {
			_A_CRITICAL << "Public manifest not written:" << pFile.mPathPublic();
		}
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mSavePrivate(QString inValue) {

	AManifestReply oOutput;

	QVariantMap oData = this->mSelectData(_A_ENUMS_MANIFEST_DATA_TYPE::Private);

	if (!ADir::mEnsure(pFile.Dir)) {
		_A_CRITICAL << "Dir for private manifest not ensured:" << pFile.Dir;
	}

	if (AJson::mEncodeFromMap(inValue,pFile.mPathPrivate(),oData)) {
		oOutput.Status = _A_ENUMS_MANIFEST_REPLY_STATUS::Ok;
		_A_DEBUG << "Private manifest written:" << pFile.mPathPrivate();
	} else {
		_A_CRITICAL << "Private manifest not written:" << pFile.mPathPublic();
	}

	return oOutput;
}
