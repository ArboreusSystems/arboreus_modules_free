// ----------------------------------------------------------
/*!
	\headerfile AFonts
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 08/05/2021 at 15:09:47
	\endlist
*/
// ----------------------------------------------------------

#ifndef AFONTS_H
#define AFONTS_H

// System includes

// Precompiled includes
#include <auihandlerpch.h>

// Application includes
#include <aloggerglobal.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AFonts : public QObject {

	Q_OBJECT

	public:

		explicit AFonts(QObject* parent = nullptr);
		virtual ~AFonts(void);

		void mInit(QList<QString> inFontList);

	public slots:

		QString mFontFamily(void);
		void mSetFont(QString inFontFamily);

	signals:

		void sgFontChanged(void);

	private:

		QString pFontFamily = QString("NoFonFamily");

		void mSetFontList(QList<QString> inFontList);
};

} // namespace ARB

#endif // AFONTS_H
