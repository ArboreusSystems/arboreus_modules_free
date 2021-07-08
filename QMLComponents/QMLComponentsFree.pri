INCLUDEPATH += $$PWD

RESOURCES += \
	$$PWD/QMLComponentsFree.qrc

lupdate_only {

	SOURCES += \
		$$PWD/*.qml \
		$$PWD/Inputs/*.qml \
		$$PWD/Controls/*.qml \
		$$PWD/Templates/*.qml \
		$$PWD/Templates/Headers/*.qml \
		$$PWD/Templates/Inputs/*.qml \
		$$PWD/Templates/Text/*.qml \
		$$PWD/Text/*.qml
}

