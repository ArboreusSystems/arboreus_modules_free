// ----------------------------------------------------------
/*!
	\class AFile
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 04/03/2022 at 16:36:45
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "afile.h"

// Namespace definition
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

AFile::AFile(QObject* parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

AFile::~AFile(void) {}


// -----------
/*!
	\fn bool aFile::mRemove(QString inPath)

	Remove file if existed.
*/

bool AFile::mRemove(QString inPath) {

	if (mExist(inPath)) {
		QFile(inPath).remove();
		if (!mExist(inPath)) {
			return true;
		}
		return false;
	}
	return false;
}


// -----------
/*!
	\fn bool aFile::mExist(QString inPath)

	Checking file existance.
*/

bool AFile::mExist(QString inPath) {

	if (QFileInfo::exists(inPath) && !QDir(inPath).exists()) {
		return true;
	}
	return false;
}


// -----------
/*!
	\fn bool AFile::mEncode(QString inValue, QString inPath, QByteArray inDatumn)

	Encode and write data to file.
*/

bool AFile::mEncode(QString inValue, QString inPath, QByteArray inDatumn) {

	ACryptographyAES oCryptography(
		_A_ENUMS_CRYPTOGRAPHY_AES_TYPE::AES_256,
		_A_ENUMS_CRYPTOGRAPHY_AES_MODE::ECB
	);

	QByteArray oEncodedDatumn = oCryptography.mEncode(
		ACryptography::mSignAdd(inDatumn),
		ACryptography::mValue(inValue),
		ACryptography::mVector(inValue)
	);

	QFile oFile(inPath);
	if (!oFile.open(QFile::WriteOnly)) {
		_A_CRITICAL << "Error in opening file:" << inPath;
		return false;
	}

	if (oFile.write(oEncodedDatumn) >= 0) {
		oFile.close();
		return true;
	}

	return false;
}


// -----------
/*!
	\fn AFileReply AFile::mDecode(QString inValue, QString inPath)

	Read and decode data from file.
*/


AFileReply AFile::mDecode(QString inValue, QString inPath) {

	AFileReply oReply = {};

	QFile oFile(inPath);
	if (!oFile.exists()) {
		oReply.Status = _A_ENUMS_APPLICATION_REPLY_STATUS::NotExisted;
		return oReply;
	}

	if (!oFile.open(QFile::ReadOnly)) {
		_A_CRITICAL << "Error in opening file:" << inPath;
		return oReply;
	}

	ACryptographyAES oCryptography(
		_A_ENUMS_CRYPTOGRAPHY_AES_TYPE::AES_256,
		_A_ENUMS_CRYPTOGRAPHY_AES_MODE::ECB
	);

	QByteArray oDatumnEncoded = oFile.readAll();
	QByteArray oDatumnSigned = oCryptography.mDecode(
		oDatumnEncoded,
		ACryptography::mValue(inValue),
		ACryptography::mVector(inValue)
	);
	ACryptographySignReply oDatum = ACryptography::mSignRemove(oDatumnSigned);
	if (oDatum.Status == _A_ENUMS_APPLICATION_REPLY_STATUS::WrongValue) {
		oReply.Status = oDatum.Status;
		return oReply;
	}

	oReply.Status = _A_ENUMS_APPLICATION_REPLY_STATUS::Ok;
	oReply.Datumn = oDatum.Datumn;
	return oReply;
}


// -----------
/*!
	\fn

	Doc.
*/

bool AFile::mEncodeBase64(QString inPath, QByteArray inDatumn) {

	QFile oFile(inPath);
	if (!oFile.open(QFile::WriteOnly)) {
		_A_CRITICAL << "Error in opening file:" << inPath;
		return false;
	}

	if (oFile.write(inDatumn.toBase64()) >= 0) {
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

AFileReply AFile::mDecodeBase64(QString inPath) {

	AFileReply oReply = {};

	QFile oFile(inPath);
	if (!oFile.exists()) {
		oReply.Status = _A_ENUMS_APPLICATION_REPLY_STATUS::NotExisted;
		return oReply;
	}

	if (!oFile.open(QFile::ReadOnly)) {
		_A_CRITICAL << "Error in opening file:" << inPath;
		return oReply;
	}

	oReply.Status = _A_ENUMS_APPLICATION_REPLY_STATUS::Ok;
	oReply.Datumn = QByteArray::fromBase64(oFile.readAll());
	return oReply;
}
