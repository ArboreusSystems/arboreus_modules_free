// ----------------------------------------------------------
/*!
    \headerfile AManifestMetatypes
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 13/06/2023 at 18:21:35
    \endlist
*/
// ----------------------------------------------------------

#ifndef AMANIFESTMETATYPES_H
#define AMANIFESTMETATYPES_H

// System includes

// Precompiled includes
#include <amanifestpch.h>

// Application includes
#include <amanifestdatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AManifestMetatypes : public QObject {

	public:

		explicit AManifestMetatypes(QObject *parent = nullptr);
		virtual ~AManifestMetatypes(void);

		static void mInit(void);
};

} // namespace ARB

#endif // AMANIFESTMETATYPES_H
