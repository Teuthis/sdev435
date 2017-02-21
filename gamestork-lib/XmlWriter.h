//-----------------------------------------------------------------------------
/**
File: XmlWriter.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Header file for XmlWriter class.
*/
//-----------------------------------------------------------------------------

#pragma once

#include <fstream>
#include <string>
#include "XmlDocument.h"

/// Writes an XmlDocument to a file.
class XmlWriter
{
public:
	/// No default constructor
	XmlWriter() = delete;

	/// Constructs a new XmlWriter object for the specified document
	/// @param xmlDocument The XmlDocument to write
	XmlWriter(const XmlDocument& xmlDocument);

	/// Destroys the XmlWriter object
	~XmlWriter();
	
	/// Writes the XmlDocument to the specified file
	/// @param filename The filename with path to write to
	/// @return A boolean indicating whether the file was writen successfully
	bool write(std::string filename) const;

private:
	/// Reference to the document that is to be written
	const XmlDocument& document;
};

