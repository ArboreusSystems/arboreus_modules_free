// ----------------------------------------------------------
/*!
	\headerfile AUISignals
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 13/03/2022 at 11:37:05
	\endlist
*/
// ----------------------------------------------------------

#ifndef AUISIGNALS_H
#define AUISIGNALS_H

// System includes

// Precompiled includes
#include <auihandlerpch.h>

// Application includes
#include <aloggerglobal.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AUISignals : public QObject {

	Q_OBJECT

	public:

		explicit AUISignals(QObject* parent = nullptr);
		virtual ~AUISignals(void);

		void mInit(void);

	signals:

};

} // namespace ARB

#endif // AUISIGNALS_H
