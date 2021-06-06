// ----------------------------------------------------------
/*!
	\headerfile ANetworkService
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 04/05/2021 at 13:32:13
	\endlist
*/
// ----------------------------------------------------------

#ifndef ANETWORKSERVICE_H
#define ANETWORKSERVICE_H

// System includes
#include <QObject>
#include <QNetworkAccessManager>

// Application includes
#include <aloggerglobal.h>
#include <athreadservicetemplate.h>
#include <anetworkdatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ANetworkService : public AThreadServiceTemplate {

	Q_OBJECT

	public:

		explicit ANetworkService(QObject* parent = nullptr);
		virtual ~ANetworkService(void);

		QNetworkAccessManager* mGetNetworkManager(void);

	public slots:

		void slInit(void);

	signals:

		void sgInitiated(void);

	private:

		QNetworkAccessManager* pNetworkManager = nullptr;
};

} // namespace ARB

#endif // ANETWORKSERVICE_H
