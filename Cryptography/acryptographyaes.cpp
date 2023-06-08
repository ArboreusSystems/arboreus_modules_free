// ----------------------------------------------------------
/*!
	\class ACryptographyAES
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 11/09/2021 at 18:27:07
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "acryptographyaes.h"

// Namespace
using namespace ARB;


// -----------
/*!
	\fn ACryptographyAES::ACryptographyAES(AESType inLevel, AESMode inMode, AESPadding inPadding, QObject *parent)

	Class consatructor.
*/

ACryptographyAES::ACryptographyAES(
	_A_ENUMS_CRYPTOGRAPHY_AES_TYPE inLevel,
	_A_ENUMS_CRYPTOGRAPHY_AES_MODE inMode,
	_A_ENUMS_CRYPTOGRAPHY_AES_PADDING inPadding,
	QObject* parent
): QObject(parent) {

	pNb = 4;
	pBlockLength = 16;
	pLevel = static_cast<int>(inLevel);
	pMode = static_cast<int>(inMode);
	pPadding = static_cast<int>(inPadding);
	pState = NULL;

	switch (inLevel) {
		case _A_ENUMS_CRYPTOGRAPHY_AES_TYPE::AES_128: {
				ACryptographyAES128 oAES;
				pNk = oAES.Nk;
				pKeyLength = oAES.KeyLength;
				pNr = oAES.Nr;
				pExpandedKey = oAES.ExpandedKey;
			}; break;
		case _A_ENUMS_CRYPTOGRAPHY_AES_TYPE::AES_192: {
				ACryptographyAES192 oAES;
				pNk = oAES.Nk;
				pKeyLength = oAES.KeyLength;
				pNr = oAES.Nr;
				pExpandedKey = oAES.ExpandedKey;
			}; break;
		case _A_ENUMS_CRYPTOGRAPHY_AES_TYPE::AES_256: {
				ACryptographyAES256 oAES;
				pNk = oAES.Nk;
				pKeyLength = oAES.KeyLength;
				pNr = oAES.Nr;
				pExpandedKey = oAES.ExpandedKey;
			}; break;
		default: {
				ACryptographyAES128 oAES;
				pNk = oAES.Nk;
				pKeyLength = oAES.KeyLength;
				pNr = oAES.Nr;
				pExpandedKey = oAES.ExpandedKey;
			}; break;
	}
}


// -----------
/*!
	\fn ACryptographyAES::~ACryptographyAES(void)

	Class destructor.
*/

ACryptographyAES::~ACryptographyAES(void) {}


// -----------
/*!
	\fn QByteArray ACryptographyAES::mEncode(const QByteArray& inRawText,const QByteArray& inKey,const QByteArray& inIv)

	Doc.
*/

QByteArray ACryptographyAES::mEncode(
	const QByteArray& inRawText,
	const QByteArray& inKey,
	const QByteArray& inIv
) {

	if (pMode >= (int)_A_ENUMS_CRYPTOGRAPHY_AES_MODE::CBC && (inIv.isNull() || inIv.size() != pBlockLength)) {
		return QByteArray();
	}

	QByteArray oOutput;
	QByteArray oExpandedKey = mExpandKey(inKey);
	QByteArray oAlignedText(inRawText);

	oAlignedText.append(mGetPadding(inRawText.size(), pBlockLength));

	switch(pMode) {
		case (int)_A_ENUMS_CRYPTOGRAPHY_AES_MODE::ECB:
			for(int i = 0; i < oAlignedText.size(); i += pBlockLength) {
				oOutput.append(mCipher(oExpandedKey, oAlignedText.mid(i, pBlockLength)));
			}
			break;
		case (int)_A_ENUMS_CRYPTOGRAPHY_AES_MODE::CBC: {
				QByteArray ivTemp(inIv);
				for(int i = 0; i < oAlignedText.size(); i += pBlockLength) {
					oAlignedText.replace(i, pBlockLength, mByteXor(oAlignedText.mid(i, pBlockLength),ivTemp));
					oOutput.append(mCipher(oExpandedKey, oAlignedText.mid(i, pBlockLength)));
					ivTemp = oOutput.mid(i, pBlockLength);
				}
			}
			break;
		case (int)_A_ENUMS_CRYPTOGRAPHY_AES_MODE::CFB: {
				oOutput.append(mByteXor(oAlignedText.left(pBlockLength), mCipher(oExpandedKey, inIv)));
				for(int i=0; i < oAlignedText.size(); i+= pBlockLength) {
					if (i+pBlockLength < oAlignedText.size()) {
						oOutput.append(
							mByteXor(oAlignedText.mid(i+pBlockLength, pBlockLength),
							mCipher(oExpandedKey, oOutput.mid(i, pBlockLength)))
						);
					}
				}
			}
			break;
		case (int)_A_ENUMS_CRYPTOGRAPHY_AES_MODE::OFB: {
				QByteArray oOfbTemp;
				oOfbTemp.append(mCipher(oExpandedKey, inIv));
				for (int i=pBlockLength; i < oAlignedText.size(); i += pBlockLength) {
					oOfbTemp.append(mCipher(oExpandedKey, oOfbTemp.right(pBlockLength)));
				}
				oOutput.append(mByteXor(oAlignedText, oOfbTemp));
			}
			break;
		default: break;
	}

	return oOutput;
}


