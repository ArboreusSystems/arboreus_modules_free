// ----------------------------------------------------------
/*!
	\qmltype
	\brief

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 08/12/2021 at 09:55:21
	\endlist
*/
// ----------------------------------------------------------

// System includes
import QtQuick 2.15
import QtQuick.Window 2.15

// Application includes


// Component
Rectangle {

	signal sgKeyboardVisible(bool inVisible);

	id: oRoot;
	color: AColors.mTransparent();
	anchors.fill: parent;

	Component.onCompleted: {

		Qt.inputMethod.onKeyboardRectangleChanged.connect(oRoot.mUpdateSize);
		Qt.inputMethod.onVisibleChanged.connect(oRoot.mUpdateSize);

		oRoot.mUpdateSize();
	}

	Component.onDestruction: {

		Qt.inputMethod.onKeyboardRectangleChanged.disconnect(oRoot.mUpdateSize);
		Qt.inputMethod.onVisibleChanged.disconnect(oRoot.mUpdateSize);
	}

	Connections {

		target: ADevice;
		function onSgOrientationChanged(inOrientation) {

			if (typeof oRoot.mOnSgOrientationChanged === "function") {
				oRoot.mOnSgOrientationChanged(inOrientation);
			}
		}
	}

	Timer {

		property real pOffset: 0;

		id: oTimerResize;
		interval: 100;
		repeat: false;
		running: false;
		onTriggered: {

			oRoot.anchors.bottomMargin = oTimerResize.pOffset;
			oTimerResize.stop();
		}
	}

	function mUpdateSize() {

		let oDeviceSafeArea = ADevice.mSafeAreaInsets();
		let oSafeAreaHeightOffset = oDeviceSafeArea.Top + oDeviceSafeArea.Bottom;
		let oRectKeyboard = Qt.inputMethod.keyboardRectangle;
		let oOffsetY = oRectKeyboard.y / Screen.devicePixelRatio;

		if (Qt.inputMethod.visible && oOffsetY > 0) {
			let oHeight = Screen.height;
			let oOffsetBar = oHeight - Screen.desktopAvailableHeight - oDeviceSafeArea.Top;
			if(Qt.platform.os == "android") {
				oTimerResize.pOffset = oHeight - oOffsetY - oOffsetBar;
				oTimerResize.restart();
			} else {
				oRoot.anchors.bottomMargin = oRectKeyboard.height - oDeviceSafeArea.Bottom;
			}
			oRoot.sgKeyboardVisible(true);
		} else {
			oTimerResize.stop();
			oRoot.anchors.bottomMargin = 0;
			oRoot.sgKeyboardVisible(false);
		}
	}
}
