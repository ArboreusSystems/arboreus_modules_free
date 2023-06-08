// ----------------------------------------------------------
/*!
    \headerfile
    \title
    \brief Template file files/cppheader/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 05/06/2023 at 19:15:53
    \endlist
*/
// ----------------------------------------------------------
#ifndef AMANIFESTDATAMODELS_H
#define AMANIFESTDATAMODELS_H

// System includes

// Precompiled includes
#include <amanifestpch.h>

// Application includes

// Constants and defintions
#define _A_ENUM_MANIFEST_REPLY_TYPE ARB::AManifestReplyType::AManifestReplyTypeEnum
#define _A_ENUM_MANIFEST_ROW_TYPE ARB::AManifestRowType::AManifestRowTypeEnum

// Namespace
namespace ARB {

class AManifestReplyType: public QObject {

	public:

		enum class AManifestReplyTypeEnum: int {

			Error, Ok, NoKey, WrongPath
		};
		Q_ENUM(AManifestReplyTypeEnum)
};

} // namespace ARB


// Namespace
namespace ARB {

class AManifestRowType: public QObject {

	public:

		enum class AManifestRowTypeEnum: int {

			Error, Public, Encoded, Base64
		};
		Q_ENUM(AManifestRowTypeEnum)

		static QString mToString(_A_ENUM_MANIFEST_ROW_TYPE inType) {

			QString oOutput = "Error";

			switch (inType) {
				case _A_ENUM_MANIFEST_ROW_TYPE::Public: oOutput = "Public";break;
				case _A_ENUM_MANIFEST_ROW_TYPE::Encoded: oOutput = "Encoded";break;
				case _A_ENUM_MANIFEST_ROW_TYPE::Base64: oOutput = "Base64";break;
				default: break;
			}

			return oOutput;
		}
};

} // namespace ARB


// Namespace
namespace ARB {

class AManifestReply {

	public:

		AManifestReply(void) {}
		virtual ~AManifestReply(void) {}

		_A_ENUM_MANIFEST_REPLY_TYPE Type = _A_ENUM_MANIFEST_REPLY_TYPE::Error;
		QVariant Data = {};
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::AManifestReply)


// Namespace
namespace ARB {

class AManifestProperties {

	public:

		AManifestProperties(void) {}
		virtual ~AManifestProperties(void) {}

		QString Path = "NoDefinedPath";
		QString Name = "NoDefinedName";
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::AManifestProperties)


// Namespace
namespace ARB {

class AManifestRowProperties {

	public:

		AManifestRowProperties(void) {}
		virtual ~AManifestRowProperties(void) {}

		_A_ENUM_MANIFEST_ROW_TYPE Type = _A_ENUM_MANIFEST_ROW_TYPE::Error;
		QString Key = "NoDefinedKey";
		QVariant Value = "NoDefinedValue";
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::AManifestRowProperties)



#endif // AMANIFESTDATAMODELS_H
