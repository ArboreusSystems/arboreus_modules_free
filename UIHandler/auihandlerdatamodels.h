// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 13/03/2023 at 12:52:21
	\endlist
*/
// ----------------------------------------------------------
#ifndef AUIHANDLERDATAMODELS_H
#define AUIHANDLERDATAMODELS_H

// System includes

// Precompiled includes
#include <auihandlerpch.h>

// Application includes

// Constants and defintions
#define _A_ENUMS_UI_HANDLER_REPLY_STATUS ARB::AEnumsUIHandlerReplyStatus::ReplyStatus


// Namespace
namespace ARB {

// Class definitions
class AEnumsUIHandlerReplyStatus : public QObject {

	Q_OBJECT

	public:

		enum class ReplyStatus: int {

			Error = 0,
			Ok = 1
		};
		Q_ENUM(ReplyStatus)
};

} // namespace ARB

Q_DECLARE_METATYPE(_A_ENUMS_UI_HANDLER_REPLY_STATUS)


// Namespace
namespace ARB {

class AUIHandlerReply {

	public:

		_A_ENUMS_UI_HANDLER_REPLY_STATUS Status = _A_ENUMS_UI_HANDLER_REPLY_STATUS::Error;
		QVariant Data = QVariant("NoDefinedData");

		QVariantMap mToVariantMap(void) {

			QVariantMap oOutput;
			oOutput.insert("Status",QVariant::fromValue(Status));
			oOutput.insert("Data",Data);
			return oOutput;
		}
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::AUIHandlerReply)

#endif // AUIHANDLERDATAMODELS_H
