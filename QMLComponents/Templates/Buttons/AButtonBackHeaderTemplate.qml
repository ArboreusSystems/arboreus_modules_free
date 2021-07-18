// ----------------------------------------------------------
/*!
	\qmltype
	\brief

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 18/07/2021 at 16:31:21
	\endlist
*/
// ----------------------------------------------------------

// System includes
import QtQuick 2.15
import QtQuick.Controls 2.15

// Application includes


// Component
AButtonTemplate {

	property string pText: "NoDefinedLabelText";
	property alias pLabelText: oLabel.color;
	property alias pLabelFontBold: oLabel.font.bold;
	property alias pLabelFontPixelSize: oLabel.font.pixelSize;

	id: oRoot;
	objectName: "NoDefinedBackButtonObjectName";
	anchors.verticalCenter: parent.verticalCenter;

	contentItem: Row {

		id: oContentItem;
		height: parent.height;
		anchors.left: parent.left;
		spacing: 5;

		Rectangle {

			id: oSignWrapper;
			height: parent.height;
			width: oSignWrapper.height;

			Image {

				id: oSign;
				anchors.fill: parent;
			}
		}

		Text {

			id: oLabel;
			text: oRoot.pText;
			color: "pink";
			font.bold: true;
			font.pixelSize: 18;
			anchors.verticalCenter: parent.verticalCenter;
		}
	}
}
