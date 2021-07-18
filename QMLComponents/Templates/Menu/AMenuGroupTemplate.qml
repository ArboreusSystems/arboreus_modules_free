// ----------------------------------------------------------
/*!
	\qmltype
	\brief

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 18/07/2021 at 17:50:33
	\endlist
*/
// ----------------------------------------------------------

// System includes
import QtQuick 2.15

// Application includes

// Application paths
import "qrc:/ClentFree/Modules/QMLComponents/Text/";


// Component
AMenuItemTemplate {

	property alias pSignSize: oSignWrapper.height;
	property alias pSignSource: oSign.source;
	property alias pLabelText: oLabel.text;
	property alias pLabelFontBold: oLabel.font.bold;
	property alias pLabelFontPixelSize: oLabel.font.pixelSize;

	id: oRoot;
	objectName: "NoDefinedMenuGroupObjectName";

	Rectangle {

		id: oSignWrapper;
		height: oRoot.height * 0.75;
		width: oSignWrapper.height;
		color: "pink";
		anchors.verticalCenter: parent.verticalCenter;
		anchors.right: parent.right;
		anchors.rightMargin: oRoot.pMargin;

		Image {

			id: oSign;
			anchors.fill: parent;
		}
	}

	AText {

		id: oLabel;
		text: "NoGroupLabelText";
		maximumLineCount: 1;
		font.bold: true;
		font.pixelSize: 18;
		anchors.verticalCenter: parent.verticalCenter;
		anchors.left: parent.left;
		anchors.leftMargin: oRoot.pMargin;
		anchors.right: oSignWrapper.right;
		anchors.rightMargin: 5;
	}

	MouseArea {

		id: oMouseArea;
		anchors.fill: parent;

		onClicked: {

			console.info("Clicked menu group",oRoot.objectName);

			if (typeof oRoot.mOnClicked === "function") {
				oRoot.mOnClicked();
			}
		}
	}
}
