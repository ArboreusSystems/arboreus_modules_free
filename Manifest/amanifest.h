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
#include <afile.h>
#include <adir.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AManifest : public QObject {

	Q_OBJECT

	public:

		explicit AManifest(QObject* parent = nullptr);
		virtual ~AManifest(void);

		void mInitWithFile(AManifestFile inFile);
		AManifestReply mLoadFromFilePublic(void);
		AManifestReply mLoadFromFilePrivate(QString inValue);
		AManifestReply mSaveToFile(void);
		void mWriteByKeyPublic(QString inKey, QVariant inValue);
		void mWriteByKeyPrivate(QString inKey, QVariant inValue);
		void mWriteByKey(QString inKey, QVariant inValue, _A_ENUMS_MANIFEST_DATA_TYPE inType);
		AManifestReply mReadByKey(QString inKey);
		bool mIsKey(QString inKey);

	private:

		AManifestFile pFile;
		QMap<QString,AManifestData> pData = {};
};

} // namespace ARB

#endif // AMANIFEST_H