// -----------
/*!
	\fn QByteArray ACryptographyAES::mDecode(const QByteArray& inRawText,const QByteArray& inKey,const QByteArray& inIv)

	Doc.
*/

QByteArray ACryptographyAES::mDecode(
	const QByteArray& inRawText,
	const QByteArray& inKey,
	const QByteArray& inIv
) {

	if (pMode >= (int)_A_ENUMS_CRYPTOGRAPHY_AES_MODE::CBC && (inIv.isNull() || inIv.size() != pBlockLength)) {
		return QByteArray();
	}

	QByteArray oOutput;
	QByteArray oExpandedKey = mExpandKey(inKey);

	switch(pMode) {
		case (int)_A_ENUMS_CRYPTOGRAPHY_AES_MODE::ECB:
			for(int i = 0; i < inRawText.size(); i += pBlockLength) {
				oOutput.append(mInvCipher(oExpandedKey, inRawText.mid(i, pBlockLength)));
			}
			break;
		case (int)_A_ENUMS_CRYPTOGRAPHY_AES_MODE::CBC: {
				QByteArray ivTemp(inIv);
				for(int i = 0; i < inRawText.size(); i += pBlockLength) {
					oOutput.append(mInvCipher(oExpandedKey, inRawText.mid(i, pBlockLength)));
					oOutput.replace(i, pBlockLength, mByteXor(oOutput.mid(i, pBlockLength),ivTemp));
					ivTemp = inRawText.mid(i, pBlockLength);
				}
			}
			break;
		case (int)_A_ENUMS_CRYPTOGRAPHY_AES_MODE::CFB: {
				oOutput.append(mByteXor(inRawText.mid(0, pBlockLength), mCipher(oExpandedKey, inIv)));
				for(int i = 0; i < inRawText.size(); i += pBlockLength) {
					if (i + pBlockLength < inRawText.size()) {
						oOutput.append(
							mByteXor(inRawText.mid(i + pBlockLength, pBlockLength),
							mCipher(oExpandedKey, inRawText.mid(i, pBlockLength)))
						);
					}
				}
			}
			break;
		case (int)_A_ENUMS_CRYPTOGRAPHY_AES_MODE::OFB: {
				QByteArray oOfbTemp;
				oOfbTemp.append(mCipher(oExpandedKey, inIv));
				for (int i = pBlockLength; i < inRawText.size(); i += pBlockLength){
					oOfbTemp.append(mCipher(oExpandedKey, oOfbTemp.right(pBlockLength)));
				}
				oOutput.append(mByteXor(inRawText, oOfbTemp));
			}
			break;
		default:
			break;
	}

	return oOutput;
}


// -----------
/*!
	\fn QByteArray ACryptographyAES::mRemovePadding(const QByteArray& inRawText)

	Doc.
*/

QByteArray ACryptographyAES::mRemovePadding(const QByteArray& inRawText) {

	return mRemovePadding(inRawText, (_A_ENUMS_CRYPTOGRAPHY_AES_PADDING) pPadding);
}


