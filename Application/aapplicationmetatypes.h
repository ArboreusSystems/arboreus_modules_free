// ----------------------------------------------------------
/*!
    \headerfile AApplicationMetatypes
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 17:28:58
    \endlist
*/
// ----------------------------------------------------------

#ifndef AAPPLICATIONMETATYPES_H
#define AAPPLICATIONMETATYPES_H

// System includes

// Precompiled includes
#include <aapplicationpch.h>

// Application includes
#include <aapplicationdatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AApplicationMetatypes : public QObject {

	public:

		explicit AApplicationMetatypes(QObject* parent = nullptr);
		virtual ~AApplicationMetatypes(void);

		static void mInit(void);
};

} // namespace ARB

#endif // AAPPLICATIONMETATYPES_H
