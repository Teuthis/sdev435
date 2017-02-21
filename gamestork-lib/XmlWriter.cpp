//-----------------------------------------------------------------------------
/**
File: XmlWriter.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Implementation file for XmlWriter class.
*/
//-----------------------------------------------------------------------------

#include "XmlWriter.h"

/// Constructs a new XmlWriter object for the specified document
/// @param xmlDocument The XmlDocument to write
XmlWriter::XmlWriter(const XmlDocument & xmlDocument)
	: document(xmlDocument)
{
}

/// Destroys the XmlWriter object
XmlWriter::~XmlWriter()
{
}

/// Writes the XmlDocument to the specified file
/// @param filename The filename with path to write to
/// @return A boolean indicating whether the file was writen successfully
bool XmlWriter::write(std::string filename) const
{
	std::ofstream stream;
	stream.open(filename, std::ios::out);
	if (!stream.is_open()) {
		return false;
	}
	stream << document.toXmlString();
	stream.close();
	return true;
}
