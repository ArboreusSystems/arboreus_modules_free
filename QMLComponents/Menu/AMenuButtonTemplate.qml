// ----------------------------------------------------------
/*!
	\qmltype
	\brief

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 22/07/2021 at 17:32:36
	\endlist
*/
// ----------------------------------------------------------

// System includes
import QtQuick 2.15

// Application includes


// Component
AMenuItemTemplate {

	property double pMargin: 0;

	id: oRoot;
	objectName: "NoDefinedMenuButtonObjectName";

	MouseArea {

		id: oMouseArea;
		anchors.fill: parent;

		onClicked: {

			console.info("Clicked menu button",oRoot.objectName);

			if (typeof oRoot.mOnClicked === "function") {
				oRoot.mOnClicked();
			}
		}
	}
}