// -----------
/*!
	\fn QByteArray ACryptographyAES::mExpandKey(const QByteArray& inKey)

	Doc.
*/

QByteArray ACryptographyAES::mExpandKey(const QByteArray& inKey) {

	int i, k;
	quint8 oTempa[4];
	QByteArray oRoundKey(inKey);

	for(i = pNk; i < pNb * (pNr + 1); i++) {

		oTempa[0] = (quint8) oRoundKey.at((i-1) * 4 + 0);
		oTempa[1] = (quint8) oRoundKey.at((i-1) * 4 + 1);
		oTempa[2] = (quint8) oRoundKey.at((i-1) * 4 + 2);
		oTempa[3] = (quint8) oRoundKey.at((i-1) * 4 + 3);

		if (i % pNk == 0) {

			k = oTempa[0];
			oTempa[0] = oTempa[1];
			oTempa[1] = oTempa[2];
			oTempa[2] = oTempa[3];
			oTempa[3] = k;

			oTempa[0] = mGetSBoxValue(oTempa[0]);
			oTempa[1] = mGetSBoxValue(oTempa[1]);
			oTempa[2] = mGetSBoxValue(oTempa[2]);
			oTempa[3] = mGetSBoxValue(oTempa[3]);

			oTempa[0] =  oTempa[0] ^ pRCon[i/pNk];
		}

		if (pLevel == (int)_A_ENUMS_CRYPTOGRAPHY_AES_TYPE::AES_256 && i % pNk == 4) {
			oTempa[0] = mGetSBoxValue(oTempa[0]);
			oTempa[1] = mGetSBoxValue(oTempa[1]);
			oTempa[2] = mGetSBoxValue(oTempa[2]);
			oTempa[3] = mGetSBoxValue(oTempa[3]);
		}

		oRoundKey.insert(i * 4 + 0, (quint8) oRoundKey.at((i - pNk) * 4 + 0) ^ oTempa[0]);
		oRoundKey.insert(i * 4 + 1, (quint8) oRoundKey.at((i - pNk) * 4 + 1) ^ oTempa[1]);
		oRoundKey.insert(i * 4 + 2, (quint8) oRoundKey.at((i - pNk) * 4 + 2) ^ oTempa[2]);
		oRoundKey.insert(i * 4 + 3, (quint8) oRoundKey.at((i - pNk) * 4 + 3) ^ oTempa[3]);

	}

	return oRoundKey;
}


// -----------
/*!
	\fn QByteArray ACryptographyAES::mCrypt(ACryptographyAES::AESType inLevel,ACryptographyAES::AESMode inMode,const QByteArray& inRawText,const QByteArray& inKey,const QByteArray& inIv,ACryptographyAES::AESPadding inPadding)

	Doc.
*/

QByteArray ACryptographyAES::mCrypt(
	_A_ENUMS_CRYPTOGRAPHY_AES_TYPE inLevel,
	_A_ENUMS_CRYPTOGRAPHY_AES_MODE inMode,
	const QByteArray& inRawText,
	const QByteArray& inKey,
	const QByteArray& inIv,
	_A_ENUMS_CRYPTOGRAPHY_AES_PADDING inPadding
) {

	ACryptographyAES* oCryptography = new ACryptographyAES(inLevel, inMode, inPadding);
	return oCryptography->mEncode(inRawText, inKey, inIv);
}


// -----------
/*!
	\fn QByteArray ACryptographyAES::mDecrypt(ACryptographyAES::AESType inLevel,ACryptographyAES::AESMode inMode,const QByteArray& inRawText,const QByteArray& inKey,const QByteArray& inIv,ACryptographyAES::AESPadding inPadding)

	Doc.
*/

QByteArray ACryptographyAES::mDecrypt(
	_A_ENUMS_CRYPTOGRAPHY_AES_TYPE inLevel,
	_A_ENUMS_CRYPTOGRAPHY_AES_MODE inMode,
	const QByteArray& inRawText,
	const QByteArray& inKey,
	const QByteArray& inIv,
	_A_ENUMS_CRYPTOGRAPHY_AES_PADDING inPadding
) {

	ACryptographyAES* oCryptography = new ACryptographyAES(inLevel, inMode, inPadding);
	return oCryptography->mDecode(inRawText, inKey, inIv);
}


