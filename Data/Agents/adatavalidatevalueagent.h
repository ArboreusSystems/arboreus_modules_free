// ----------------------------------------------------------
/*!
    \headerfile ADataValidateValueAgent
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 26/06/2023 at 18:33:43
    \endlist
*/
// ----------------------------------------------------------

#ifndef ADATAVALIDATEVALUEAGENT_H
#define ADATAVALIDATEVALUEAGENT_H

// System includes

// Precompiled includes
#include <adatapch.h>

// Application includes
#include <aloggerglobal.h>
#include <athreadagenttemplate.h>
#include <adataservice.h>
#include <adatamodels.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADataValidateValueAgent : public AThreadAgentTemplate {

	Q_OBJECT

	public:

		explicit ADataValidateValueAgent(QObject* parent = nullptr);
		virtual ~ADataValidateValueAgent(void);

		void mInit(
			ADataService* inService,_A_ENUMS_DATA_TYPE inType,
			QVariant inValue,QVariantMap inProperties = {}
		);
		ADataReplyValidate mReply(void);

	public slots:

		void slRun(void);

	private:

		ADataService* pService = nullptr;
		_A_ENUMS_DATA_TYPE pType = _A_ENUMS_DATA_TYPE::Undefined;
		QVariantMap pProperties = {};
		QVariant pValue = 0;
		ADataReplyValidate pReply;
};

} // namespace ARB

#endif // ADATAVALIDATEVALUEAGENT_H
