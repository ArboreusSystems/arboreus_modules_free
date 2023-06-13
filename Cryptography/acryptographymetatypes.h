// ----------------------------------------------------------
/*!
    \headerfile ACryptographyMetatypes
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 17:38:33
    \endlist
*/
// ----------------------------------------------------------

#ifndef ACRYPTOGRAPHYMETATYPES_H
#define ACRYPTOGRAPHYMETATYPES_H

// System includes
#include <QObject>

// Precompiled includes
#include <acryptographypch.h>

// Application includes
#include <acryptographydatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ACryptographyMetatypes : public QObject {

	public:

		explicit ACryptographyMetatypes(QObject *parent = nullptr);
		virtual ~ACryptographyMetatypes(void);

		static void mInit(void);
};

} // namespace ARB

#endif // ACRYPTOGRAPHYMETATYPES_H
