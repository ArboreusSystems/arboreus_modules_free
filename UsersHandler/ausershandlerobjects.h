// ----------------------------------------------------------
/*!
	\headerfile AUsersHandlerObjects
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 13/03/2022 at 14:18:30
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

// Classes
class ABackend;

// Class definitions
class AUsersHandlerObjects : public QObject {

	Q_OBJECT

	public:

		explicit AUsersHandlerObjects(ABackend* inBackend, QObject* parent = nullptr);
		virtual ~AUsersHandlerObjects(void);

	public slots:

		QVariantMap mUserPropeties(void);

	private:

		AUsersHandlerConfig* pConfig = nullptr;
		QVariantMap pUserProperties = {};
};

} // namespace ARB

#endif // AUSERSHANDLEROBJECTS_H
