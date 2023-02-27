// ----------------------------------------------------------
/*!
	\headerfile AUsersDeleteAgent
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 19/08/2022 at 06:55:44
	\endlist
*/
// ----------------------------------------------------------

#ifndef AUSERSDELETEAGENT_H
#define AUSERSDELETEAGENT_H

// System includes
#include <QObject>

// Application includes

// Constants and definitions

// Namespace

// Class definitions
class AUsersDeleteAgent : public QObject {

	Q_OBJECT

public:

	explicit AUsersDeleteAgent(QObject *parent = nullptr);
	virtual ~AUsersDeleteAgent(void);

signals:

};

#endif // AUSERSDELETEAGENT_H
