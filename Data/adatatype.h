// ----------------------------------------------------------
/*!
    \headerfile ADataType
    \title
    \brief Template file wizard/classes/cpp/file.h

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 16/06/2023 at 19:09:54
    \endlist
*/
// ----------------------------------------------------------

#ifndef ADATATYPE_H
#define ADATATYPE_H

// System includes


#include <QObject>

// Application includes

// Constants and definitions

// Namespace
namespace ARB {

// Class definitions
class ADataType : public QObject {

	Q_OBJECT

	public:

		explicit ADataType(QObject* parent = nullptr);
		virtual ~ADataType(void);
};

} // namespace ARB

#endif // ADATATYPE_H
