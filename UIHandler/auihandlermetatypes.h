// ----------------------------------------------------------
/*!
    \headerfile AUIHandlerMetatypes
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 19:03:48
    \endlist
*/
// ----------------------------------------------------------

#ifndef AUIHANDLERMETATYPES_H
#define AUIHANDLERMETATYPES_H

// System includes

// Precompiled includes
#include <auihandlerpch.h>

// Application includes
#include <auihandlerdatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AUIHandlerMetatypes : public QObject {

	public:

		explicit AUIHandlerMetatypes(QObject* parent = nullptr);
		virtual ~AUIHandlerMetatypes(void);

		static void mInit(void);
};

} // namespace ARB

#endif // AUIHANDLERMETATYPES_H
