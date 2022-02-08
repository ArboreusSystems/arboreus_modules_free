// ----------------------------------------------------------
/*!
	\qmltype
	\brief

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 08/07/2021 at 13:59:46
	\endlist
*/
// ----------------------------------------------------------

// System includes
import QtQuick 2.15

// Application includes

// Application paths
import "qrc:/ModulesFree/QMLComponents/Text";


// Component
ATextTemplate {

	id: oRoot;
	color: AColors.mGetString("White");
	font.pixelSize: AUIConfig.mFontSizeHeader();
	anchors.verticalCenter: parent.verticalCenter;
}
