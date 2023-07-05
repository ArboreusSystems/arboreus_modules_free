// ----------------------------------------------------------
/*!
    \headerfile ASettingsWriteAgent
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 05/07/2023 at 17:55:33
    \endlist
*/
// ----------------------------------------------------------

#ifndef ASETTINGSWRITEAGENT_H
#define ASETTINGSWRITEAGENT_H

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
class ASettingsWriteAgent : public AThreadAgentTemplate {

	Q_OBJECT

	public:

		ASettingsReply pReply;
		QString pKey = "NoDefinedKey";
		QVariant pValue = "NoDefinedValue";

		explicit ASettingsWriteAgent(
			ADBKeyValue* inDBKeyValue,
			QString inKey, QVariant inValue,
			QObject* parent = nullptr
		);
		explicit ASettingsWriteAgent(QObject* parent = nullptr);
		virtual ~ASettingsWriteAgent(void);

		void slRun(void);

	private:

		ADBKeyValue* pDBKeyValue = nullptr;
};

} // namespace ARB

#endif // ASETTINGSWRITEAGENT_H
