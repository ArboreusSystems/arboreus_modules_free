// ----------------------------------------------------------
/*!
    \headerfile ADBKeyValueMetatypes
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 18:06:33
    \endlist
*/
// ----------------------------------------------------------

#ifndef ADBKEYVALUEMETATYPES_H
#define ADBKEYVALUEMETATYPES_H

// System includes

// Precompiled includes
#include <adbkeyvaluepch.h>

// Application includes
#include <adbkeyvaluedatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADBKeyValueMetatypes : public QObject {

	public:

		explicit ADBKeyValueMetatypes(QObject* parent = nullptr);
		virtual ~ADBKeyValueMetatypes(void);

		static void mInit(void);
};

} // namespace ARB

#endif // ADBKEYVALUEMETATYPES_H
