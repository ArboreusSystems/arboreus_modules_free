// ----------------------------------------------------------
/*!
	\headerfile AConstants
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 23/07/2021 at 18:25:26
	\endlist
*/
// ----------------------------------------------------------

#ifndef ACONSTANTS_H
#define ACONSTANTS_H

// System includes
#include <QObject>
#include <QString>

// Application includes
#include <aloggerglobal.h>
#include <aconstantsdefinition.h>

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class AConstants : public QObject {

	Q_OBJECT

	public:

		explicit AConstants(QObject *parent = nullptr);
		virtual ~AConstants(void);

	public slots:

		QString mStringError(void);
		QString mStringNormal(void);
		QString mStringOnClicked(void);
		QString mStringOnPressed(void);

	private:

		QString mString(const char* inValue);
};

} // namespace ARB

#endif // ACONSTANTS_H
