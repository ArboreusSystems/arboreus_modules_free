// ----------------------------------------------------------
/*!
    \headerfile ADataStructure
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 16/06/2023 at 19:12:09
    \endlist
*/
// ----------------------------------------------------------

#ifndef ADATASTRUCTURE_H
#define ADATASTRUCTURE_H

// System includes

// Precompiled includes
#include <adatapch.h>

// Application includes

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADataStructure : public QObject {

		explicit ADataStructure(QObject* parent = nullptr);
		virtual ~ADataStructure(void);

};

} // namespace ARB

#endif // ADATASTRUCTURE_H
