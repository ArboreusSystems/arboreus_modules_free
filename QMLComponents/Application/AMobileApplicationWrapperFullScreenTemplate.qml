// ----------------------------------------------------------
/*!
	\qmltype
	\brief

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 02/01/2022 at 12:00:29
	\endlist
*/
// ----------------------------------------------------------

// System includes
import QtQuick 2.15
import QtQuick.Controls 2.15
import Arboreus 1.0

// Application includes


// Component
Item {

	required property ApplicationWindow pApplicationWindow;
	property alias pContent: oContentWrapper;
	property string pColorSafeArea: "magenta";
	property string pColorBackground: "white";
	property var pStatusBarStyle: ADeviceEnums.Light;

	id: oRoot;
	width: parent.width;
	height: parent.height;

	Component.onCompleted: {

		oRoot.pApplicationWindow.flags = Qt.Window | Qt.MaximizeUsingFullscreenGeometryHint;
		oRoot.mSetStatusBarStyleDefault();
		oRoot.mSetSafeAreaInsets();
	}

	Connections {

		target: ADevice;
		function onSgOrientationChanged(inOrientation) {

			oRoot.mSetSafeAreaInsets();

			if (ADevice.mIsLandscape()) {
				oPaddingLeft.color = AColors.mTransparent();
				oPaddingRight.color = AColors.mTransparent();
			} else {
				if (inOrientation === Qt.InvertedPortraitOrientation) {
					oPaddingLeft.color = AColors.mTransparent();
					oPaddingRight.color = AColors.mTransparent();
				} else {
					oPaddingLeft.color = oRoot.pColorSafeArea;
					oPaddingRight.color = oRoot.pColorSafeArea;
				}
			}
		}
	}

	Rectangle {

		id: oPaddingLeft;
		color: AColors.mTransparent();
		height: parent.height;
		anchors.top: parent.top;
		anchors.left: parent.left;
	}

	Rectangle {

		id: oPaddingRight;
		color: AColors.mTransparent();
		height: parent.height;
		anchors.top: parent.top;
		anchors.right: parent.right;
	}

	Rectangle {

		id: oPaddingTop;
		color: oRoot.pColorSafeArea;
		anchors.top: parent.top;
		anchors.left: oPaddingLeft.right;
		anchors.right: oPaddingRight.left;
	}

	Rectangle {

		id: oPaddingBottom;
		color: oRoot.pColorSafeArea;
		anchors.bottom: parent.bottom;
		anchors.left: oPaddingLeft.right;
		anchors.right: oPaddingRight.left;
	}

	Item {

		id: oContentWrapper;
		anchors.top: oPaddingTop.bottom;
		anchors.bottom: oPaddingBottom.top;
		anchors.left: oPaddingLeft.right;
		anchors.right: oPaddingRight.left;
	}

	function mSetSafeAreaInsets() {

		let oSafeAreaInsets = ADevice.mSafeAreaInsets();

		oPaddingTop.height = oSafeAreaInsets.Top;
		oPaddingBottom.height = oSafeAreaInsets.Bottom;
		oPaddingLeft.width = oSafeAreaInsets.Left;
		oPaddingRight.width = oSafeAreaInsets.Right;
	}

	function mSetStatusBarStyleDefault() {

		oRoot.pStatusBarStyle = ADeviceEnums.Light;
		ADevice.mSetStatusBarStyle(oRoot.pStatusBarStyle);
	}

	function mSetBackgroundColor(inColor) {

		oRoot.pColorBackground = AColors.mGetString(inColor);
	}
}
