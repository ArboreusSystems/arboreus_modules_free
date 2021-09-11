// ----------------------------------------------------------
/*!
	\headerfile AUIHandler
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 08/05/2021 at 15:08:35
	\endlist
*/
// ----------------------------------------------------------

#ifndef AUIHANDLER_H
#define AUIHANDLER_H

// System includes

// Precompiled includes
#include <auihandlerpch.h>

// Application includes
#include <auiconfig.h>
#include <auihandlerdefinitions.h>
#include <afonts.h>
#include <acolors.h>

// Constants and definitions

// Namespace
namespace ARB {

// Classes
class ABackend;

// Class definitions
class AUIHandler : public QObject {

	Q_OBJECT

	public:

		AFonts* pFonts = nullptr;
		AColors* pColors = nullptr;
		AUIConfig* pConfig = nullptr;

		explicit AUIHandler(QObject* parent = nullptr);
		virtual ~AUIHandler(void);
		Q_DISABLE_COPY(AUIHandler)

		void mInit(void);

	public slots:

		QString mComponentContent(QString inName);

	signals:

		void sgInitiated(void);

	private:

		ABackend* pBackend = nullptr;

		QString mComponentString(QString inImport,QString inName);
};

} // namespace ARB

#endif // AUIHANDLER_H
