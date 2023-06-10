// ----------------------------------------------------------
/*!
    \headerfile
    \title
    \brief Template file files/cppheader/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 10/06/2023 at 12:52:10
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
#define _A_ENUMS_MANIFEST_DATA_TYPE ARB::AEnumsManifestDataType::DataType
#define _A_ENUMS_MANIFEST_REPLY_STATUS ARB::AEnumsManifestReplyStatus::ReplyStatus


// Namespace
namespace ARB {

class AEnumsManifestDataType: public QObject {

	Q_OBJECT

	public:

		enum class DataType: int {

			System = 0,
			Public = 1,
			Private = 2
		};
		Q_ENUM(DataType)
};

} // namespace ARB

Q_DECLARE_METATYPE(_A_ENUMS_MANIFEST_DATA_TYPE)


// Namespace
namespace ARB {

class AEnumsManifestReplyStatus: public QObject {

	Q_OBJECT

	public:

		enum class ReplyStatus: int {

			Error = 0,
			Ok = 1,
			NoKey = 2,
		};
		Q_ENUM(ReplyStatus)
};

} // namespace ARB

Q_DECLARE_METATYPE(_A_ENUMS_MANIFEST_REPLY_STATUS)


// Namespace
namespace ARB {

class AManifestData {

	public:

		_A_ENUMS_MANIFEST_DATA_TYPE Type = _A_ENUMS_MANIFEST_DATA_TYPE::Public;
		QVariant Data = "NoData";

		explicit AManifestData(void) {}
		virtual ~AManifestData(void) {}
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::AManifestData)


// Namespace
namespace ARB {

class AManifestReply {

	public:

		_A_ENUMS_MANIFEST_REPLY_STATUS Status = _A_ENUMS_MANIFEST_REPLY_STATUS::Error;
		QVariant Data = "NoData";

		explicit AManifestReply(void) {}
		virtual ~AManifestReply(void) {}
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::AManifestReply)


// Namespace
namespace ARB {

class AManifestFile {

	public:

		QString Dir = "NoDefinedDir";
		QString Name = "NoDefinedName";
		QMap<_A_ENUMS_MANIFEST_DATA_TYPE,QString> Aliases = {};
		bool EncodeBase64 = false;

		explicit AManifestFile(void) {

			this->mSetAliasPrivate("Private");
			this->mSetAliasPublic("Public");
		}

		virtual ~AManifestFile(void) {}

		QString mPath(void) {

			QString oPath = this->Dir + "/" + this->Name;
			return oPath;
		}

		QString mPathPublic(void) {

			QString oFileName = this->Name + "." + Aliases.value(_A_ENUMS_MANIFEST_DATA_TYPE::Public);
			QString oPath = this->Dir + "/" + oFileName;
			return oPath;
		}

		QString mPathPrivate(void) {

			QString oFileName = this->Name + "." + Aliases.value(_A_ENUMS_MANIFEST_DATA_TYPE::Private);
			QString oPath = this->Dir + "/" + oFileName;
			return oPath;
		}

		void mSetAlias(_A_ENUMS_MANIFEST_DATA_TYPE inType,QString inAlias) {

			Aliases.insert(inType,inAlias);
		}

		void mSetAliasPrivate(QString inAlias) {

			this->mSetAlias(_A_ENUMS_MANIFEST_DATA_TYPE::Private,inAlias);
		}

		void mSetAliasPublic(QString inAlias) {

			this->mSetAlias(_A_ENUMS_MANIFEST_DATA_TYPE::Public,inAlias);
		}
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::AManifestFile)

#endif // AMANIFESTDATAMODELS_H
