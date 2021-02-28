// ----------------------------------------------------------
/*!
	\headerfile ALogger
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 28/02/2021 at 14:49:26
	\endlist
*/
// ----------------------------------------------------------

#ifndef ALOGGER_H
#define ALOGGER_H

// System includes
#include <QObject>

// Application includes

// Constants and definitions

// Namespace

// Class definitions
class ALogger : public QObject {

	Q_OBJECT

public:

	explicit ALogger(QObject *parent = nullptr);
	virtual ~ALogger(void);

signals:

};

#endif // ALOGGER_H
