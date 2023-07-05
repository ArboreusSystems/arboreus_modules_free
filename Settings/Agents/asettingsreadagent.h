// ----------------------------------------------------------
/*!
    \headerfile ASettingsReadAgent
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 05/07/2023 at 18:40:37
    \endlist
*/
// ----------------------------------------------------------

#ifndef ASETTINGSREADAGENT_H
#define ASETTINGSREADAGENT_H

// System includes

// Precompiled includes
#include <asettingspch.h>

// Application includes
#include <aloggerglobal.h>
#include <athreadagenttemplate.h>
#include <adbkeyvalue.h>
#include <asettingsdatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ASettingsReadAgent : public AThreadAgentTemplate {

	Q_OBJECT

	public:

		ASettingsReply pReply;
		QString pKey = "NoDefinedKey";

		explicit ASettingsReadAgent(
			ADBKeyValue* inDBKeyValue,
			QString inKey,
			QObject* parent = nullptr
		);
		explicit ASettingsReadAgent(QObject *parent = nullptr);
		virtual ~ASettingsReadAgent(void);

		void slRun(void);

	private:

		ADBKeyValue* pDBKeyValue = nullptr;

};

} // namespace ARB

#endif // ASETTINGSREADAGENT_H
