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
AButtonGeneralTemplate {

	property alias pLabel: oLabel;
	property alias pSign: oSign;

	id: oRoot;
	objectName: "NoDefinedBackButtonObjectName";
	anchors.verticalCenter: parent.verticalCenter;

	contentItem: Row {

		id: oContentItem;
		height: parent.height;
		anchors.left: parent.left;
		spacing: 5;

		Component.onCompleted: {

			oSign.implicitWidth = oSign.children[0].width;
			oLabel.implicitWidth = oLabel.children[0].width;
		}

		Item {

			id: oSign;
			implicitHeight: parent.height;
		}

		Item {

			id: oLabel;
			implicitHeight: parent.height
		}
	}

	background: Rectangle {

		id: oBackground;
		color: AColors.mTransparent();
		anchors.fill: parent;
	}
}
