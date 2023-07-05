INCLUDEPATH += \
	$$PWD \
	$$PWD/Agents

HEADERS += \
	$$PWD/Agents/asettingsreadagent.h \
	$$PWD/Agents/asettingswriteagent.h \
	$$PWD/asettings.h \
	$$PWD/asettingsagent.h \
	$$PWD/asettingsconfig.h \
	$$PWD/asettingsdatamodels.h \
	$$PWD/asettingspch.h \
	$$PWD/asettingsservice.h

SOURCES += \
	$$PWD/Agents/asettingsreadagent.cpp \
	$$PWD/Agents/asettingswriteagent.cpp \
	$$PWD/asettings.cpp \
	$$PWD/asettingsagent.cpp \
	$$PWD/asettingsservice.cpp
