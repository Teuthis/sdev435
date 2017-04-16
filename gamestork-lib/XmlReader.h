//-----------------------------------------------------------------------------
/**
File: XmlReader.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Header file for an XML parsing reader
*/
//-----------------------------------------------------------------------------

#pragma once

#include <stack>
#include <fstream>
#include <string>
#include <ios>
#include <algorithm>
#include "XmlDocument.h"

/// Represents the reader state machine's state
enum XML_READER_STATE {
	XMLSTATE_FINISHED,
	XMLSTATE_INVALID,
	XMLSTATE_PROLOG_OPEN,
	XMLSTATE_PROLOG_KEYVAL,
	XMLSTATE_ELEMENT_OPEN,
	XMLSTATE_ELEMENT_BODY,
	XMLSTATE_ELEMENT_KEYVAL,
	XMLSTATE_ELEMENT_INNERVALUE,
	XMLSTATE_ELEMENT_CLOSE,
	XMLSTATE_ELEMENT_SELFCLOSE
};

class XmlReader
{
public:
	/// Constructs a new XmlReader object. The reader will need to be opened
	/// with a filename in order for the document to be read.
	XmlReader();

	/// Constructs a new XmlReader and reads the data from the provided filename
	/// @param filename The path and name of the file to read from
	/// @throws std::ios_base::failure if the file cannot be opened
	XmlReader(const std::string filename);
	
	/// Destroys the XmlReader object
	~XmlReader();

	/// Opens a file and reads the XML from it
	/// @param filename The path and name of the file to read from
	/// @throws std::ios_base::failure if the file cannot be opened
	void open(const std::string filename);

	/// Checks whether the XmlDocument has been constructed successfully
	/// @return true if the XML was successfully read, false otherwise
	bool isXmlReady() const;

	/// Gets the XmlDocument
	/// @return A copy of the XmlDocument read from the file
	XmlDocument getDocument() const;

private:
	/// The document result
	XmlDocument document;

	/// Working stack of nodes
	std::stack<XmlNode> nodeStack;

	/// The file being read from
	std::ifstream stream;

	/// The state of the XmlDocument
	bool xmlReady;

	/// Initiates and controls the reading process
	void read();

	// Reading/parsing is implemented as a sort of state machine.
	// Each function can read a certain component of the document
	// and then returns a value indicating what the next state is.
	// It keeps the branching under control, while being a little
	// easier to manage than a single characater state machine. 
	
	/// Handles the beginning of the XML prolog
	/// @return The next reading state
	XML_READER_STATE prologOpening();

	/// Handles any attributes in the prolog
	/// @return The next reading state
	XML_READER_STATE prologKeyValPair();

	/// Handles the element name of an opening tag
	/// @return The next reading state
	XML_READER_STATE elementOpening();

	/// State router inside an element tag
	/// @return The next reading state
	XML_READER_STATE elementBody();

	/// Handles element attributes
	/// @return The next reading state
	XML_READER_STATE elementKeyValPair();

	/// Handles the inner value of an element
	/// @return The next reading state
	XML_READER_STATE elementInnerValue();

	/// Handles closing an element and constructing the node tree
	/// @return The next reading state
	XML_READER_STATE elementClosing(bool selfClose = false);
};

