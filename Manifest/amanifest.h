// ----------------------------------------------------------
/*!
    \headerfile AManifest
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 05/06/2023 at 08:50:52
    \endlist
*/
// ----------------------------------------------------------

#ifndef AMANIFEST_H
#define AMANIFEST_H

// System includes

// Precompiled includes
#include <amanifestpch.h>

// Application includes
#include <aloggerglobal.h>
#include <amanifestdatamodels.h>
#include <amanifestmetatypes.h>
#include <ajson.h>
#include <adir.h>
#include <afile.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AManifest : public QObject {

	Q_OBJECT

	public:

		bool pIsLoadedPublic = false;
		bool pIsLoadedPrivate = false;

		explicit AManifest(QObject* parent = nullptr);
		virtual ~AManifest(void);

		void mInitWithFile(AManifestFile inFile);
		void mInitWithData(QString inValue,QVariantList inData,AManifestFile inFile);
		bool mIsKey(QString inKey);
		AManifestData mGetDataByKey(QString inKey);
		QVariant mGetValueByKey(QString inKey);
		AManifestReply mAddDataSystem(QString inKey,QVariant inDataValue);
		AManifestReply mAddDataPublic(QString inKey,QVariant inDataValue);
		AManifestReply mAddDataPrivate(QString inValue,QString inKey,QVariant inDataValue);
		AManifestReply mRemoveFromSystem(QString inKey);
		AManifestReply mRemoveFromPublic(QString inKey);
		AManifestReply mRemoveFromPrivate(QString inValue,QString inKey);
		AManifestReply mLoadSystem(void);
		AManifestReply mLoadPublic(void);
		AManifestReply mLoadPrivate(QString inValue);
		void mUnloadPublic(void);
		void mUnloadPrivate(void);

	private:

		AManifestFile pFile;
		QMap<QString,AManifestData> pData = {};

		void mAddData(QString inKey,AManifestData inData);
		QVariantMap mSelectData(_A_ENUMS_MANIFEST_DATA_TYPE inType);
		void mUnloadData(_A_ENUMS_MANIFEST_DATA_TYPE inType);
		void mLoadData(_A_ENUMS_MANIFEST_DATA_TYPE inType,QJsonObject inManifest);
		AManifestReply mSaveSystem(void);
		AManifestReply mSavePublic(void);
		AManifestReply mSavePrivate(QString inValue);
};

} // namespace ARB

#endif // AMANIFEST_H
