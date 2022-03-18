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
#ifndef ATHREADAGENTTEMPLATE_H
#define ATHREADAGENTTEMPLATE_H

// System includes

// Precompiled includes
#include <atemplatespch.h>

// Application includes

// Constants and defintions

// Namespace
namespace ARB {

class AThreadAgentTemplate : public QObject {

	Q_OBJECT

	public:

		explicit AThreadAgentTemplate(QObject* parent = nullptr): QObject(parent) {}
		virtual ~AThreadAgentTemplate(void) {}

	public slots:

		virtual void slRun(void) = 0;

	signals:

		void sgFinished(void);
};

} // namespace ARB

#endif // ATHREADAGENTTEMPLATE_H
