// ----------------------------------------------------------
/*!
    \headerfile AUserHandlerMetatypes
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 17:17:58
    \endlist
*/
// ----------------------------------------------------------

#ifndef AUSERSHANDLERMETATYPES_H
#define AUSERSHANDLERMETATYPES_H

// System includes

// Precompiled includes
#include <ausershandlerpch.h>

// Application includes
#include <ausershandlerdatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AUsersHandlerMetatypes : public QObject {

	public:

		explicit AUsersHandlerMetatypes(QObject* parent = nullptr);
		virtual ~AUsersHandlerMetatypes(void);

		static void mInit(void);
};

} // namespace ARB

#endif // AUSERSHANDLERMETATYPES_H
