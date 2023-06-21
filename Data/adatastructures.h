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

#ifndef ADATASTRUCTURES_H
#define ADATASTRUCTURES_H

// System includes

// Precompiled includes
#include <adatapch.h>

// Application includes
#include <aloggerglobal.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADataStructures : public QObject {

		Q_OBJECT

	public:

		explicit ADataStructures(QObject* parent = nullptr);
		virtual ~ADataStructures(void);

	public slots:

};

} // namespace ARB

#endif // ADATASTRUCTURES_H
