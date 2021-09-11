// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 28/04/2021 at 19:43:18
	\endlist
*/
// ----------------------------------------------------------
#ifndef ATHREADOBJECTTEMPLATE_H
#define ATHREADOBJECTTEMPLATE_H

// System includes

// Precompiled includes
#include <atemplatespch.h>

// Application includes

// Constants and defintions

// Namespace
namespace ARB {

class AThreadObjectTemplate : public QObject {

	Q_OBJECT

	public:

		explicit AThreadObjectTemplate(QObject* parent = nullptr): QObject(parent) {}
		virtual ~AThreadObjectTemplate(void) {}

	public slots:

		virtual void slRun(void) = 0;

	signals:

		void sgFinished(void);
};

} // namespace ARB

#endif // ATHREADOBJECTTEMPLATE_H
