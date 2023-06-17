// ----------------------------------------------------------
/*!
    \class ADataDictionary
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 16/06/2023 at 19:45:48
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "adatadictionary.h"

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

ADataDictionary::ADataDictionary(QObject* parent) : QObject(parent) {}


// -----------
/*!
	\fn

	Doc.
*/

ADataDictionary::~ADataDictionary(void) {}


// -----------
/*!
	\fn

	Doc.
*/

QString ADataDictionary::mCreate(QList<_A_ENUMS_DATA_DICTIONARY_TYPE> inParameters) {

	QString oOutput = "";

	QList<_A_ENUMS_DATA_DICTIONARY_TYPE>::iterator oIteratorParameters;
	for (
		oIteratorParameters = inParameters.begin();
		oIteratorParameters != inParameters.end();
		++oIteratorParameters
	) {
		switch (*oIteratorParameters) {
			case _A_ENUMS_DATA_DICTIONARY_TYPE::Numeric:
				oOutput.append(ADataDictionary::mGetNumeric());
				break;
			case _A_ENUMS_DATA_DICTIONARY_TYPE::AlphaLowerCase:
				oOutput.append(ADataDictionary::mGetAlphaLowerCase());
				break;
			case _A_ENUMS_DATA_DICTIONARY_TYPE::AlphaUpperCase:
				oOutput.append(ADataDictionary::mGetAlphaUpperCase());
				break;
			default:
				break;
		}
	}

	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

QString ADataDictionary::mGetNumeric(void) {

	QString oOutput = "0123456789";
	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

QString ADataDictionary::mGetAlphaLowerCase(void) {

	QString oOutput = "abcdefghijklmnopqrstuvwxyz";
	return oOutput;
}


// -----------
/*!
	\fn

	Doc.
*/

QString ADataDictionary::mGetAlphaUpperCase(void) {

	QString oOutput = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return oOutput;
}

