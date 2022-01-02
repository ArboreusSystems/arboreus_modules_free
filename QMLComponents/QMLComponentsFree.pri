INCLUDEPATH += $$PWD

RESOURCES += \
	$$PWD/QMLComponentsFree.qrc

lupdate_only {

	SOURCES += \
		$$PWD/*.qml \
		$$PWD/Application/*.qml \
		$$PWD/Content/*.qml \
		$$PWD/Controls/*.qml \
		$$PWD/Templates/*.qml \
		$$PWD/Templates/Buttons/*.qml \
		$$PWD/Templates/Headers/*.qml \
		$$PWD/Templates/Inputs/*.qml \
		$$PWD/Templates/Menu/*.qml \
		$$PWD/Templates/Text/*.qml
}

DISTFILES +=

