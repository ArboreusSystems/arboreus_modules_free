// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 01/05/2021 at 12:42:13
	\endlist
*/
// ----------------------------------------------------------
#ifndef ALOGGERDATAMODELS_H
#define ALOGGERDATAMODELS_H

// System includes

// Precompiled includes
#include <aloggerpch.h>

// Application includes

// Constants and defintions
#define _A_ENUM_LOGGER_LOGBOOK_TYPE ARB::AEnumsLoggerLogbookType::Type


// Namespace
namespace ARB {

class AEnumsLoggerLogbookType: public QObject {

	Q_OBJECT

	public:

		enum class Type: int {

			DB, File
		};
		Q_ENUM(Type)
};

} // namespace ARB

// Namespace
namespace ARB {

class ALoggerMessageModel {

	public:

		unsigned long long Time = 0;
		QtMsgType Type = QtMsgType::QtDebugMsg;
		const char* Author = "EMP";
		QByteArray ThreadID = {};
		QByteArray Message = {};
		const char* Function = "NoFunction";
		const char* File = "NoFile";
		int Line = 0;

		explicit ALoggerMessageModel(void) {}
		virtual ~ALoggerMessageModel(void) {}
};

}
Q_DECLARE_METATYPE(ARB::ALoggerMessageModel)

// Namespace
namespace ARB {

class ALoggerServiceProperties {

	public:

		QString PathLoggerDB = "NoPathLoggerDB";
		QString PathLoggerFile = "PathLoggerFile";
		QObject* ConfigObject = nullptr;

		explicit ALoggerServiceProperties(void) {}
		virtual ~ALoggerServiceProperties(void) {}
};

}
Q_DECLARE_METATYPE(ARB::ALoggerServiceProperties)

#endif // ALOGGERDATAMODELS_H
