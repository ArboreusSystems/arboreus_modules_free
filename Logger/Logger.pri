INCLUDEPATH += $$PWD

PRECOMPILED_HEADER = $$PWD/aloggerpch.h

HEADERS += \
	$$PWD/alogger.h \
	$$PWD/aloggeragent.h \
	$$PWD/aloggeragentinterface.h \
	$$PWD/aloggerconfig.h \
	$$PWD/aloggerdatamodels.h \
	$$PWD/aloggerdbagent.h \
	$$PWD/aloggerfileagent.h \
	$$PWD/aloggerglobal.h \
	$$PWD/aloggerpch.h \
	$$PWD/aloggerservice.h

SOURCES += \
	$$PWD/alogger.cpp \
	$$PWD/aloggeragent.cpp \
	$$PWD/aloggerdbagent.cpp \
	$$PWD/aloggerfileagent.cpp \
	$$PWD/aloggerservice.cpp

RESOURCES +=
