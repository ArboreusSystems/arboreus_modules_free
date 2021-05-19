// ----------------------------------------------------------
/*!
	\headerfile AColors
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 08/05/2021 at 16:41:15
	\endlist
*/
// ----------------------------------------------------------

#ifndef ACOLORS_H
#define ACOLORS_H

// System includes
#include <QObject>
#include <QColor>
#include <QString>

// Application includes
#include <aloggerglobal.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AColors : public QObject {

	Q_OBJECT

	public:

		QColor pTransparent = QColor(Qt::transparent).rgba();

		QColor pBlackLight = QColor::fromRgb(10,10,10);
		QColor pBlack = QColor::fromRgb(5,5,5);
		QColor pBlackDark = QColor::fromRgb(0,0,0);

		QColor pWhiteDark = QColor::fromRgb(239,239,239);
		QColor pWhite = QColor::fromRgb(249,249,249);
		QColor pWhiteLight = QColor::fromRgb(255,255,255);

		explicit AColors(QObject* parent = nullptr);
		virtual ~AColors(void);
		Q_DISABLE_COPY(AColors)

		void mInit(void);

	public slots:

		QString mTransparent(void);

		QString mBlackLight(void);
		QString mBlack(void);
		QString mBlackDark(void);

		QString mWhiteDark(void);
		QString mWhite(void);
		QString mWhiteLight(void);
};

} // namespace ARB

#endif // ACOLORS_H
