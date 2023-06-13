// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 14/03/2023 at 13:21:34
	\endlist
*/
// ----------------------------------------------------------
#ifndef AUSERSHANDLERDATAMODELS_H
#define AUSERSHANDLERDATAMODELS_H

// System includes

// Precompiled includes
#include <ausershandlerpch.h>

// Application includes
#include <ausershandlermodelfile.h>
#include <ausershandlermodeluser.h>

// Constants and defintions
#define _A_ENUMS_USERS_HANDLER_REPLY_STATUS ARB::AEnumsUsersHandlerReplyStatus::ReplyStatus


// Namespace
namespace ARB {

// Class definitions
class AEnumsUsersHandlerReplyStatus : public QObject {

	Q_OBJECT

	public:

		enum class ReplyStatus: int {

			Error = 0,
			Ok = 1,
			Existed = 2,
			NotExisted = 3
		};
		Q_ENUM(ReplyStatus)
};

} // namespace ARB

//Q_DECLARE_METATYPE(_A_ENUMS_USERS_HANDLER_REPLY_STATUS)


// Namespace
namespace ARB {

class AUsersHandlerReply {

	public:

		_A_ENUMS_USERS_HANDLER_REPLY_STATUS Status = _A_ENUMS_USERS_HANDLER_REPLY_STATUS::Error;
		QVariant Data = "NoData";

        QVariantMap mToVariantMap(void) {

            QVariantMap oOutput;
            oOutput.insert("Status",QVariant::fromValue(Status));
            oOutput.insert("Data",Data);

            return oOutput;
        }
};

} // Namespace

Q_DECLARE_METATYPE(ARB::AUsersHandlerReply)

#endif // AUSERSHANDLERDATAMODELS_H