// -----------
/*!
	\fn QByteArray ACryptographyAES::mExpandKey(ACryptographyAES::AESType inLevel,ACryptographyAES::AESMode inMode,const QByteArray& inKey)

	Doc.
*/

QByteArray ACryptographyAES::mExpandKey(
	_A_ENUMS_CRYPTOGRAPHY_AES_TYPE inLevel,
	_A_ENUMS_CRYPTOGRAPHY_AES_MODE inMode,
	const QByteArray& inKey
) {

	ACryptographyAES* oCryptography = new ACryptographyAES(inLevel, inMode);
	return oCryptography->mExpandKey(inKey);
}


// -----------
/*!
	\fn QByteArray ACryptographyAES::mRemovePadding(const QByteArray &inRawText,ACryptographyAES::AESPadding inPadding)

	Doc.
*/

QByteArray ACryptographyAES::mRemovePadding(
	const QByteArray &inRawText,
	_A_ENUMS_CRYPTOGRAPHY_AES_PADDING inPadding
) {

	if (inRawText.isEmpty()) {
		return inRawText;
	}

	QByteArray oOutput(inRawText);
	switch (inPadding) {
		case _A_ENUMS_CRYPTOGRAPHY_AES_PADDING::ZERO:
			while (oOutput.at(oOutput.length()-1) == 0x00) {
				oOutput.remove(oOutput.length()-1, 1);
			}
			break;
		case _A_ENUMS_CRYPTOGRAPHY_AES_PADDING::PKCS7:
			oOutput.remove(oOutput.length() - oOutput.back(),oOutput.back());
			break;
		case _A_ENUMS_CRYPTOGRAPHY_AES_PADDING::ISO: {
				int iMarkerIndex = oOutput.length() - 1;
				for (; iMarkerIndex >= 0; --iMarkerIndex) {
					if (oOutput.at(iMarkerIndex) != 0x00) {
						break;
					}
				}

				if (oOutput.at(iMarkerIndex) == static_cast<char>(0x80)) {
					oOutput.truncate(iMarkerIndex);
				}
				break;
			}
		default: break;
	}

	return oOutput;
}


// -----------
/*!
	\fn void ACryptographyAES::mAddRoundKey(const quint8 inRound, const QByteArray inExpKey)

	This function adds the round key to state.
	The round key is added to the state by an XOR function
*/

void ACryptographyAES::mAddRoundKey(const quint8 inRound, const QByteArray inExpKey) {

	QByteArray::iterator oIteartor = pState->begin();
	for(int i = 0; i < 16; ++i) {
		oIteartor[i] = (quint8)oIteartor[i] ^ (quint8)inExpKey.at(
			inRound * pNb * 4 + (i/4) * pNb + (i%4)
		);
	}
}


// -----------
/*!
	\fn void ACryptographyAES::mSubBytes(void)

	The SubBytes Function Substitutes the values in the state matrix with values in an S-box.
*/

void ACryptographyAES::mSubBytes(void) {

	QByteArray::iterator oIterator = pState->begin();
	for(int i = 0; i < 16; i++) {
		oIterator[i] = mGetSBoxValue((quint8) oIterator[i]);
	}
}


// -----------
/*!
	\fn void ACryptographyAES::mShiftRows(void)

	The ShiftRows() function shifts the rows in the state to the left.
	Each row is shifted with different offset.
	Offset = Row number. So the first row is not shifted.
*/

void ACryptographyAES::mShiftRows(void) {

	QByteArray::iterator oIterator = pState->begin();
	quint8 oTemp;

	oTemp   = (quint8)oIterator[1];
	oIterator[1]  = (quint8)oIterator[5];
	oIterator[5]  = (quint8)oIterator[9];
	oIterator[9]  = (quint8)oIterator[13];
	oIterator[13] = (quint8)oTemp;

	oTemp   = (quint8)oIterator[2];
	oIterator[2]  = (quint8)oIterator[10];
	oIterator[10] = (quint8)oTemp;
	oTemp   = (quint8)oIterator[6];
	oIterator[6]  = (quint8)oIterator[14];
	oIterator[14] = (quint8)oTemp;

	oTemp   = (quint8)oIterator[3];
	oIterator[3]  = (quint8)oIterator[15];
	oIterator[15] = (quint8)oIterator[11];
	oIterator[11] = (quint8)oIterator[7];
	oIterator[7]  = (quint8)oTemp;
}


