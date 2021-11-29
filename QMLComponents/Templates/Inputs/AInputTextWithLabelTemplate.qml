// ----------------------------------------------------------
/*!
	\qmltype
	\brief

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 16/11/2021 at 14:57:10
	\endlist
*/
// ----------------------------------------------------------

// System includes
import QtQuick 2.15

// Application includes

//
import "qrc:/ClentFree/Modules/QMLComponents/Text";


// Component
Item {

	property alias pLabelText: oLabel.text;
	property alias pInputText: oInput.pText;
	property alias pInputPlaceholder: oInput.pPlaceholder;

	property alias pStateNormalName: oInput.pStateNormalName;
	property alias pStateErrorName: oInput.pStateErrorName;
	property alias pStateOnFocusName: oInput.pStateOnFocusName;

	property alias pColorBorderNormal: oInput.pColorBorderError;
	property alias pColorBorderOnFocus: oInput.pColorBorderError;
	property alias pColorBorderError: oInput.pColorBorderError;

	property alias pColorBackgroundNormal: oInput.pColorBackgroundNormal;
	property alias pColorBackgroundOnFocus: oInput.pColorBackgroundOnFocus;
	property alias pColorBackgroundError: oInput.pColorBackgroundError;

	property alias pColorTextNormal: oInput.pColorTextNormal;
	property alias pColorTextOnFocus: oInput.pColorTextOnFocus;
	property alias pColorTextError: oInput.pColorTextError;

	property alias pSizeBorder: oInput.pSizeBorder;
	property alias pSizeRadius: oInput.pSizeRadius;

	property alias pFontFamily: oInput.pFontFamily;
	property alias pFontPixelSize: oInput.pFontPixelSize;

	property alias pPaddingLeft: oInput.pPaddingLeft;
	property alias pPaddingRight: oInput.pPaddingRight;

	id: oRoot;
	height: oLabel.height + 2 + oInput.height

	AText {

		id: oLabel;
		width: parent.width;
		horizontalAlignment: Text.AlignLeft;
		text: "NoDefinedLabelText";
		anchors.top: parent.top;
		anchors.left: parent.left;
	}

	AInputTextTemplate {

		id: oInput;
		width: parent.width;
		height: AUIConfig.mElementHeight();
		anchors.bottom: parent.bottom;
		anchors.left: parent.left;
	}
}
