// ----------------------------------------------------------
/*!
	\qmltype
	\brief

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 10/05/2021 at 11:26:14
	\endlist
*/
// ----------------------------------------------------------

// System includes
import QtQuick 2.15

// Application includes


// Component
Text {

	id: oRoot;
	font.family: AFonts.mFontFamily();

	Connections {

		target: AFonts;
		function onSgFontChanged() {

			oRoot.font.family = AFonts.mFontFamily();
		}
	}
}
