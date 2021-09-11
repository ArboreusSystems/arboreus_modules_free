// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 11/09/2021 at 17:52:04
	\endlist
*/
// ----------------------------------------------------------
#ifndef ACRYPTOGRAPHYDATAMODELS_H
#define ACRYPTOGRAPHYDATAMODELS_H

// System includes

// Precompiled includes
#include <acryptographypch.h>

// Application includes
#include <aapplicationdatamodels.h>

// Constants and defintions
#define _A_ENUM_AES_TYPE ARB::AEnumsAESType::AESType
#define _A_ENUM_AES_MODE ARB::AEnumsAESMode::AESMode
#define _A_ENUM_AES_PADDING ARB::AEnumsAESPadding::AESPadding


// Namespace
namespace ARB {

struct ACryptographySignReply {

	_A_ENUM_REPLY_STATUS Status = _A_ENUM_REPLY_STATUS::Error;
	QByteArray Datumn = {};
};

struct ACryptographyAES256 {

	int Nk = 8;
	int KeyLength = 32;
	int Nr = 14;
	int ExpandedKey = 240;
};

struct ACryptographyAES192 {

	int Nk = 6;
	int KeyLength = 24;
	int Nr = 12;
	int ExpandedKey = 209;
};

struct ACryptographyAES128 {

	int Nk = 4;
	int KeyLength = 16;
	int Nr = 10;
	int ExpandedKey = 176;
};

class AEnumsAESType: public QObject {

	Q_OBJECT

	public:

		enum class AESType: int {AES_128, AES_192, AES_256};
		Q_ENUM(AESType)
};

class AEnumsAESMode: public QObject {

	Q_OBJECT

	public:

		enum class AESMode: int {ECB,CBC,CFB,OFB};
		Q_ENUM(AESMode)
};

class AEnumsAESPadding: public QObject {

	Q_OBJECT

	public:

		enum class AESPadding: int {ZERO, PKCS7, ISO};
		Q_ENUM(AESPadding)
};

} // namespace ARB

#endif // ACRYPTOGRAPHYDATAMODELS_H
