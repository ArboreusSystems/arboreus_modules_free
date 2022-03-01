// ----------------------------------------------------------
/*!
	\headerfile AUsers
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 27/02/2022 at 15:10:11
	\endlist
*/
// ----------------------------------------------------------

#ifndef AUSERS_H
#define AUSERS_H

// System includes

// Precompiled includes
#include <auserspch.h>

// Application includes
#include <athreadtemplate.h>
#include <ausersservice.h>

// Constants and definitions

// Namespace
namespace ARB {

// Classes
class ABackend;

// Class definitions
class AUsers : public AThreadTemplate<AUsersService> {

	Q_OBJECT

	public:

		explicit AUsers(QObject* parent = nullptr);
		virtual ~AUsers(void);
		Q_DISABLE_COPY(AUsers)

		void mInit(void);

	public slots:

		void slInitiated(void);

	signals:

		void sgInit(void);
		void sgInitiated(void);

	private:

		ABackend* pBackend = nullptr;
};

} // namespace ARB

#endif // AUSERS_H