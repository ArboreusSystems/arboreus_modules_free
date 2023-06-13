// ----------------------------------------------------------
/*!
	\class ACryptography
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 11/09/2021 at 17:46:32
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "acryptography.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ACryptography::ACryptography(QObject* parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

ACryptography::~ACryptography(void) {}


// -----------
/*!
	\fn QByteArray ACryptography::mValue(QString inString)

	Create value from incoming string.
*/

QByteArray ACryptography::mValue(QString inString) {

	QString oOutputValueString = "";
	QString oMirror = inString;
	std::reverse(oMirror.begin(),oMirror.end());
	for (int i = 0; i < inString.length(); ++i) {
		oOutputValueString =
			QString::number((int)oMirror[i].toLatin1()) +
			oOutputValueString + inString[i] +
			QString::number((int)inString[i].toLatin1()) +
			oMirror[i];
	}

	QByteArray oPart1 = QCryptographicHash::hash(
		oOutputValueString.toLocal8Bit(),QCryptographicHash::Sha3_384
	);
	QByteArray oPart2 = QCryptographicHash::hash(
		oOutputValueString.toLocal8Bit(),QCryptographicHash::Sha3_512
	);
	QByteArray oPart3 = QCryptographicHash::hash(
		oOutputValueString.toLocal8Bit(),QCryptographicHash::Sha3_256
	);

	return oPart1.append(oPart3).append(oPart2);
}


// -----------
/*!
	\fn QByteArray ACryptography::mVector(QString inString)

	Create vector sequence based on incoming string.
*/

QByteArray ACryptography::mVector(QString inString) {

	QString oOutputKeyString = "";
	QString oMirror = inString;
	std::reverse(oMirror.begin(),oMirror.end());
	for (int i = 0; i < inString.length(); ++i) {
		oOutputKeyString =
			oOutputKeyString + inString[i] +
			oMirror[i] + QString::number((int)oMirror[i].toLatin1());
	}

	return QCryptographicHash::hash(
		ASequenceString::mMd4FromQString(oOutputKeyString).toLocal8Bit(),
		QCryptographicHash::Md5
	);
}


// -----------
/*!
	\fn QByteArray ACryptography::mSignAdd(QByteArray inDatumn)

	Return self-signed datumn.
*/

QByteArray ACryptography::mSignAdd(QByteArray inDatumn) {

	QByteArray oSign = QCryptographicHash::hash(inDatumn,QCryptographicHash::Md5);
	return oSign.append(inDatumn);
}


// -----------
/*!
	\fn ACryptographySignReply ACryptography::mSignRemove(QByteArray inDatumn)

	Return datumn without sign within validating data.
*/

ACryptographySignReply ACryptography::mSignRemove(QByteArray inDatumn) {

	ACryptographySignReply oOutput;

	if (inDatumn.length() < 16) {
		return oOutput;
	}

	QByteArray oSign = {};
	for (int i = 0; i < 16; ++i) {
		oSign.append(inDatumn[i]);
	}
	QByteArray oDatumn = inDatumn.remove(0,16);

	if (oSign == QCryptographicHash::hash(oDatumn,QCryptographicHash::Md5)) {
		oOutput.Status = _A_ENUMS_APPLICATION_REPLY_STATUS::Ok;
		oOutput.Datumn = oDatumn;
	} else {
		oOutput.Status = _A_ENUMS_APPLICATION_REPLY_STATUS::WrongValue;
	}

	return oOutput;
}
