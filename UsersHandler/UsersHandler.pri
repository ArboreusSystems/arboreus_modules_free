INCLUDEPATH += \
	$$PWD \
	$$PWD/Agents

HEADERS += \
    $$PWD/Agents/auserscreateagent.h \
    $$PWD/Agents/ausersdeleteagent.h \
    $$PWD/Agents/ausersreadagent.h \
    $$PWD/Agents/ausersupdateagent.h \
    $$PWD/ausershandler.h \
    $$PWD/ausershandlerconfig.h \
    $$PWD/ausershandlerdatamodels.h \
    $$PWD/ausershandlerobjects.h \
    $$PWD/ausershandlerpch.h \
    $$PWD/ausershandlerservice.h

SOURCES += \
    $$PWD/Agents/auserscreateagent.cpp \
    $$PWD/Agents/ausersdeleteagent.cpp \
    $$PWD/Agents/ausersreadagent.cpp \
    $$PWD/Agents/ausersupdateagent.cpp \
    $$PWD/ausershandler.cpp \
    $$PWD/ausershandlerobjects.cpp \
    $$PWD/ausershandlerservice.cpp
