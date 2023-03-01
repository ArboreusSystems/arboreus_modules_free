.pragma library

// ----------------------------------------------------------
/*!
	\module
	\title
	\brief Template file files/js/file.js

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 01/03/2023 at 17:43:37
	\endlist
*/
// ----------------------------------------------------------


// -----------
/*!
	\fn

	Function description.
*/

function mConsoleDebugProperties(inObject) {

	const oProperties = Object.getOwnPropertyNames(inObject);
	console.debug("" + inObject.constructor.name + "->OwnPropertyNames: " + oProperties);
}


// -----------
/*!
	\fn

	Function description.
*/

function mConsoleDebugKeys(inObject) {

	const oProperties = Object.keys(inObject);
	console.debug("" + inObject.constructor.name + "->Keys: " + oProperties);
}
