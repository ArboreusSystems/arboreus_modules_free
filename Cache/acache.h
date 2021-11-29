// ----------------------------------------------------------
/*!
	\headerfile ASession
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 15/11/2021 at 18:23:56
	\endlist
*/
// ----------------------------------------------------------

#ifndef ACACHE_H
#define ACACHE_H

// System includes

// Precompiled includes
#include <acachepch.h>

// Application includes
#include <acachedatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Classes
class ABackend;

// Class definitions
class ACache : public QObject {

	Q_OBJECT

	public:

		explicit ACache(QObject* parent = nullptr);
		virtual ~ACache(void);

		void mInit(void);

		ACacheReply mPut(QString inKey,QVariant inValue);
		ACacheReply mGet(QString inKey);
		ACacheReply mGetOut(QString inKey);
		ACacheReply mRemove(QString inKey);

	public slots:

		bool mIsKey(QString inKey);

		QVariantMap mPutInCache(QString inKey,QVariant inValue);
		QVariantMap mGetFromCache(QString inKey);
		QVariantMap mGetOutFromCache(QString inKey);
		QVariantMap mRemoveFromCache(QString inKey);

		bool mIsObject(QString inKey);
		bool mIsKeyInObject(QString inObjectID, QString inKey);

		QVariantMap mCreateObject(QString inObjectID);
		QVariantMap mCreateObjectWithTemplate(QString inObjectID,QVariantMap inTemplate);
		QVariantMap mPutInObject(QString inObjectID, QString inKey, QVariant inValue);
		QVariantMap mGetObject(QString inObjectID);
		QVariantMap mGetOutObject(QString inObjectID);
		QVariantMap mGetFromObject(QString inObjectID, QString inKey);
		QVariantMap mGetOutFromObject(QString inObjectID, QString inKey);
		QVariantMap mRemoveObject(QString inObjectID);

	signals:

		void sgInitiated(void);

	private:

		ABackend* pBackend = nullptr;
		QHash<QString,QVariant> pCache = {};
};

} // namespace ARB

#endif // ACACHE_H
