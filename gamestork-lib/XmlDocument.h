//-----------------------------------------------------------------------------
/**
File: XmlDocument.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Header file for an XML document
*/
//-----------------------------------------------------------------------------

#pragma once

#include <string>
#include <memory>
#include "XmlNode.h"

/// Represents an XML document composed of a prolog and element nodes
class XmlDocument
{
public:
	/// Default constructs a new XmlDocument. The root element is initialized
	/// to "XMLROOT" and encoding defaults to UTF-8
	XmlDocument();

	/// Constructs a new XmlDocument with the encoding type set to UTF-8 and
	/// with the specified root element
	/// @param rootElement The element type of the root node
	XmlDocument(std::string rootElement);

	/// Constructs a new XmlDocument with the specified root and encoding
	/// @param rootElement The element type of the root node
	/// @param docEncoding The document encoding of the XML file
	XmlDocument(std::string rootElement, std::string docEncoding);

	/// Destroys the XmlDocument
	~XmlDocument();

	/// Sets a new root node with the specified element
	/// @param rootElement The element type of the root node
	void setRoot(std::string rootElement);

	/// Sets the root node to the specified XmlNode
	/// @param rootNode An XmlNode that will be the new root node
	void setRoot(XmlNode rootNode);

	/// Gets a pointer to the root XmlNode
	/// @return A shared_ptr to the document's root node
	std::shared_ptr<XmlNode> getRoot();

	/// Gets the document as an XML string
	/// @return A string containing the document's XML
	std::string toXmlString() const;

	/// Gets a collection of pointers to all nodes of the specified element type
	/// @param searchElement The element string to search for
	/// @return A vector of shared_ptrs to all matching nodes
	std::vector<std::shared_ptr<XmlNode>>
		getNodesByElement(std::string searchElement) const;


private:
	/// The encoding format of the XML document. At the moment, only UTF-8 is 
	/// properly supported.
	std::string encoding;

	/// A pointer to the root node
	std::shared_ptr<XmlNode> root;

	/// Gets the XML prolog for this document as a string
	/// @return The XML prolog as string
	std::string getProlog() const;

	/// Recursively adds nodes that match the desired element type to the
	/// result collection
	/// @param searchElement The element string to search for
	/// @param currentNode The node currently being examined
	/// @param results A reference to the result vector
	void getNodesByElement(std::string searchElement, 
		std::shared_ptr<XmlNode> currentNode,
		std::vector<std::shared_ptr<XmlNode>>& results) const;
};

