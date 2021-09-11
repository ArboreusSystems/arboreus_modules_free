// ----------------------------------------------------------
/*!
	\headerfile aDir
	\title
	\brief Template file classes/cpp/file.h

	\list
		\li @notice Template file classes/file.h
		\li @copyright Arboreus (http://arboreus.systems)
		\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
		\li @created 08/09/2019 at 11:53:41
	\endlist
*/
// ----------------------------------------------------------

#ifndef ADIR_H
#define ADIR_H

// System includes

// Precompiled includes
#include <auniversalpch.h>

// Application includes

namespace ARB {

class ADir : public QObject {

	Q_OBJECT

	public:

		explicit ADir(QObject* parent = nullptr);
		virtual ~ADir(void);

		static bool mEnsure(QString inPath);
		static bool mRemoveRecursively(QString inPath);
		static QStringList mGetSubdirs(QString inPath);
};

} // namespace ARB

#endif // ADIR_H