// -----------
/*!
	\fn void ACryptographyAES::mMixColumns(void)

	MixColumns function mixes the columns of the state matrix optimized!!
*/

void ACryptographyAES::mMixColumns(void) {

	QByteArray::iterator oIterator = pState->begin();
	quint8 oTmp, oTm, oT;

	for(int i = 0; i < 16; i += 4) {

		oT = (quint8)oIterator[i];
		oTmp = (quint8)oIterator[i] ^ (quint8)oIterator[i+1] ^ (quint8)oIterator[i+2] ^ (quint8)oIterator[i+3];

		oTm = mInlineTime((quint8)oIterator[i] ^ (quint8)oIterator[i+1]);
		oIterator[i] = (quint8)oIterator[i] ^ (quint8)oTm ^ (quint8)oTmp;

		oTm = mInlineTime((quint8)oIterator[i+1] ^ (quint8)oIterator[i+2]);
		oIterator[i+1] = (quint8)oIterator[i+1] ^ (quint8)oTm ^ (quint8)oTmp;

		oTm = mInlineTime( (quint8)oIterator[i+2] ^ (quint8)oIterator[i+3]);
		oIterator[i+2] =(quint8)oIterator[i+2] ^ (quint8)oTm ^ (quint8)oTmp;

		oTm = mInlineTime((quint8)oIterator[i+3] ^ (quint8)oT);
		oIterator[i+3] =(quint8)oIterator[i+3] ^ (quint8)oTm ^ (quint8)oTmp;
	}
}


// -----------
/*!
	\fn void ACryptographyAES::mInvSubBytes(void)

	The SubBytes Function Substitutes the values in the state matrix with values in an S-box.
*/

void ACryptographyAES::mInvSubBytes(void) {

	QByteArray::iterator oIterator = pState->begin();
	for(int i = 0; i < 16; ++i) {
		oIterator[i] = mGetSBoxInvert((quint8) oIterator[i]);
	}
}


// -----------
/*!
	\fn void ACryptographyAES::mInvShiftRows(void)

	Doc.
*/

void ACryptographyAES::mInvShiftRows(void) {

	QByteArray::iterator oIterator = pState->begin();
	uint8_t oTemp;

	oTemp   = (quint8)oIterator[13];
	oIterator[13] = (quint8)oIterator[9];
	oIterator[9]  = (quint8)oIterator[5];
	oIterator[5]  = (quint8)oIterator[1];
	oIterator[1]  = (quint8)oTemp;

	oTemp   = (quint8)oIterator[10];
	oIterator[10] = (quint8)oIterator[2];
	oIterator[2]  = (quint8)oTemp;
	oTemp   = (quint8)oIterator[14];
	oIterator[14] = (quint8)oIterator[6];
	oIterator[6]  = (quint8)oTemp;

	oTemp   = (quint8)oIterator[15];
	oIterator[15] = (quint8)oIterator[3];
	oIterator[3]  = (quint8)oIterator[7];
	oIterator[7]  = (quint8)oIterator[11];
	oIterator[11] = (quint8)oTemp;
}


// -----------
/*!
	\fn QByteArray ACryptographyAES::mGetPadding(int inCurrSize, int inAlignment)

	Doc.
*/

QByteArray ACryptographyAES::mGetPadding(int inCurrSize, int inAlignment) {

	int oSize = (inAlignment - inCurrSize % inAlignment) % inAlignment;
	switch(pPadding) {
		case (int)_A_ENUMS_CRYPTOGRAPHY_AES_PADDING::ZERO:
			return QByteArray(oSize, 0x00);
			break;
		case (int)_A_ENUMS_CRYPTOGRAPHY_AES_PADDING::PKCS7:
			if (oSize == 0) {
				oSize = inAlignment;
			}
			return QByteArray(oSize, oSize);
			break;
		case (int)_A_ENUMS_CRYPTOGRAPHY_AES_PADDING::ISO:
			if (oSize > 0) {
				return QByteArray (oSize - 1, 0x00).prepend(0x80);
			}
			break;
		default:
			return QByteArray(oSize, 0x00);
			break;
	}
	return QByteArray();
}


