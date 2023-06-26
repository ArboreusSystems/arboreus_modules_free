// ----------------------------------------------------------
/*!
    \headerfile ADataService
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 26/06/2023 at 11:21:53
    \endlist
*/
// ----------------------------------------------------------

#ifndef ADATASERVICE_H
#define ADATASERVICE_H

// System includes
#include <QObject>

// Precompiled includes
#include <adatapch.h>

// Application includes
#include <athreadservicetemplate.h>
#include <aloggerglobal.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADataService : public AThreadServiceTemplate {

	Q_OBJECT

	public:

		explicit ADataService(QObject* parent = nullptr);
		virtual ~ADataService(void);

	public slots:

		void slInit(void);

	signals:

		void sgInitiated(void);
};

} // namespace ARB

#endif // ADATASERVICE_H
