// ----------------------------------------------------------
/*!
	\headerfile AUsersUpdateAgent
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 19/08/2022 at 06:55:12
	\endlist
*/
// ----------------------------------------------------------

#ifndef AUSERSUPDATEAGENT_H
#define AUSERSUPDATEAGENT_H

// System includes
#include <QObject>

// Application includes

// Constants and definitions

// Namespace

// Class definitions
class AUsersUpdateAgent : public QObject {

	Q_OBJECT

public:

	explicit AUsersUpdateAgent(QObject *parent = nullptr);
	virtual ~AUsersUpdateAgent(void);

signals:

};

#endif // AUSERSUPDATEAGENT_H
