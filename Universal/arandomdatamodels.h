// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 07/10/2021 at 13:51:03
	\endlist
*/
// ----------------------------------------------------------
#ifndef ARANDOMDATAMODELS_H
#define ARANDOMDATAMODELS_H

// System includes

// Precompiled includes
#include <auniversalpch.h>

// Application includes

// Constants and defintions
#define _A_NUMBER_DECA 10
#define _A_NUMBER_HECTO 100
#define _A_NUMBER_KILO 1000
#define _A_NUMBER_MEGA 1000000
#define _A_NUMBER_GIGA 1000000000
#define _A_NUMBER_TERA 1000000000000
#define _A_NUMBER_PETA 1000000000000000
#define _A_NUMBER_EXA 1000000000000000000

#define _A_ENUMS_RANDOM_DICTIONARY_TYPE ARB::AEnumsRandomDictionaryType::RandomDictionaryType
#define _A_ENUMS_RANDOM_EXPONENT ARB::AEnumsRandomExponent::RandomExponent


// Namespace
namespace ARB {

class AEnumsRandomDictionaryType: public QObject {

	Q_OBJECT

	public:

		enum class RandomDictionaryType: int {

			Free,
			Positive,
			Negative
		};
		Q_ENUM(RandomDictionaryType)
};

class AEnumsRandomExponent: public QObject {

	Q_OBJECT

	public:

		enum class RandomExponent: int {

			Deca,
			Hecto,
			Kilo,
			Mega,
			Giga,
			Tera,
			Peta,
			Exa,
			Full
		};
		Q_ENUM(RandomExponent)
};

} // namespace ARB

#endif // ARANDOMDATAMODELS_H
