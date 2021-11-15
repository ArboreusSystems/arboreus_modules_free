// ----------------------------------------------------------
/*!
	\headerfile ASession
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 15/11/2021 at 18:23:56
	\endlist
*/
// ----------------------------------------------------------

#ifndef ASESSION_H
#define ASESSION_H

// System includes

// Precompiled includes
#include <asessionpch.h>

// Application includes
#include <asessiondatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Classes
class ABackend;

// Class definitions
class ASession : public QObject {

	Q_OBJECT

	public:

		explicit ASession(QObject* parent = nullptr);
		virtual ~ASession(void);

		void mInit(void);

	public slots:

		void mPut(QString inKey,QVariant inValue);
		QVariantMap mGet(QString inKey);
		void mRemove(QString inKey);

	signals:

		void sgInitiated(void);

	private:

		ABackend* pBackend = nullptr;
		QHash<QString,QVariant> pSession = {};
};

} // namespace ARB

#endif // ASESSION_H
