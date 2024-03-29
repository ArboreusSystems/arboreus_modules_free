A_DIR_MODULES_FREE_APPLICATION = $$PWD/Application
A_PRI_MODULES_FREE_APPLICATION = $$A_DIR_MODULES_FREE_APPLICATION/Application.pri
exists($$A_PRI_MODULES_FREE_APPLICATION) {
	include($$A_PRI_MODULES_FREE_APPLICATION)
} else {
	error(No Free Module Application config file $$A_PRI_MODULES_FREE_APPLICATION)
}

A_DIR_MODULES_FREE_CACHE = $$PWD/Cache
A_PRI_MODULES_FREE_CACHE = $$A_DIR_MODULES_FREE_CACHE/Cache.pri
exists($$A_PRI_MODULES_FREE_CACHE) {
	include($$A_PRI_MODULES_FREE_CACHE)
} else {
	error(No Free Module Cache config file $$A_PRI_MODULES_FREE_CACHE)
}

A_DIR_MODULES_FREE_CRYPTOGRAPHY = $$PWD/Cryptography
A_PRI_MODULES_FREE_CRYPTOGRAPHY = $$A_DIR_MODULES_FREE_CRYPTOGRAPHY/Cryptography.pri
exists($$A_PRI_MODULES_FREE_CRYPTOGRAPHY) {
	include($$A_PRI_MODULES_FREE_CRYPTOGRAPHY)
} else {
	error(No Free Module Cryptography config file $$A_PRI_MODULES_FREE_CRYPTOGRAPHY)
}

A_DIR_MODULES_FREE_DATA = $$PWD/Data
A_PRI_MODULES_FREE_DATA = $$A_DIR_MODULES_FREE_DATA/Data.pri
exists($$A_PRI_MODULES_FREE_DATA) {
	include($$A_PRI_MODULES_FREE_DATA)
} else {
	error(No Free Module Data config file $$A_PRI_MODULES_FREE_DATA)
}

A_DIR_MODULES_FREE_DB = $$PWD/DB
A_PRI_MODULES_FREE_DB = $$A_DIR_MODULES_FREE_DB/DB.pri
exists($$A_PRI_MODULES_FREE_DB) {
	include($$A_PRI_MODULES_FREE_DB)
} else {
	error(No Free Module Logger config file $$A_PRI_MODULES_FREE_DB)
}

A_DIR_MODULES_FREE_DB_KEY_VALUE = $$PWD/DBKeyValue
A_PRI_MODULES_FREE_DB_KEY_VALUE = $$A_DIR_MODULES_FREE_DB_KEY_VALUE/DBKeyValue.pri
exists($$A_PRI_MODULES_FREE_DB_KEY_VALUE) {
	include($$A_PRI_MODULES_FREE_DB_KEY_VALUE)
} else {
	error(No Free Module DBKeyValue config file $$A_PRI_MODULES_FREE_DB_KEY_VALUE)
}

A_DIR_MODULES_FREE_DEVICE = $$PWD/Device
A_PRI_MODULES_FREE_DEVICE = $$A_DIR_MODULES_FREE_DEVICE/Device.pri
exists($$A_PRI_MODULES_FREE_DEVICE) {
	include($$A_PRI_MODULES_FREE_DEVICE)
} else {
	error(No Free Module Device config file $$A_PRI_MODULES_FREE_DEVICE)
}

A_DIR_MODULES_FREE_JS_COMPONENTS = $$PWD/JSComponents
A_PRI_MODULES_FREE_JS_COMPONENTS = $$A_DIR_MODULES_FREE_JS_COMPONENTS/JSComponents.pri
exists($$A_PRI_MODULES_FREE_JS_COMPONENTS) {
	include($$A_PRI_MODULES_FREE_JS_COMPONENTS)
} else {
	error(No Free Module JSComponents config file $$A_PRI_MODULES_FREE_JS_COMPONENTS)
}

A_DIR_MODULES_FREE_LOGGER = $$PWD/Logger
A_PRI_MODULES_FREE_LOGGER = $$A_DIR_MODULES_FREE_LOGGER/Logger.pri
exists($$A_PRI_MODULES_FREE_LOGGER) {
	include($$A_PRI_MODULES_FREE_LOGGER)
} else {
	error(No Free Module Logger config file $$A_PRI_MODULES_FREE_LOGGER)
}

