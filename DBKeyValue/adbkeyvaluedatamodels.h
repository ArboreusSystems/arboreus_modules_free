// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 09/03/2023 at 13:56:08
	\endlist
*/
// ----------------------------------------------------------
#ifndef ADBKEYVALUEDATAMODELS_H
#define ADBKEYVALUEDATAMODELS_H

// System includes

// Precompiled includes
#include <ausershandlerpch.h>

// Application includes
#include <adbdatamodels.h>

// Constants and defintions
#define _A_ENUMS_DB_KEY_VALUE_REPLY_STATUS ARB::AEnumsDBKeyValueReplyStatus::ReplyStatus


// Namespace
namespace ARB {

class AEnumsDBKeyValueReplyStatus: public QObject {

	Q_OBJECT

	public:

		enum class ReplyStatus: int {

			Error = 0,
			Ok = 1,
			NotExisted = 2,
			NotDefined = 3
		};
		Q_ENUM(ReplyStatus)
};

} // namespace ARB


// Namespace
namespace ARB {

class ADBKeyValueProperties: public ADBSqliteCipherProperties  {

	public:

		QString NameTable = "NoDefinedNameTable";
		bool Encrypted = false;

		explicit ADBKeyValueProperties(QObject* parent = nullptr) : ADBSqliteCipherProperties(parent) {}
		virtual ~ADBKeyValueProperties() {}

		void mCopy(ADBKeyValueProperties* inProperties) {

			inProperties->NameTable = this->NameTable;
			inProperties->Encrypted = this->Encrypted;
			inProperties->Value = this->Value;
			inProperties->Name = this->Name;
			inProperties->Path = this->Path;
		}
};

} // namespace ARB
Q_DECLARE_METATYPE(ARB::ADBKeyValueProperties)


// Namespace
namespace ARB {

class ADBKeyValueReply {

	public:

		_A_ENUMS_DB_KEY_VALUE_REPLY_STATUS Status = _A_ENUMS_DB_KEY_VALUE_REPLY_STATUS::NotDefined;
		QVariant Data = "NoData";

		explicit ADBKeyValueReply() {}
		virtual ~ADBKeyValueReply() {}
};

} // namespace ARB
Q_DECLARE_METATYPE(ARB::ADBKeyValueReply)

#endif // ADBKEYVALUEDATAMODELS_H
