// ----------------------------------------------------------
/*!
	\class ASequenceString
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 11/09/2021 at 18:02:00
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "asequencestring.h"

// Namesapce
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ASequenceString::ASequenceString(QObject* parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

ASequenceString::~ASequenceString(void) {}


// -----------
/*!
	\fn QString ASequenceString::mRandomMatrix(int inWidth,int inHeight)

	Generate random string matrix of with and height based on AlphaNumeric dictionary.
*/

QString ASequenceString::mRandomMatrix(int inWidth,int inHeight) {

	return mRandomMatrix(
		inWidth,inHeight,
		mDictionary(_A_ENUM_DICTIONARY_TYPE::AlphaNumeric)
	);
}


// -----------
/*!
	\fn QString ASequenceString::mRandomMatrix(int inWidth, int inHeight, QString inDictionary)

	Generate random string matrix of with and height based on defined dictionary.
*/

QString ASequenceString::mRandomMatrix(int inWidth, int inHeight, QString inDictionary) {

	QString oMatrix;
	QString oShakedDictionary = ASequenceString::mShake(inDictionary);

	for (int i = 0; i < inHeight; ++i) {
		oMatrix += mRandom(inWidth,oShakedDictionary) + QString("\n");
	}

	return oMatrix;
}


// -----------
/*!
	\fn QString ASequenceString::mValue(QString inValue)

	Return full value from QString object.
*/

QString ASequenceString::mValue(QString inValue) {

	QString oString1 = mMd4FromQString(inValue);
	QString::iterator oString1Iterator = oString1.begin();
	QString oString2 = mMd5FromQString(inValue);
	QString::iterator oString2Iterator = oString2.begin();

	QString oOutput = "";
	while (oString1Iterator != oString1.end()) {
		oOutput = oOutput + *oString1Iterator + *oString2Iterator;
		++oString1Iterator; ++ oString2Iterator;
	}

	return oOutput;
}


// -----------
/*!
	\fn QString ASequenceString::mValue(int inLength,QString inValue)

	Return restricted by length value from QString object.
*/

QString ASequenceString::mValue(int inLength,QString inValue) {

	QString oOutut = mValue(inValue);
	if (inLength > oOutut.length()) {
		return oOutut;
	}
	return oOutut.left(inLength);
}


// -----------
/*!
	\fn QString ASequenceString::mValue(int inLength,QString inValue)

	Return restricted by length value from QString object.
*/

QString ASequenceString::mValue(QString inExtention, int inLength, QString inValue) {

	return inExtention + mValue(inLength,inValue);
}


// -----------
/*!
	\fn QString ASequenceString::mMd5ID(void)

	Generate unique ID based on md5-hash from unique random string..
*/

QString ASequenceString::mMd5ID(void) {

	return mMd5FromQString(
		QString::number(QDateTime::currentMSecsSinceEpoch()) + mRandom(1024)
	);
}


// -----------
/*!
	\fn QString ASequenceString::mMd5FromQString(QString inString)

	Generate unique ID based on md4-hash from unique random string.
*/

QString ASequenceString::mMd5FromQString(QString inString) {

	return QString(
		QCryptographicHash::hash(inString.toUtf8(),QCryptographicHash::Md5).toHex()
	);
}


// -----------
/*!
	\fn QString ASequenceString::mMd4ID(void)

	Generate unique ID based on md4-hash from unique random string.
*/

QString ASequenceString::mMd4ID(void) {

	return mMd4FromQString(
		QString::number(QDateTime::currentMSecsSinceEpoch()) + mRandom(1024)
	);
}


// -----------
/*!
	\fn QString ASequenceString::mMd4FromQString(QString inString)

	Generate QString object within unique MD4 sequence based on md4-hash from string.
*/

QString ASequenceString::mMd4FromQString(QString inString) {

	return QString(
		QCryptographicHash::hash(inString.toUtf8(),QCryptographicHash::Md4).toHex()
	);
}


// -----------
/*!
	\fn QString ASequenceString::mRandom(int inLength)

	Return random string sequence based on length and used by default
	pDictionaryType::AlphaNumeric value for dictionary.
*/

QString ASequenceString::mRandom(int inLength) {

	return mRandom(inLength,mDictionary(_A_ENUM_DICTIONARY_TYPE::AlphaNumeric));
}


// -----------
/*!
	\fn QString ASequenceString::mRandom(int inLength,QString inDictionary)

	Return random string sequence based on length and dictionary.
*/

QString ASequenceString::mRandom(int inLength,QString inDictionary) {

	QString oString;

	if (inDictionary.length() > 0) {
		int oSolt = ARandom::mNumberFromRange(0,1024);
		for(int i = 0; i < inLength + oSolt; ++i) {
			int oCharPosition = ARandom::mNumberPositiveNoExponent() % inDictionary.length();
			QChar vNextChar = inDictionary.at(oCharPosition);
			oString.append(vNextChar);
		}
		static_cast<void>(oString.mid(ARandom::mNumberFromRange(0,oSolt - 1),inLength));
	} else {
		oString = "Error! Got empty dictionary";
	}

	return oString;
}


// -----------
/*!
	\fn QString ASequenceString::mDictionary(_A_ENUM_DICTIONARY_TYPE inType)

	Return QString within dictionary for generating sequence.
*/

QString ASequenceString::mDictionary(_A_ENUM_DICTIONARY_TYPE inType) {

	QString vDictionary;
	switch (inType) {
		case _A_ENUM_DICTIONARY_TYPE::AlphaLower:
			vDictionary = "abcdefghijklmnopqrstuvwxyz";
			break;
		case _A_ENUM_DICTIONARY_TYPE::AlphaUpper:
			vDictionary = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			break;
		case _A_ENUM_DICTIONARY_TYPE::Alpha:
			vDictionary = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
			break;
		case _A_ENUM_DICTIONARY_TYPE::AlphaLowerNumeric:
			vDictionary = "abcdefghijklmnopqrstuvwxyz0123456789";
			break;
		case _A_ENUM_DICTIONARY_TYPE::AlphaUpperNumeric:
			vDictionary = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
			break;
		case _A_ENUM_DICTIONARY_TYPE::Numeric:
			vDictionary = "0123456789";
			break;
		case _A_ENUM_DICTIONARY_TYPE::Symbols:
			vDictionary = "±!@#$%^&*()_+=-§`?><~{}][ ,.;':";
			break;
		default:
			vDictionary = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
			break;
	}
	return vDictionary;
}


// -----------
/*!
	\fn

	Doc.
*/

QString ASequenceString::mShake(QString inString) {

	QString oStringShaked;
	int oStringLength = inString.length();
	int oPosition = 0;

	for (int i = 0; i < oStringLength; i++) {
		oPosition = 0 + arc4random() % inString.length();
		oStringShaked += inString.at(oPosition);
		inString.remove(oPosition,1);
	}

	return oStringShaked;
}
