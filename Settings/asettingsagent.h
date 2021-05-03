// ----------------------------------------------------------
/*!
	\headerfile ASettingsAgent
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 03/05/2021 at 19:30:45
	\endlist
*/
// ----------------------------------------------------------

#ifndef ASETTINGSAGENT_H
#define ASETTINGSAGENT_H

// System includes
#include <QObject>

// Application includes
#include <asettingsdatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ASettingsAgent : public QObject {

	Q_OBJECT

	public:

		ASettingsReply* pReply = nullptr;

		explicit ASettingsAgent(QString* inDbName, QObject* parent = nullptr);
		explicit ASettingsAgent(QObject* parent = nullptr);
		virtual ~ASettingsAgent(void);

	signals:

		void sgFinished(void);

	public slots:

		void slGet(QString inSettingsID);

	private:

		QString* pDBName = nullptr;
};

} // namespace ARB

#endif // ASETTINGSAGENT_H
