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
#include <adatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADataDictionary : public QObject {

	public:

		explicit ADataDictionary(QObject* parent = nullptr);
		virtual ~ADataDictionary(void);

		static QString mCreate(QList<_A_ENUMS_DATA_DICTIONARY_TYPE> inParameters);
		static QString mGetNumeric(void);
		static QString mGetAlphaLowerCase(void);
		static QString mGetAlphaUpperCase(void);
};

} // namespace ARB

#endif // ADATADICTIONARY_H
