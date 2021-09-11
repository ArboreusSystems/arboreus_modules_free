// ----------------------------------------------------------
/*!
	\headerfile ANetwork
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 04/05/2021 at 13:31:50
	\endlist
*/
// ----------------------------------------------------------

#ifndef ANETWORK_H
#define ANETWORK_H

// System includes

// Precompiled includes
#include <anetworkpch.h>

// Application includes
#include <athreadtemplate.h>
#include <anetworkservice.h>
#include <anetworkagent.h>
#include <anetworkdatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Classes
class ABackend;

// Class definitions
class ANetwork : public AThreadTemplate<ANetworkService> {

	Q_OBJECT

	public:

		explicit ANetwork(QObject* parent = nullptr);
		virtual ~ANetwork(void);

		void mInit(void);
		ANetworkReply mPOSTRequest(ANetworkRequestProperties inProperties);
		ANetworkReply mGETRequest(ANetworkRequestProperties inProperties);

	signals:

		void sgInit(void);
		void sgInitiated(void);

	public slots:

		void slInitiated(void);

	private:

		ABackend* pBackend = nullptr;
};

} // namespace ARB

#endif // ANETWORK_H
