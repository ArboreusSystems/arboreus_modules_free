// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 28/04/2021 at 19:44:41
	\endlist
*/
// ----------------------------------------------------------
#ifndef ATHREADOBJECTCONTROLLERTEMPLATE_H
#define ATHREADOBJECTCONTROLLERTEMPLATE_H

// System includes
#include <QObject>

// Application includes

// Constants and defintions

// Namespace
namespace ARB {

class AThreadObjectControllerTemplate : public QObject {

	Q_OBJECT

	public:

		explicit AThreadObjectControllerTemplate(QObject* parent = nullptr): QObject(parent) {}
		virtual ~AThreadObjectControllerTemplate(void) {}

	signals:

		void sgRun(void);
};

} // namespace ARB

#endif // ATHREADOBJECTCONTROLLERTEMPLATE_H
