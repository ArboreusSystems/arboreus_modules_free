INCLUDEPATH += \
	$$PWD \
	$$PWD/Delegate \
	$$PWD/Heartbeat

PRECOMPILED_HEADER = $$PWD/aapplicationpch.h

HEADERS += \
	$$PWD/Heartbeat/aapplicationheartbeat.h \
	$$PWD/Heartbeat/aapplicationheartbeatconfig.h \
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

	OBJECTIVE_HEADERS += \
		$$PWD/Delegate/aapplicationdelegatedatamodels.h \
		$$PWD/Delegate/aapplicationdelegateglobalconfig.h \
		$$PWD/Delegate/aapplicationdelegateiosnative.h

	OBJECTIVE_SOURCES += \
		$$PWD/Delegate/aapplicationdelegateiosnative.mm
}
