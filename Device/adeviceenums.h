// ----------------------------------------------------------
/*!
	\headerfile ADeviceEnums
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 08/05/2021 at 11:58:48
	\endlist
*/
// ----------------------------------------------------------

#ifndef ADEVICEENUMS_H
#define ADEVICEENUMS_H

// System includes
#include <QObject>

// Application includes

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADeviceEnums : public QObject {

	Q_OBJECT

	public:

		enum class StatusBarStyle: int {

			Default,
			Light,
			Dark
		};
		Q_ENUM(StatusBarStyle)

		enum class Type {

			Undefined,
			Phone,
			Tablet,
			Desktop
		};
		Q_ENUM(Type)
};

} // namespace ARB

#endif // ADEVICEENUMS_H
