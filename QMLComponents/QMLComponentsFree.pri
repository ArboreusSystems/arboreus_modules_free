INCLUDEPATH += $$PWD

RESOURCES += \
	$$PWD/QMLComponentsFree.qrc

lupdate_only {

	SOURCES += \
		$$PWD/*.qml \
		$$PWD/Inputs/*.qml \
		$$PWD/Controls/*.qml \
		$$PWD/Templates/*.qml \
		$$PWD/Text/*.qml
}
