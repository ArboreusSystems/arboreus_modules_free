QT += sql

INCLUDEPATH += $$PWD

HEADERS += \
	$$PWD/adbdatamodels.h \
	$$PWD/adbpch.h \
	$$PWD/adbsqlgenerator.h \
	$$PWD/adbsqlite.h \
	$$PWD/adbsqlitecipher.h

SOURCES += \
	$$PWD/adbsqlgenerator.cpp \
	$$PWD/adbsqlite.cpp \
	$$PWD/adbsqlitecipher.cpp
