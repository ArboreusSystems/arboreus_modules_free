// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 04/05/2021 at 13:33:05
	\endlist
*/
// ----------------------------------------------------------
#ifndef ANETWORKDATAMODELS_H
#define ANETWORKDATAMODELS_H

// System includes
#include <QString>
#include <QMap>
#include <QVariantMap>
#include <QVariantList>

// Application includes

// Constants and defintions

// Namespace
namespace ARB {

class ANetworkRequestProperties {

	public:

		QString URL = QString("NoDefinedURL");
		QMap<QString,QString> Headers = {};
		QByteArray Data = QByteArray();
};

class ANetworkReply {

	public:

		bool Status = false;
		QVariantList Headers = {};
		QByteArray Data = QByteArray();

		QVariantMap mToVariantMap(void) {

			QVariantMap oOutput;
			oOutput.insert("Status",Status);
			oOutput.insert("Data",Data);
			oOutput.insert("Headers",Headers);
			return oOutput;
		}
};

}

#endif // ANETWORKDATAMODELS_H
