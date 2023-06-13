// ----------------------------------------------------------
/*!
    \headerfile AUniversalMetatypes
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 19:11:32
    \endlist
*/
// ----------------------------------------------------------

#ifndef AUNIVERSALMETATYPES_H
#define AUNIVERSALMETATYPES_H

// System includes

// Precompiled includes
#include <auniversalpch.h>

// Application includes
#include <auniversaldatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AUniversalMetatypes : public QObject {

	public:

		explicit AUniversalMetatypes(QObject* parent = nullptr);
		virtual ~AUniversalMetatypes(void);

		static void mInit(void);
};

} // namespace ARB

#endif // AUNIVERSALMETATYPES_H
