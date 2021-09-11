// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 11/09/2021 at 18:43:47
	\endlist
*/
// ----------------------------------------------------------
#ifndef ACRYPTOGRAPHYAESGLOBAL_H
#define ACRYPTOGRAPHYAESGLOBAL_H

// System includes

// Application includes

// Constants and defintions

// Namespace
namespace ARB {


// -----------
/*!
	\fn inline quint8 mInlineTime(quint8 inX)

	Doc.
*/

inline quint8 mInlineTime(quint8 inX) {

  return ((inX << 1) ^ (((inX >> 7) & 1) * 0x1b));
}


// -----------
/*!
	\fn inline quint8 mInlineMultiply(quint8 inX, quint8 inY)

	Doc.
*/

inline quint8 mInlineMultiply(quint8 inX, quint8 inY) {

	return (
		((inY & 1) * inX) ^ ((inY >> 1 & 1) * mInlineTime(inX)) ^
		((inY >> 2 & 1) * mInlineTime(mInlineTime(inX))) ^ ((inY >> 3 & 1) *
		mInlineTime(mInlineTime(mInlineTime(inX)))) ^ ((inY >> 4 & 1) *
		mInlineTime(mInlineTime(mInlineTime(mInlineTime(inX)))))
	);
}

} // namespace ARB

#endif // ACRYPTOGRAPHYAESGLOBAL_H
