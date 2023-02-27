// ----------------------------------------------------------
/*!
	\headerfile AUsersReadAgent
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 19/08/2022 at 06:54:46
	\endlist
*/
// ----------------------------------------------------------

#ifndef AUSERSREADAGENT_H
#define AUSERSREADAGENT_H

// System includes
#include <QObject>

// Application includes

// Constants and definitions

// Namespace

// Class definitions
class AUsersReadAgent : public QObject {

	Q_OBJECT

public:

	explicit AUsersReadAgent(QObject *parent = nullptr);
	virtual ~AUsersReadAgent(void);

signals:

};

#endif // AUSERSREADAGENT_H
