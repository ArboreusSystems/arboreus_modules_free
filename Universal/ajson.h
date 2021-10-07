// ----------------------------------------------------------
/*!
	\headerfile AJson
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 23/07/2021 at 19:31:23
	\endlist
*/
// ----------------------------------------------------------

#ifndef AJSON_H
#define AJSON_H

// System includes

// Precompiled includes
#include <auniversalpch.h>

// Application includes
#include <aloggerglobal.h>
#include <auniversaldatamodels.h>
#include <acryptography.h>
#include <acryptographyaes.h>

// Constants and definitions
#define _A_JSON_DEFAULT_ENCRYPTION_OBJECT ACryptographyAES oEncryption( \
	_A_ENUM_AES_TYPE::AES_256, \
	_A_ENUM_AES_MODE::CBC \
)


// Namespace
namespace ARB {

// Class definitions
class AJson : public QObject {

	Q_OBJECT

	public:

		explicit AJson(QObject* parent = nullptr);
		virtual ~AJson(void);

		static bool mToFileFromObject(QString inPath,QJsonObject inObject);
		static bool mToFileFromDocument(QString inPath,QJsonDocument inDocument);
		static bool mToFileFromMap(QString inPath,QVariantMap inMap);
		static bool mToFileFromHash(QString inPath,QVariantHash inHash);
		static AJsonFileReply mFromFile(QString inPath);
		static bool mEncodeFromObject(QString inValue,QString inPath,QJsonObject inObject);
		static bool mEncodeFromDocument(QString inValue,QString inPath,QJsonDocument inDocument);
		static bool mEncodeFromMap(QString inValue,QString inPath,QVariantMap inMap);
		static bool mEncodeFromHash(QString inValue,QString inPath,QVariantHash inHash);
		static AJsonFileReply mDecodeFromFile(QString inValue,QString inPath);
		static bool mChangeValue(QString inOldValue,QString inNewValue,QString inPath);
		static bool mRemoveValue(QString inValue,QString inPath);
};

} // namespace ARB

#endif // AJSON_H
