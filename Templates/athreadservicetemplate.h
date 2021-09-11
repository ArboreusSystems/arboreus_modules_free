// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 28/04/2021 at 19:32:13
	\endlist
*/
// ----------------------------------------------------------
#ifndef ATHREADSERVICETEMPLATE_H
#define ATHREADSERVICETEMPLATE_H

// System includes

// Precompiled includes
#include <atemplatespch.h>

// Application includes

// Constants and defintions

// Namespace
namespace ARB {

class AThreadServiceTemplate : public QObject {

	Q_OBJECT

	public:

		explicit AThreadServiceTemplate(QObject *parent = nullptr): QObject(parent) {

			pMutex.lock();
		}

		virtual ~AThreadServiceTemplate(void) {

			pWaitCondition.wakeAll();
			pMutex.unlock();
		}

		void mResume(void) {

			pWaitCondition.wakeAll();
		}

		void mSuspend(void) {

			QMetaObject::invokeMethod(this,&AThreadServiceTemplate::slSuspend);
			pMutex.lock();
			pMutex.unlock();
		}

	private slots:

		void slSuspend(void) {

			pWaitCondition.wait(&pMutex);
		}

	private:

		QMutex pMutex;
		QWaitCondition pWaitCondition;
};

} // namespace ARB

#endif // ATHREADSERVICETEMPLATE_H
