!contains(QT, core) {
	QT += core
}

INCLUDEPATH += \
	$$PWD \
	$$PWD/Agents

HEADERS += \
	$$PWD/Agents/adatavalidatestructureagent.h \
	$$PWD/Agents/adatavalidatevalueagent.h \
	$$PWD/adata.h \
	$$PWD/adatadictionary.h \
	$$PWD/adatametatypes.h \
	$$PWD/adatamodels.h \
	$$PWD/adatapch.h \
	$$PWD/adataservice.h \
	$$PWD/adatastructures.h \
	$$PWD/adatavalues.h

SOURCES += \
	$$PWD/Agents/adatavalidatestructureagent.cpp \
	$$PWD/Agents/adatavalidatevalueagent.cpp \
	$$PWD/adata.cpp \
	$$PWD/adatadictionary.cpp \
	$$PWD/adatametatypes.cpp \
	$$PWD/adataservice.cpp \
	$$PWD/adatastructures.cpp \
	$$PWD/adatavalues.cpp
