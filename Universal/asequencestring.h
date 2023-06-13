// ----------------------------------------------------------
/*!
	\headerfile ASequenceString
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 11/09/2021 at 18:02:00
	\endlist
*/
// ----------------------------------------------------------

#ifndef ASEQUENCESTRING_H
#define ASEQUENCESTRING_H

// System includes

// Precompiled includes
#include <auniversalpch.h>

// Application includes
#include <auniversaldatamodels.h>
#include <arandom.h>
#include <aloggerglobal.h>
#include <auniversalmetatypes.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ASequenceString : public QObject {

	Q_OBJECT

	public:

		explicit ASequenceString(QObject* parent = nullptr);
		virtual ~ASequenceString(void);

		static QString mRandomMatrix(int inWidth,int inHeight);
		static QString mRandomMatrix(int inWidth,int inHeight,QString inDictionary);
		static QString mRandomMatrixQuoted(int inWidth,int inHeight);
		static QString mRandomMatrixQuoted(int inWidth,int inHeight,QString inDictionary);
		static QString mRandom(int inLength);
		static QString mRandom(int inLength,QString inDictionary);
		static QString mValue(QString inValue);
		static QString mValue(int inLength,QString inValue);
		static QString mValue(QString inExtention,int inLength,QString inValue);
		static QString mMd4ID(void);
		static QString mMd4FromQString(QString inString);
		static QString mMd5ID(void);
		static QString mMd5FromQString(QString inString);
		static QString mDictionary(_A_ENUMS_DICTIONARY_TYPE inType);
		static QString mShake(QString inString);
};

} // namespace ARB

#endif // ASEQUENCESTRING_H
