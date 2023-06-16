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

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AData : public QObject {

	Q_OBJECT

	public:

		explicit AData(QObject* parent = nullptr);
		virtual ~AData(void);

	public slots:



	signals:

};

} // namespace ARB

#endif // ADATA_H
