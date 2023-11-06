// ----------------------------------------------------------
/*!
    \headerfile
    \title
    \brief Template file files/cppheader/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 12/06/2023 at 20:08:18
    \endlist
*/
// ----------------------------------------------------------
#ifndef AUSERSHANDLERMODELUSER_H
#define AUSERSHANDLERMODELUSER_H

// System includes

// Precompiled includes
#include <ausershandlerpch.h>

// Application includes
#include <aloggerglobal.h>
#include <amanifest.h>

// Constants and defintions

// Namespace
namespace ARB {

class AUsersHandlerModelUser : public QObject {

	public:

		QString ID = "NoDefinedID";
		AManifest Manifest;

		explicit AUsersHandlerModelUser(QObject* parent) : QObject(parent)  {

			_A_DEBUG << "AUsersHandlerModelUser created";
		}

		virtual ~AUsersHandlerModelUser(void) {

			_A_DEBUG << "AUsersHandlerModelUser deleted";
		}

		void mInitWithManifest(QString inPath) {

			Q_UNUSED(inPath)
			_A_DEBUG << "AUsersHandlerModelUser initiated with manifest";
		}
};

} // namespace ARB

#endif // AUSERSHANDLERMODELUSER_H
