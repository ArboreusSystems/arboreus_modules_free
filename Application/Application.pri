INCLUDEPATH += $$PWD

PRECOMPILED_HEADER = $$PWD/aapplicationpch.h

HEADERS += \
	$$PWD/aapplication.h \
	$$PWD/aapplicationconfig.h \
	$$PWD/aapplicationdatamodels.h \
	$$PWD/aapplicationpch.h \
	$$PWD/aapplicationservice.h \
	$$PWD/aconstants.h \
	$$PWD/aconstantsdefinition.h

SOURCES += \
	$$PWD/aapplication.cpp \
	$$PWD/aapplicationservice.cpp \
	$$PWD/aconstants.cpp