// -----------
/*!
	\fn QByteArray ACryptographyAES::mCipher(const QByteArray &expKey, const QByteArray &in)

	Cipher is the main function that encrypts the PlainText.
*/

QByteArray ACryptographyAES::mCipher(const QByteArray &inExpKey, const QByteArray &inIn) {

	QByteArray oOutput(inIn);
	pState = &oOutput;

	mAddRoundKey(0, inExpKey);

	for(quint8 iRound = 1; iRound < pNr; ++iRound) {
		mSubBytes();
		mShiftRows();
		mMixColumns();
		mAddRoundKey(iRound, inExpKey);
	}

	mSubBytes();
	mShiftRows();
	mAddRoundKey(pNr, inExpKey);

	return oOutput;
}


// -----------
/*!
	\fn QByteArray ACryptographyAES::mInvCipher(const QByteArray &inExpKey, const QByteArray &inIn)

	Doc.
*/

QByteArray ACryptographyAES::mInvCipher(const QByteArray &inExpKey, const QByteArray &inIn) {

	QByteArray oOutput(inIn);
	pState = &oOutput;

	mAddRoundKey(pNr, inExpKey);

	for(quint8 iRound = pNr-1; iRound > 0 ; iRound--){
		mInvShiftRows();
		mInvSubBytes();
		mAddRoundKey(iRound, inExpKey);
		mInvMixColumns();
	}

	mInvShiftRows();
	mInvSubBytes();
	mAddRoundKey(0, inExpKey);

	return oOutput;
}


// -----------
/*!
	\fn void ACryptographyAES::mInvMixColumns(void)

	MixColumns function mixes the columns of the state matrix.
	The method used to multiply may be difficult to understand for the inexperienced.
	Please use the references to gain more information.
*/

void ACryptographyAES::mInvMixColumns(void) {

	QByteArray::iterator oIterator = pState->begin();
	quint8 a,b,c,d;

	for(int i = 0; i < 16; i += 4) {

		a = (quint8) oIterator[i];
		b = (quint8) oIterator[i+1];
		c = (quint8) oIterator[i+2];
		d = (quint8) oIterator[i+3];

		oIterator[i] = (quint8) (
			mInlineMultiply(a, 0x0e) ^ mInlineMultiply(b, 0x0b) ^ \
			mInlineMultiply(c, 0x0d) ^ mInlineMultiply(d, 0x09)
		);
		oIterator[i+1] = (quint8) (
			mInlineMultiply(a, 0x09) ^ mInlineMultiply(b, 0x0e) ^ \
			mInlineMultiply(c, 0x0b) ^ mInlineMultiply(d, 0x0d)
		);
		oIterator[i+2] = (quint8) (
			mInlineMultiply(a, 0x0d) ^ mInlineMultiply(b, 0x09) ^ \
			mInlineMultiply(c, 0x0e) ^ mInlineMultiply(d, 0x0b)
		);
		oIterator[i+3] = (quint8) (
			mInlineMultiply(a, 0x0b) ^ mInlineMultiply(b, 0x0d) ^ \
			mInlineMultiply(c, 0x09) ^ mInlineMultiply(d, 0x0e)
		);
	}
}


// -----------
/*!
	\fn QByteArray ACryptographyAES::mByteXor(const QByteArray &inA, const QByteArray &inB)

	Doc.
*/

QByteArray ACryptographyAES::mByteXor(const QByteArray &inA, const QByteArray &inB) {

	QByteArray::const_iterator oIteratorA = inA.begin();
	QByteArray::const_iterator oIteratorB = inB.begin();
	QByteArray oOutput;

	for(int i = 0; i < std::min(inA.size(), inB.size()); i++) {
		oOutput.insert(i,oIteratorA[i] ^ oIteratorB[i]);
	}

	return oOutput;
}

