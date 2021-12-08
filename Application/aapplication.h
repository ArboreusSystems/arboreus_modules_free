// ----------------------------------------------------------
/*!
	\headerfile AApplication
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 22/07/2021 at 17:15:29
	\endlist
*/
// ----------------------------------------------------------

#ifndef AAPPLICATION_H
#define AAPPLICATION_H

// System includes

// Precompiled includes
#include <aapplicationpch.h>

// Application includes
#include <aconstants.h>
#include <aapplicationdatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Classes
class ABackend;

// Class definitions
class AApplication : public QObject {

	Q_OBJECT

	public:

		AConstants* pConstants = nullptr;

		explicit AApplication(QObject* parent = nullptr);
		virtual ~AApplication(void);
		Q_DISABLE_COPY(AApplication)

		void mInit(void);

	public slots:

		void mExit(void);

	signals:

		void sgInitiated(void);

	private:

		ABackend* pBackend = nullptr;
};

} // namespace ARB

#endif // AAPPLICATION_H