// ----------------------------------------------------------
/*!
	\headerfile AUsersHandlerUserData
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 10/03/2023 at 13:53:45
	\endlist
*/
// ----------------------------------------------------------

#ifndef AUSERSHANDLERUSERDATA_H
#define AUSERSHANDLERUSERDATA_H

// System includes

// Precompiled includes
#include <ausershandlerpch.h>

// Application includes
#include <aloggerglobal.h>

// Constants and definitions
#define _A_USER_DATA_NO_KEY QString("<<NoKey>>")
#define _A_USER_DATA_NAME_ID "ID"
#define _A_USER_DATA_NAME_VALUE_ADDON "ValueAddon"


// Namespace
namespace ARB {

// Class definitions
class AUsersHandlerUserData : public QVariantMap {

	public:

		explicit AUsersHandlerUserData(QVariantMap inData);
		explicit AUsersHandlerUserData(void);
		virtual ~AUsersHandlerUserData(void);

		QString mGetID(void);
		QString mGetValueAddon(void);

	private:

		void mLoadData(QVariantMap inData);
};

} // namespace ARB

#endif // AUSERSHANDLERUSERDATA_H
