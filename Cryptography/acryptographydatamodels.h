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
#define _A_ENUMS_CRYPTOGRAPHY_AES_TYPE ARB::AEnumsCryptographyAESType::AESType
#define _A_ENUMS_CRYPTOGRAPHY_AES_MODE ARB::AEnumsCryptographyAESMode::AESMode
#define _A_ENUMS_CRYPTOGRAPHY_AES_PADDING ARB::AEnumsCryptographyAESPadding::AESPadding


// Namespace
namespace ARB {

class AEnumsCryptographyAESType: public QObject {

	Q_OBJECT

	public:

		enum class AESType: int {
			AES_128 = 0,
			AES_192 = 1,
			AES_256 = 2
		};
		Q_ENUM(AESType)
};

class AEnumsCryptographyAESMode: public QObject {

	Q_OBJECT

	public:

		enum class AESMode: int {
			ECB = 0,
			CBC = 1,
			CFB = 2,
			OFB = 3
		};
		Q_ENUM(AESMode)
};

class AEnumsCryptographyAESPadding: public QObject {

	Q_OBJECT

	public:

		enum class AESPadding: int {
			ZERO = 0,
			PKCS7 = 1,
			ISO = 2
		};
		Q_ENUM(AESPadding)
};

} // namespace ARB


// Namespace
namespace ARB {

class ACryptographySignReply {

	public:

		_A_ENUMS_APPLICATION_REPLY_STATUS Status = _A_ENUMS_APPLICATION_REPLY_STATUS::Error;
		QByteArray Datumn = {};

		explicit ACryptographySignReply(void) {}
		virtual ~ACryptographySignReply(void) {}
};

class ACryptographyAES256 {

	public:

		int Nk = 8;
		int KeyLength = 32;
		int Nr = 14;
		int ExpandedKey = 240;

		explicit ACryptographyAES256(void) {}
		virtual ~ACryptographyAES256(void) {}
};

class ACryptographyAES192 {

	public:

		int Nk = 6;
		int KeyLength = 24;
		int Nr = 12;
		int ExpandedKey = 209;

		explicit ACryptographyAES192(void) {}
		virtual ~ACryptographyAES192(void) {}
};

class ACryptographyAES128 {

	public:

		int Nk = 4;
		int KeyLength = 16;
		int Nr = 10;
		int ExpandedKey = 176;

		explicit ACryptographyAES128(void) {}
		virtual ~ACryptographyAES128(void) {}
};

} // namespace ARB

#endif // ACRYPTOGRAPHYDATAMODELS_H
