// ----------------------------------------------------------
/*!
    \headerfile ADataMetatypes
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 16/06/2023 at 19:25:03
    \endlist
*/
// ----------------------------------------------------------

#ifndef ADATAMETATYPES_H
#define ADATAMETATYPES_H

// System includes

// Precompiled includes
#include <adatapch.h>

// Application includes
#include <adatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADataMetatypes : public QObject {

	public:

		explicit ADataMetatypes(QObject* parent = nullptr);
		virtual ~ADataMetatypes(void);

		static void mInit(void);
};

} // namespace ARB

#endif // ADATAMETATYPES_H
