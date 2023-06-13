// ----------------------------------------------------------
/*!
    \headerfile ADBMetatypes
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 17:51:40
    \endlist
*/
// ----------------------------------------------------------

#ifndef ADBMETATYPES_H
#define ADBMETATYPES_H

// System includes

// Precompiled includes
#include <adbpch.h>

// Application includes
#include <adbdatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADBMetatypes : public QObject {

	public:

		explicit ADBMetatypes(QObject* parent = nullptr);
		virtual ~ADBMetatypes(void);

		static void mInit(void);
};

} // namespace ARB

#endif // ADBMETATYPES_H
