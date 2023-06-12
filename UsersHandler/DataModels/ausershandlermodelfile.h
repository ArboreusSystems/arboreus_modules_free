// ----------------------------------------------------------
/*!
    \headerfile
    \title
    \brief Template file files/cppheader/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 12/06/2023 at 20:11:03
    \endlist
*/
// ----------------------------------------------------------
#ifndef AUSERSHANDLERMODELFILE_H
#define AUSERSHANDLERMODELFILE_H

// System includes

// Precompiled includes
#include <ausershandlerpch.h>

// Application includes

// Constants and defintions
#define _A_ENUMS_USERS_HANDLER_FILE_ENCODING_TYPE ARB::AEnumsUsersHandlerFileEncodingType::EncodingType


// Namespace
namespace ARB {

// Class definitions
class AEnumsUsersHandlerFileEncodingType : public QObject {

	Q_OBJECT

	public:

		enum class EncodingType: int {

			Undefined = 0,
			Base64 = 1,
			AES256 = 2
		};
		Q_ENUM(EncodingType)
};

} // namespace ARB

Q_DECLARE_METATYPE(_A_ENUMS_USERS_HANDLER_FILE_ENCODING_TYPE)


// Namespace
namespace ARB {

class AUsersHandlerModelFile {

	public:

		QString Name = "NoDefinedName";
		bool IsEncoded = false;
		_A_ENUMS_USERS_HANDLER_FILE_ENCODING_TYPE EncodingType = _A_ENUMS_USERS_HANDLER_FILE_ENCODING_TYPE::Undefined;
		QByteArray Data = {};

		explicit AUsersHandlerModelFile(void) {}
		virtual ~AUsersHandlerModelFile(void) {}
};

} // namespace ARB

Q_DECLARE_METATYPE(ARB::AUsersHandlerModelFile)

#endif // AUSERSHANDLERMODELFILE_H
