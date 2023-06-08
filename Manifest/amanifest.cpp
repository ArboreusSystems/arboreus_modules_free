// ----------------------------------------------------------
/*!
    \class AManifest
    \title
    \brief Template file classes/cpp/file.cpp

    \list
    \li @notice Template file classes/file.h
    \li @copyright Arboreus (http://arboreus.systems)
    \li @author Alexandr Kirilov (http://alexandr.kirilov.me)
    \li @created 05/06/2023 at 08:50:52
    \endlist
*/
// ----------------------------------------------------------

// Class header
#include "amanifest.h"

// Namespace
using namespace ARB;


// -----------
/*!
    \fn

    Doc.
*/

AManifest::AManifest(QObject* parent) : QObject(parent) {

	_A_DEBUG << "AManifest created";
}


// -----------
/*!
	\fn

	Doc.
*/

AManifest::~AManifest(void) {

	_A_DEBUG << "AManifest deleted";
}


// -----------
/*!
	\fn

	Doc.
*/

AManifestReply AManifest::mLoad(AManifestProperties inProperties) {

	AManifestReply oOutput;

	pProperties = inProperties;

	if(ADir::mEnsure(pProperties.Path)) {
		_A_DEBUG << "Ensured manifest path:" << pProperties.Path;
	} else {
		oOutput.Type = _A_ENUM_MANIFEST_REPLY_TYPE::WrongPath;
		oOutput.Data = pProperties.Path;
		_A_CRITICAL << "The path for manifest file not ensured:" << pProperties.Path;
	}

	_A_DEBUG << "Mainfest loaded" << pProperties.Path;


	return oOutput;
}



