// ----------------------------------------------------------
/*!
    \headerfile
    \title
    \brief Template file files/cppheader/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 09/06/2023 at 15:59:24
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
#define _A_ENUMS_MANIFEST_REPLY_TYPE ARB::AEnumsManifestReplyType::ReplyType


// Namespace
namespace ARB {

class AEnumsManifestDataType: public QObject {

	Q_OBJECT

	public:

		enum class DataType: int {

			Public = 0,
			Private = 1
		};
		Q_ENUM(DataType)
};

} // namespace ARB

Q_DECLARE_METATYPE(_A_ENUMS_MANIFEST_DATA_TYPE)


// Namespace
namespace ARB {

class AEnumsManifestReplyType: public QObject {

	Q_OBJECT

	public:

		enum class ReplyType: int {

			Error = 0,
			Ok = 1,
			NoKey = 2
		};
		Q_ENUM(ReplyType)
};

} // namespace ARB

Q_DECLARE_METATYPE(_A_ENUMS_MANIFEST_REPLY_TYPE)


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

		_A_ENUMS_MANIFEST_REPLY_TYPE Type = _A_ENUMS_MANIFEST_REPLY_TYPE::Error;
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

		explicit AManifestFile(void) {}
		virtual ~AManifestFile(void) {}

		QString mPath(void) {

			QString oPath = this->Dir + "/" + this->Name;
			return oPath;
		}
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::AManifestFile)


#endif // AMANIFESTDATAMODELS_H
