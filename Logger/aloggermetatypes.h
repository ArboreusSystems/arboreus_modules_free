// ----------------------------------------------------------
/*!
    \headerfile ALoggerMetatypes
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 18:14:55
    \endlist
*/
// ----------------------------------------------------------

#ifndef ALOGGERMETATYPES_H
#define ALOGGERMETATYPES_H

// System includes

// Precompiled includes
#include <aloggerpch.h>

// Application includes
#include <aloggerdatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ALoggerMetatypes : public QObject {

	public:

		explicit ALoggerMetatypes(QObject* parent = nullptr);
		virtual ~ALoggerMetatypes(void);

		static void mInit(void);
};

} // namespace ARB

#endif // ALOGGERMETATYPES_H
