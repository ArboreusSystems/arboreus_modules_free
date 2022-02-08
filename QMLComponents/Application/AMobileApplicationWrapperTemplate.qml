// ----------------------------------------------------------
/*!
	\qmltype
	\brief

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 02/01/2022 at 12:46:37
	\endlist
*/
// ----------------------------------------------------------

// System includes
import QtQuick 2.15
import QtQuick.Controls 2.15

// Application includes


// Component
Item {

	required property ApplicationWindow pApplicationWindow;

	id: oRoot;
	width: parent.width;
	height: parent.height;

	Component.onCompleted: {

		pApplicationWindow.flags = Qt.Window;
	}
}
