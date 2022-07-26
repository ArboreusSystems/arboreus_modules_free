// ----------------------------------------------------------
/*!
	\headerfile AApplicationService
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 26/07/2022 at 09:06:02
	\endlist
*/
// ----------------------------------------------------------

#ifndef AAPPLICATIONSERVICE_H
#define AAPPLICATIONSERVICE_H

// System includes

// Precompiled includes
#include <aloggerpch.h>

// Application includes
#include <aloggerglobal.h>
#include <athreadservicetemplate.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AApplicationService : public AThreadServiceTemplate {

	Q_OBJECT

	public:

		explicit AApplicationService(QObject* parent = nullptr);
		virtual ~AApplicationService(void);

	public slots:

		void slInit(void);

	signals:

		void sgInitiated(void);
};

} // namespace ARB

#endif // AAPPLICATIONSERVICE_H
