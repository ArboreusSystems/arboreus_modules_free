INCLUDEPATH += \
	$$PWD \
	$$PWD/Delegate \
	$$PWD/Heartbeat

HEADERS += \
	$$PWD/Delegate/aapplicationdelegatedatamodels.h \
	$$PWD/Delegate/aapplicationdelegateglobalconfig.h \
	$$PWD/Heartbeat/aapplicationheartbeat.h \
	$$PWD/aapplication.h \
	$$PWD/aapplicationconfig.h \
	$$PWD/aapplicationdatamodels.h \
	$$PWD/aapplicationglobalconfig.h \
	$$PWD/aapplicationpch.h \
	$$PWD/aapplicationservice.h \
	$$PWD/aconstants.h \
	$$PWD/aconstantsdefinition.h

SOURCES += \
	$$PWD/Heartbeat/aapplicationheartbeat.cpp \
	$$PWD/aapplication.cpp \
	$$PWD/aapplicationservice.cpp \
	$$PWD/aconstants.cpp

ios {

	INCLUDEPATH += \
		$$PWD/Delegate/IOS

	HEADERS += \
		$$PWD/Delegate/IOS/aapplicationdelegateiosdatamodels.h \
		$$PWD/Delegate/IOS/aapplicationdelegateiosglobalconfig.h

	SOURCES +=

	OBJECTIVE_HEADERS += \
		$$PWD/Delegate/IOS/aapplicationdelegateiosnative.h

	OBJECTIVE_SOURCES += \
		$$PWD/Delegate/IOS/aapplicationdelegateiosnative.mm
}

android {

	INCLUDEPATH += \
		$$PWD/Delegate/Android

	HEADERS +=

	SOURCES +=
}
