// ----------------------------------------------------------
/*!
	\headerfile AProperties
	\title
	\brief Template file wizard/classes/cpp/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 28/02/2021 at 15:01:40
	\endlist
*/
// ----------------------------------------------------------

#ifndef APROPERTIES_H
#define APROPERTIES_H

// System includes
#include <QObject>

// Application includes

// Constants and definitions

// Namespace

// Class definitions
class AProperties : public QObject {

	Q_OBJECT

public:

	explicit AProperties(QObject *parent = nullptr);
	virtual ~AProperties(void);

signals:

};

#endif // APROPERTIES_H
