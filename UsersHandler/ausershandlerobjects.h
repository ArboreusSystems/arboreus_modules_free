// ----------------------------------------------------------
/*!
	\headerfile AUsersHandlerObjects
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 10/03/2023 at 16:03:57
	\endlist
*/
// ----------------------------------------------------------

#ifndef AUSERSHANDLEROBJECTS_H
#define AUSERSHANDLEROBJECTS_H

// System includes

// Precompiled includes
#include <ausershandlerpch.h>

// Application includes
#include <aloggerglobal.h>
#include <ausershandlerconfig.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AUsersHandlerObjects : public QObject {

	Q_OBJECT

	public:

		explicit AUsersHandlerObjects(
			AUsersHandlerConfig* inConfig = nullptr,
			QObject* parent = nullptr
		);
		explicit AUsersHandlerObjects(QObject* parent = nullptr);
		virtual ~AUsersHandlerObjects(void);

	public slots:

		QVariantMap mUserData(void);

	private:

		AUsersHandlerConfig* pConfig = nullptr;
};

} // namespace ARB

#endif // AUSERSHANDLEROBJECTS_H
