INCLUDEPATH += $$PWD

RESOURCES += \
	$$PWD/QMLComponentsFree.qrc

lupdate_only {

	SOURCES += \
		$$PWD/*.qml \
		$$PWD/Text/*.qml \
		$$PWD/Controls/*.qml
}
