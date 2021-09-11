QT += network

INCLUDEPATH += $$PWD

PRECOMPILED_HEADER = $$PWD/anetworkpch.h

HEADERS += \
	$$PWD/anetwork.h \
	$$PWD/anetworkagent.h \
	$$PWD/anetworkdatamodels.h \
	$$PWD/anetworkpch.h \
	$$PWD/anetworkservice.h

SOURCES += \
	$$PWD/anetwork.cpp \
	$$PWD/anetworkagent.cpp \
	$$PWD/anetworkservice.cpp
