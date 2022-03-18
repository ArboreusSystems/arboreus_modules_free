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

// Precompiled includes
#include <asettingspch.h>

// Application includes
#include <asettingsdatamodels.h>
#include <asettingsservice.h>
#include <aloggerglobal.h>
#include <athreadagenttemplate.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ASettingsAgent : public AThreadAgentTemplate {

	Q_OBJECT

	public:

		bool pStatus = false;
		ASettingsReply pReply;

		explicit ASettingsAgent(
			ASettingsService* inService = nullptr,
			QString inKey = QString("NoInKey"),
			QVariant inValue = QVariant(QString("NoInValue")),
			QObject* parent = nullptr
		);
		explicit ASettingsAgent(QObject* parent = nullptr);
		virtual ~ASettingsAgent(void);

	public slots:

		void slRun(void);

	private:

		ASettingsService* pService = nullptr;
		QString pKey;
		QVariant pValue;
};

} // namespace ARB

#endif // ASETTINGSAGENT_H
