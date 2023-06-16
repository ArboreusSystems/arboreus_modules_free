// ----------------------------------------------------------
/*!
    \headerfile ADataDictionary
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 16/06/2023 at 19:45:48
    \endlist
*/
// ----------------------------------------------------------

#ifndef ADATADICTIONARY_H
#define ADATADICTIONARY_H

// System includes

// Precompiled includes
#include <adatapch.h>

// Application includes

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADataDictionary : public QObject {

	Q_OBJECT

	public:

		explicit ADataDictionary(QObject* parent = nullptr);
		virtual ~ADataDictionary(void);
};

} // namespace ARB

#endif // ADATADICTIONARY_H
