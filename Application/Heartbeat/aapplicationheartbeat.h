// ----------------------------------------------------------
/*!
	\headerfile AApplicationHeartbeat
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 27/07/2022 at 13:44:04
	\endlist
*/
// ----------------------------------------------------------

#ifndef AAPPLICATIONHEARTBEAT_H
#define AAPPLICATIONHEARTBEAT_H

// System includes
#include <QObject>

// Application includes

// Constants and definitions

// Namespace

// Class definitions
class AApplicationHeartbeat : public QObject {

	Q_OBJECT

public:

	explicit AApplicationHeartbeat(QObject *parent = nullptr);
	virtual ~AApplicationHeartbeat(void);

signals:

};

#endif // AAPPLICATIONHEARTBEAT_H
