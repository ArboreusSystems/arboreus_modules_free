QT += sql

INCLUDEPATH += $$PWD

PRECOMPILED_HEADER = $$PWD/adbpch.h

HEADERS += \
	$$PWD/adbdatamodels.h \
	$$PWD/adbpch.h \
	$$PWD/adbsqlcipher.h

SOURCES += \
	$$PWD/adbsqlcipher.cpp
