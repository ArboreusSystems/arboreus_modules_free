// ----------------------------------------------------------
/*!
    \headerfile AData
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 16/06/2023 at 19:48:12
    \endlist
*/
// ----------------------------------------------------------

#ifndef ADATA_H
#define ADATA_H

// System includes

// Precompiled includes
#include <adatapch.h>

// Application includes
#include <aloggerglobal.h>
#include <adatatypes.h>
#include <adatastructures.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AData : public QObject {

	Q_OBJECT

	public:

		ADataTypes* pTypes = nullptr;
		ADataStructures* pStructures = nullptr;

		explicit AData(QObject* parent = nullptr);
		virtual ~AData(void);
		Q_DISABLE_COPY(AData)

		void mInit(void);

	public slots:



	signals:

		void sgInitiated(void);
};

} // namespace ARB

#endif // ADATA_H
