// ----------------------------------------------------------
/*!
	\class ASession
	\title
	\brief Template file classes/cpp/file.cpp

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 15/11/2021 at 18:23:56
	\endlist
*/
// ----------------------------------------------------------

// Class header
#include "acache.h"

// Forwarded classes
#include <abackend.h>

// Namespace
using namespace ARB;


// -----------
/*!
	\fn

	Doc.
*/

ACache::ACache(QObject* parent) : QObject(parent) {

	_A_DEBUG << "ACache created";
}


// -----------
/*!
	\fn

	Doc.
*/

ACache::~ACache(void) {

	_A_DEBUG << "ACache deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

void ACache::mInit(void) {

	pBackend = &ABackend::mInstance();

	_A_DEBUG << "ACache initiated";

	emit sgInitiated();
}


// -----------
/*!
	\fn

	Doc.
*/

ACacheReply ACache::mPutHandler(QString inKey, QVariant inValue) {

	ACacheReply oOutput;

	pCache.insert(inKey,inValue);
	oOutput.Status = this->mIsKey(inKey);

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ACacheReply ACache::mGetHandler(QString inKey) {

	ACacheReply oOutput;

	if (this->mIsKey(inKey)) {
		oOutput.Status = true;
		oOutput.Data = pCache.value(inKey);
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ACacheReply ACache::mGetOutHandler(QString inKey) {

	ACacheReply oOutput;

	if (this->mIsKey(inKey)) {

		QVariant oValue = pCache.value(inKey);
		pCache.remove(inKey);

		if (!this->mIsKey(inKey)) {
			oOutput.Status = true;
			oOutput.Data = oValue;
		}
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

ACacheReply ACache::mRemoveHandler(QString inKey) {

	ACacheReply oOutput;

	if (this->mIsKey(inKey)) {
		pCache.remove(inKey);
		if (this->mIsKey(inKey)) {
			oOutput.Status = true;
		}
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

bool ACache::mIsKey(QString inKey) {

	return pCache.contains(inKey);
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ACache::mPut(QString inKey, QVariant inValue) {

	return this->mPutHandler(inKey,inValue).mToVariantMap();
}




// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ACache::mGet(QString inKey) {

	return this->mGetHandler(inKey).mToVariantMap();
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ACache::mGetOut(QString inKey) {

	return this->mGetOutHandler(inKey).mToVariantMap();
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ACache::mRemove(QString inKey) {

	return this->mRemoveHandler(inKey).mToVariantMap();
}


// -----------
/*!
	\fn

	Doc.
*/

bool ACache::mIsObject(QString inKey) {

	if (this->mIsKey(inKey)) {
		QVariant oObject = pCache.value(inKey);
		if (strcmp(oObject.typeName(),"QVariantMap") == 0) {
			return true;
		}
	}

	return false;
}


// -----------
/*!
	\fn

	Doc.
*/

bool ACache::mIsKeyInObject(QString inObjectID, QString inKey) {

	if (this->mIsKey(inObjectID)) {

		QVariant oObject = pCache.value(inObjectID);

		if (strcmp(oObject.typeName(),"QVariantMap") == 0) {
			QVariantMap oObjectMap = qvariant_cast<QVariantMap>(oObject);
			QString oErrorValue = "NoValue";
			QVariant oValue = oObjectMap.value(inKey,oErrorValue);
			if (oValue != oErrorValue) return true;
		}
	}

	return false;
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ACache::mCreateObject(QString inObjectID) {

	QVariantMap oTemplate = {};
	return this->mPutHandler(inObjectID,oTemplate).mToVariantMap();
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ACache::mCreateObjectWithTemplate(QString inObjectID, QVariantMap inTemplate) {

	return this->mPutHandler(inObjectID,inTemplate).mToVariantMap();
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ACache::mPutInObject(QString inObjectID, QString inKey, QVariant inValue) {

	ACacheReply oOutput;

	if (this->mIsKey(inObjectID)) {

		QVariant oObject = pCache.value(inObjectID);

		if (strcmp(oObject.typeName(),"QVariantMap") == 0) {
			QVariantMap oObjectMap = qvariant_cast<QVariantMap>(oObject);
			oObjectMap.insert(inKey,inValue);
			pCache.insert(inObjectID,oObjectMap);
			oOutput.Status = true;
		}
	}

	return oOutput.mToVariantMap();
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ACache::mGetObject(QString inObjectID) {

	ACacheReply oOutput;

	if (this->mIsKey(inObjectID)) {

		QVariant oObject = pCache.value(inObjectID);

		if (strcmp(oObject.typeName(),"QVariantMap") == 0) {
			oOutput.Status = true;
			oOutput.Data = oObject;
		}
	}

	return oOutput.mToVariantMap();
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ACache::mGetOutObject(QString inObjectID) {

	ACacheReply oOutput;

	if (this->mIsKey(inObjectID)) {

		QVariant oObject = pCache.value(inObjectID);

		if (strcmp(oObject.typeName(),"QVariantMap") == 0) {
			oOutput.Status = true;
			oOutput.Data = oObject;
			pCache.remove(inObjectID);
		}
	}

	return oOutput.mToVariantMap();
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ACache::mGetFromObject(QString inObjectID, QString inKey) {

	ACacheReply oOutput;

	if (this->mIsKey(inObjectID)) {

		QVariant oObject = pCache.value(inObjectID);

		if (strcmp(oObject.typeName(),"QVariantMap") == 0) {
			QVariantMap oObjectMap = qvariant_cast<QVariantMap>(oObject);
			QString oErrorValue = "NoValue";
			QVariant oValue = oObjectMap.value(inKey,oErrorValue);
			if (oValue != oErrorValue) {
				oOutput.Status = true;
				oOutput.Data = oValue;
			}
		}
	}

	return oOutput.mToVariantMap();
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ACache::mGetOutFromObject(QString inObjectID, QString inKey) {

	ACacheReply oOutput;

	if (this->mIsKey(inObjectID)) {

		QVariant oObject = pCache.value(inObjectID);

		if (strcmp(oObject.typeName(),"QVariantMap") == 0) {
			QVariantMap oObjectMap = qvariant_cast<QVariantMap>(oObject);
			QString oErrorValue = "NoValue";
			QVariant oValue = oObjectMap.value(inKey,oErrorValue);
			if (oValue != oErrorValue) {
				oOutput.Status = true;
				oOutput.Data = oValue;
				oObjectMap.remove(inKey);
				pCache.insert(inObjectID,oObjectMap);
			}
		}
	}

	return oOutput.mToVariantMap();
}


// -----------
/*!
	\fn

	Doc.
*/

QVariantMap ACache::mRemoveObject(QString inObjectID) {

	return this->mRemoveHandler(inObjectID).mToVariantMap();
}
