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
	_A_DEBUG << "Manifest initiated with file:" << pFile.mPath();
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mLoadPublic(void) {

	AManifestReply oOutput;
	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mLoadPrivate(QString inValue) {

	AManifestReply oOutput;
	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mSave(void) {

	AManifestReply oOutput;

	if (!ADir::mEnsure(pFile.Dir)) {
		_A_CRITICAL << "Not ensured dir for manifest file" << pFile.mPath();
		return oOutput;
	}

	QVariantMap oManifest;
	QVariantList oManifestPublic;
	QVariantList oManifestPrivate;

	foreach (QString iKey, pData.keys()) {
		AManifestData iData = pData.value(iKey);
		QVariantMap iRow;
		iRow.insert("key",iKey);
		iRow.insert("value",iData.Data);
		if (iData.Type == _A_ENUMS_MANIFEST_DATA_TYPE::Private) {
			oManifestPrivate.append(iRow);
		} else {
			oManifestPublic.append(iRow);
		}
	}

	oManifest.insert(
		pFile.Aliases.value(_A_ENUMS_MANIFEST_DATA_TYPE::Public),
		oManifestPublic
	);
	oManifest.insert(
		pFile.Aliases.value(_A_ENUMS_MANIFEST_DATA_TYPE::Private),
		oManifestPrivate
	);

	if (!AJson::mToFileFromMap(pFile.mPath(),oManifest)) {
		_A_CRITICAL << "Manifest JSON file not saved:" << pFile.mPath();
		return oOutput;
	} else {
		oOutput.Type = _A_ENUMS_MANIFEST_REPLY_TYPE::Ok;
		_A_DEBUG << "Did write manifest:" << pFile.mPath();
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mWriteByKeyPublic(QString inKey, QVariant inValue) {

	return this->mWriteByKey(inKey,inValue,_A_ENUMS_MANIFEST_DATA_TYPE::Public);
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mWriteByKeyPrivate(QString inKey, QVariant inValue) {

	return this->mWriteByKey(inKey,inValue,_A_ENUMS_MANIFEST_DATA_TYPE::Private);
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mWriteByKey(QString inKey, QVariant inValue, _A_ENUMS_MANIFEST_DATA_TYPE inType) {

	AManifestData oData;
	oData.Type = inType;
	oData.Data = inValue;

	pData.insert(inKey,oData);

	return this->mSave();
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mReadByKey(QString inKey) {

	AManifestReply oOutput;

	if (this->mIsKey(inKey)) {
		oOutput.Type = _A_ENUMS_MANIFEST_REPLY_TYPE::Ok;
		oOutput.Data = pData.value(inKey).Data;
	} else {
		oOutput.Type = _A_ENUMS_MANIFEST_REPLY_TYPE::NoKey;
		oOutput.Data = inKey;
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

bool AManifest::mIsKey(QString inKey) {

	return pData.contains(inKey);
}

