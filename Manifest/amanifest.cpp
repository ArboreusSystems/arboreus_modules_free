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

void AManifest::mInitWithData(QString inValue, QVariantList inData, AManifestFile inFile) {

	pFile = inFile;

	this->mAddDataSystem(
		pFile.Aliases.value(_A_ENUMS_MANIFEST_DATA_TYPE::Private),
		pFile.mPathPrivate()
	);

	this->mAddDataSystem(
		pFile.Aliases.value(_A_ENUMS_MANIFEST_DATA_TYPE::Public),
		pFile.mPathPublic()
	);

	QVariantMap oDataProperties;

	foreach (QVariant iProperties, inData) {
		oDataProperties = qvariant_cast<QVariantMap>(iProperties);
		switch (static_cast<_A_ENUMS_MANIFEST_DATA_TYPE>(qvariant_cast<int>(oDataProperties.value("type")))) {
			case _A_ENUMS_MANIFEST_DATA_TYPE::System:
				_A_DEBUG << 1;
				this->mAddDataSystem(
					qvariant_cast<QString>(oDataProperties.value("key")),
					oDataProperties.value("data")
				);
				break;
			case _A_ENUMS_MANIFEST_DATA_TYPE::Public:
				_A_DEBUG << 2;
				this->mAddDataPublic(
					qvariant_cast<QString>(oDataProperties.value("key")),
					oDataProperties.value("data")
				);
				break;
			case _A_ENUMS_MANIFEST_DATA_TYPE::Private:
				_A_DEBUG << 3;
				this->mAddDataPrivate(
					inValue,
					qvariant_cast<QString>(oDataProperties.value("key")),
					oDataProperties.value("data")
				);
				break;
			default:
				break;
			}
	}

	_A_DEBUG << "Manifest initiated with data in file:" << pFile.mPath();
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

AManifestReply AManifest::mLoadSystem(void) {

	AManifestReply oOutput;
	QString oPath = pFile.mPathPublic();

	if (!AFile::mExist(oPath)) {
		oOutput.Status = _A_ENUMS_MANIFEST_REPLY_STATUS::NoFile;
		oOutput.Data = oPath;
		_A_CRITICAL << "No manifest file:" << oPath;
		return oOutput;
	}

	AJsonFileReply oJSONManifestReply;
	if (pFile.EncodeBase64) {
		oJSONManifestReply = AJson::mFromBase64File(oPath);
	} else {
		oJSONManifestReply = AJson::mFromFile(oPath);
	}

	if (oJSONManifestReply.Status == _A_ENUMS_APPLICATION_REPLY_STATUS::Ok) {
		this->mLoadData(_A_ENUMS_MANIFEST_DATA_TYPE::System,oJSONManifestReply.Json);
		oOutput.Status = _A_ENUMS_MANIFEST_REPLY_STATUS::Ok;
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mLoadPublic(void) {

	AManifestReply oOutput;
	QString oPath = pFile.mPathPublic();

	if (!AFile::mExist(oPath)) {
		oOutput.Status = _A_ENUMS_MANIFEST_REPLY_STATUS::NoFile;
		oOutput.Data = oPath;
		_A_CRITICAL << "No public manifest file:" << oPath;
		return oOutput;
	}

	AJsonFileReply oJSONManifestReply;
	if (pFile.EncodeBase64) {
		oJSONManifestReply = AJson::mFromBase64File(oPath);
	} else {
		oJSONManifestReply = AJson::mFromFile(oPath);
	}

	if (oJSONManifestReply.Status == _A_ENUMS_APPLICATION_REPLY_STATUS::Ok) {
		this->mLoadData(_A_ENUMS_MANIFEST_DATA_TYPE::Public,oJSONManifestReply.Json);
		oOutput.Status = _A_ENUMS_MANIFEST_REPLY_STATUS::Ok;
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mLoadPrivate(QString inValue) {

	AManifestReply oOutput;
	QString oPath = pFile.mPathPrivate();

	if (!AFile::mExist(oPath)) {
		oOutput.Status = _A_ENUMS_MANIFEST_REPLY_STATUS::NoFile;
		oOutput.Data = oPath;
		_A_CRITICAL << "No private manifest file:" << oPath;
		return oOutput;
	}

	AJsonFileReply oJSONManifestReply = AJson::mDecodeFromFile(inValue,oPath);

	if (oJSONManifestReply.Status == _A_ENUMS_APPLICATION_REPLY_STATUS::Ok) {
		this->mLoadData(_A_ENUMS_MANIFEST_DATA_TYPE::System,oJSONManifestReply.Json);
		oOutput.Status = _A_ENUMS_MANIFEST_REPLY_STATUS::Ok;
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

void AManifest::mUnloadPublic(void) {

	this->mUnloadData(_A_ENUMS_MANIFEST_DATA_TYPE::Public);
	pIsLoadedPublic = false;
}


// -----------
/*!
	\fn

	Doc.
*/

void AManifest::mUnloadPrivate(void) {

	this->mUnloadData(_A_ENUMS_MANIFEST_DATA_TYPE::Private);
	pIsLoadedPrivate = false;
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

void AManifest::mUnloadData(_A_ENUMS_MANIFEST_DATA_TYPE inType) {

	foreach (QString iKey, pData.keys()) {
		AManifestData iData = pData.value(iKey);
		if (iData.Type == inType) {
			pData.remove(iKey);
		}
	}
}


// -----------
/*!
	\fn

	Doc.
*/

void AManifest::mLoadData(_A_ENUMS_MANIFEST_DATA_TYPE inType, QJsonObject inManifest) {

	QVariantMap oManifestData = inManifest.toVariantMap();
	foreach (QString iKey, oManifestData.keys()) {
		AManifestData iData;
		iData.Type = inType;
		iData.Data = oManifestData.value(iKey);
		pData.insert(iKey,iData);
	}
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
