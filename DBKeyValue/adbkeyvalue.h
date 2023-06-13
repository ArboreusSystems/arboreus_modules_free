// ----------------------------------------------------------
/*!
	\headerfile ADBKeyValue
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 09/03/2023 at 13:49:01
	\endlist
*/
// ----------------------------------------------------------

#ifndef ADBKEYVALUE_H
#define ADBKEYVALUE_H

// System includes

// Precompiled includes
#include <ausershandlerpch.h>

// Application includes
#include <aloggerglobal.h>
#include <adbsqlitecipher.h>
#include <adbkeyvaluedatamodels.h>
#include <adbkeyvaluemetatypes.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADBKeyValue : public QObject {

	Q_OBJECT

	public:

		explicit ADBKeyValue(QObject* parent = nullptr);
		virtual ~ADBKeyValue(void);

		bool mInit(ADBKeyValueProperties inProperties);
		bool mIsKey(QString inKey);
		ADBKeyValueReply mRead(QString inKey);
		ADBKeyValueReply mReadAll(void);
		ADBKeyValueReply mWrite(QString inKey,QVariant inValue);

	private:

		ADBSqliteCipher* pDB = nullptr;
		ADBKeyValueProperties* pProperties = nullptr;
};

} // namespace ARB

#endif // ADBKEYVALUE_H
