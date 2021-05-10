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
#include <QObject>
#include <QFontDatabase>

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

		void mInit(void);

	public slots:

		QString mFontFamily(void);

	signals:

		void sgFontChanged(void);

	private:

		QString pFontFamily = QString("NoFonFamily");

		void mInitFonts(void);
};

} // namespace ARB

#endif // AFONTS_H
