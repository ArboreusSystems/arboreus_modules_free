// ----------------------------------------------------------
/*!
	\headerfile ANetworkAgent
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 06/06/2021 at 14:00:54
	\endlist
*/
// ----------------------------------------------------------

#ifndef ANETWORKAGENT_H
#define ANETWORKAGENT_H

// System includes
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>

// Application includes
#include <aloggerglobal.h>
#include <anetworkdatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ANetworkAgent : public QObject {

	Q_OBJECT

	public:

		ANetworkReply pReply = ANetworkReply();

		explicit ANetworkAgent(
			ANetworkRequestProperties inProperties = ANetworkRequestProperties(),
			QNetworkAccessManager* inManager = nullptr,
			QObject* parent = nullptr
		);
		explicit ANetworkAgent(QObject* parent = nullptr);
		virtual ~ANetworkAgent(void);

	public slots:

		void slPOST(void);
		void slGET(void);

	signals:

		void sgFinished(void);

	private:

		ANetworkRequestProperties pProperties;
		QNetworkAccessManager* pManager = nullptr;

		QNetworkRequest mCreateRequest(void);
		QVariantList mGetHeaders(QNetworkReply* inReply);
};

} // namespace ARB

#endif // ANETWORKAGENT_H
