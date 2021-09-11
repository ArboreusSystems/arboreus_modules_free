// ----------------------------------------------------------
/*!
	\headerfile AUIConfig
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 18/05/2021 at 20:30:03
	\endlist
*/
// ----------------------------------------------------------

#ifndef AUICONFIG_H
#define AUICONFIG_H

// System includes

// Precompiled includes
#include <auihandlerpch.h>

// Application includes
#include <auihandlerconfig.h>
#include <aloggerglobal.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AUIConfig : public QObject {

	Q_OBJECT

	public:

		explicit AUIConfig(QObject* parent = nullptr);
		virtual ~AUIConfig(void);

		void mInit(AUIHandlerConfig* inConfig);

	public slots:

		QString mQMLImport(void);

		int mUIWidth(void);
		int mUIHeight(void);
		int mDesktopUIWidth(void);
		int mDesktopUIHeight(void);

		int mFontSizeHeader(void);
		int mFontSizeRegular(void);
		int mFontSizeTextInput(void);

		int mBorderSize(void);
		int mRadius(void);
		int mElementHeight(void);

		QMap<QString,QString> mColors(void);
		QList<QString> mFonts(void);

	private:

		AUIHandlerConfig* pConfig = nullptr;
};

} // namespace ARB

#endif // AUICONFIG_H
