INCLUDEPATH += \
	$$PWD \
	$$PWD/IOS \

PRECOMPILED_HEADER = $$PWD/aapplicationpch.h

HEADERS += \
	$$PWD/aapplication.h \
	$$PWD/aapplicationconfig.h \
	$$PWD/aapplicationdatamodels.h \
	$$PWD/aapplicationglobalconfig.h \
	$$PWD/aapplicationpch.h \
	$$PWD/aapplicationservice.h \
	$$PWD/aconstants.h \
	$$PWD/aconstantsdefinition.h

SOURCES += \
	$$PWD/aapplication.cpp \
	$$PWD/aapplicationservice.cpp \
	$$PWD/aconstants.cpp

ios {

	OBJECTIVE_HEADERS += \
		$$PWD/IOS/aapplicationiosdatamodels.h \
		$$PWD/IOS/aapplicationiosglobalconfig.h \
		$$PWD/IOS/aapplicationiosnativedelegate.h \

	OBJECTIVE_SOURCES += \
		$$PWD/IOS/aapplicationiosnativedelegate.mm
}
