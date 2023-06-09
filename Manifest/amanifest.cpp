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

AManifestReply AManifest::mLoadFromFilePublic(void) {

	AManifestReply oOutput;
	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mLoadFromFilePrivate(QString inValue) {

	AManifestReply oOutput;
	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mSaveToFile(void) {

	AManifestReply oOutput;
	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

void AManifest::mWriteByKeyPublic(QString inKey, QVariant inValue) {

	this->mWriteByKey(inKey,inValue,_A_ENUMS_MANIFEST_DATA_TYPE::Public);
}


// -----------
/*!
	\fn

	Doc.
*/

void AManifest::mWriteByKeyPrivate(QString inKey, QVariant inValue) {

	this->mWriteByKey(inKey,inValue,_A_ENUMS_MANIFEST_DATA_TYPE::Private);
}


// -----------
/*!
	\fn

	Doc.
*/

void AManifest::mWriteByKey(QString inKey, QVariant inValue, _A_ENUMS_MANIFEST_DATA_TYPE inType) {

	AManifestData oData;
	oData.Type = inType;
	oData.Data = inValue;

	pData.insert(inKey,oData);
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

