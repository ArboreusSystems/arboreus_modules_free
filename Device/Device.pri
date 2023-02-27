INCLUDEPATH += $$PWD

HEADERS += \
	$$PWD/adevice.h \
	$$PWD/adevicedatamodels.h \
	$$PWD/adeviceenums.h \
	$$PWD/adevicepch.h

SOURCES += \
	$$PWD/adevice.cpp

ios {

	OBJECTIVE_HEADERS += \
		$$PWD/adeviceios.h

	OBJECTIVE_SOURCES += \
		$$PWD/adeviceios.mm
}

android {

	HEADERS += \
		$$PWD/adeviceandroid.h

	SOURCES += \
		$$PWD/adeviceandroid.cpp
}
