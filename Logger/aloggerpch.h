// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 11/09/2021 at 10:07:27
	\endlist
*/
// ----------------------------------------------------------
#ifndef ALOGGERPCH_H
#define ALOGGERPCH_H

#if defined __cplusplus

// System includes
#include <QObject>
#include <QDateTime>
#include <QDebug>
#include <QThread>
#include <QString>
#include <QList>
#include <QByteArray>
#include <string>
#include <stdio.h>

#if !defined(A_CONSOLE_APPLICATION)
#include <QQmlEngine>
#endif

// Qt 5 System includes
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
#include <QStringRef>
#endif

// Application includes

// Constants and defintions

// Namespace

#endif

#endif // ALOGGERPCH_H