A_DIR_MODULES_FREE_MANIFEST = $$PWD/Manifest
A_PRI_MODULES_FREE_MANIFEST = $$A_DIR_MODULES_FREE_MANIFEST/Manifest.pri
exists($$A_PRI_MODULES_FREE_MANIFEST) {
	include($$A_PRI_MODULES_FREE_MANIFEST)
} else {
	error(No Free Module Manifest config file $$A_PRI_MODULES_FREE_MANIFEST)
}

A_DIR_MODULES_FREE_NETWORK = $$PWD/Network
A_PRI_MODULES_FREE_NETWORK = $$A_DIR_MODULES_FREE_NETWORK/Network.pri
exists($$A_PRI_MODULES_FREE_NETWORK) {
	include($$A_PRI_MODULES_FREE_NETWORK)
} else {
	error(No Free Module Settings config file $$A_PRI_MODULES_FREE_NETWORK)
}

A_DIR_MODULES_FREE_PROPERTIES = $$PWD/Properties
A_PRI_MODULES_FREE_PROPERTIES = $$A_DIR_MODULES_FREE_PROPERTIES/Properties.pri
exists($$A_PRI_MODULES_FREE_PROPERTIES) {
	include($$A_PRI_MODULES_FREE_PROPERTIES)
} else {
	error(No Free Module Logger config file $$A_PRI_MODULES_FREE_PROPERTIES)
}

A_DIR_MODULES_FREE_QML_COMPONENTS = $$PWD/QMLComponents
A_PRI_MODULES_FREE_QML_COMPONENTS = $$A_DIR_MODULES_FREE_QML_COMPONENTS/QMLComponentsFree.pri
exists($$A_PRI_MODULES_FREE_QML_COMPONENTS) {
	include($$A_PRI_MODULES_FREE_QML_COMPONENTS)
} else {
	error(No Free Module QML Components config file $$A_PRI_MODULES_FREE_QML_COMPONENTS)
}

A_DIR_MODULES_FREE_SETTINGS = $$PWD/Settings
A_PRI_MODULES_FREE_SETTINGS = $$A_DIR_MODULES_FREE_SETTINGS/Settings.pri
exists($$A_PRI_MODULES_FREE_SETTINGS) {
	include($$A_PRI_MODULES_FREE_SETTINGS)
} else {
	error(No Free Module Settings config file $$A_PRI_MODULES_FREE_SETTINGS)
}

A_DIR_MODULES_FREE_TEMPLATES = $$PWD/Templates
A_PRI_MODULES_FREE_TEMPLATES = $$A_DIR_MODULES_FREE_TEMPLATES/Templates.pri
exists($$A_PRI_MODULES_FREE_TEMPLATES) {
	include($$A_PRI_MODULES_FREE_TEMPLATES)
} else {
	error(No Free Module Templates config file $$A_PRI_MODULES_FREE_TEMPLATES)
}

A_DIR_MODULES_FREE_UIHANDLER = $$PWD/UIHandler
A_PRI_MODULES_FREE_UIHANDLER = $$A_DIR_MODULES_FREE_UIHANDLER/UIHandler.pri
exists($$A_PRI_MODULES_FREE_UIHANDLER) {
	include($$A_PRI_MODULES_FREE_UIHANDLER)
} else {
	error(No Free Module UIHandler config file $$A_PRI_MODULES_FREE_UIHANDLER)
}

A_DIR_MODULES_FREE_UNIVERSAL = $$PWD/Universal
A_PRI_MODULES_FREE_UNIVERSAL = $$A_DIR_MODULES_FREE_UNIVERSAL/Universal.pri
exists($$A_PRI_MODULES_FREE_UNIVERSAL) {
	include($$A_PRI_MODULES_FREE_UNIVERSAL)
} else {
	error(No Free Module Logger config file $$A_PRI_MODULES_FREE_UNIVERSAL)
}

A_DIR_MODULES_FREE_USERS_HANDLER = $$PWD/UsersHandler
A_PRI_MODULES_FREE_USERS_HANDLER = $$A_DIR_MODULES_FREE_USERS_HANDLER/UsersHandler.pri
exists($$A_PRI_MODULES_FREE_USERS_HANDLER) {
	include($$A_PRI_MODULES_FREE_USERS_HANDLER)
} else {
	error(No Free Module UsersHandler config file $$A_PRI_MODULES_FREE_USERS_HANDLER)
}
