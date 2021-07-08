// ----------------------------------------------------------
/*!
	\qmltype
	\brief

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 08/07/2021 at 13:54:17
	\endlist
*/
// ----------------------------------------------------------

// System includes
import QtQuick 2.15
import QtQuick.Controls 2.15

// Application includes


// Component
Button {

	id: oRoot;
	width: parent.height * 0.63;
	height: parent.height * 0.63;
	anchors.verticalCenter: parent.verticalCenter;

	onClicked: {

		console.log("Button clicked")
	}
}
