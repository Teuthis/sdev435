//-----------------------------------------------------------------------------
/**
File: XmlDocument.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Implementation file for an XML document
*/
//-----------------------------------------------------------------------------

#include "XmlDocument.h"

/// Default constructs a new XmlDocument. The root element is initialized
/// to "XMLROOT" and encoding defaults to UTF-8
XmlDocument::XmlDocument()
	: encoding("UTF-8"), root(std::make_shared<XmlNode>(XmlNode("documentRoot")))
{
}

/// Constructs a new XmlDocument with the encoding type set to UTF-8 and
/// with the specified root element
/// @param rootElement The element type of the root node
XmlDocument::XmlDocument(std::string rootElement)
	: encoding("UTF-8"), root(std::make_shared<XmlNode>(XmlNode(rootElement)))
{
}

/// Constructs a new XmlDocument with the specified root and encoding
/// @param rootElement The element type of the root node
/// @param docEncoding The document encoding of the XML file
XmlDocument::XmlDocument(std::string rootElement, std::string docEncoding)
	: encoding(docEncoding), 
	root(std::make_shared<XmlNode>(XmlNode(rootElement)))
{
}

/// Destroys the XmlDocument
XmlDocument::~XmlDocument()
{
}

/// Sets a new root node with the specified element
/// @param rootElement The element type of the root node
void XmlDocument::setRoot(std::string rootElement)
{
	root = std::make_shared<XmlNode>(XmlNode(rootElement));
}

/// Sets the root node to the specified XmlNode
/// @param rootNode An XmlNode that will be the new root node
void XmlDocument::setRoot(XmlNode rootNode)
{
	root = std::make_shared<XmlNode>(rootNode);
}

/// Gets a pointer to the root XmlNode
/// @return A shared_ptr to the document's root node
std::shared_ptr<XmlNode> XmlDocument::getRoot()
{
	return root;
}

/// Gets the document as an XML string
/// @return A string containing the document's XML
std::string XmlDocument::toXmlString() const
{
	return getProlog() + root->toXmlString(true);
}

/// Gets a collection of pointers to all nodes of the specified element type
/// @param searchElement The element string to search for
/// @return A vector of shared_ptrs to all matching nodes
std::vector<std::shared_ptr<XmlNode>> 
	XmlDocument::getNodesByElement(std::string searchElement,
		const bool caseInsensitive) const
{
	if (caseInsensitive) {
		std::transform(searchElement.begin(), searchElement.end(),
			searchElement.begin(), toupper);
	}	
	std::vector<std::shared_ptr<XmlNode>> results;
	getNodesByElement(searchElement, caseInsensitive, root, results);
	return results;
}

/// Gets the XML prolog for this document as a string
/// @return The XML prolog as string
std::string XmlDocument::getProlog() const
{
	return "<?xml version=\"1.0\" encoding=\"" + encoding + "\"?>\n";
}

/// Recursively adds nodes that match the desired element type to the
/// result collection
/// @param searchElement The element string to search for
/// @param currentNode The node currently being examined
/// @param results A reference to the result vector
void XmlDocument::getNodesByElement(std::string searchElement,
	bool caseInsensitive,
	std::shared_ptr<XmlNode> currentNode,
	std::vector<std::shared_ptr<XmlNode>>& results) const
{
	std::string currentElement = currentNode->getElement();
	if (caseInsensitive) {
		std::transform(currentElement.begin(), currentElement.end(),
			currentElement.begin(), toupper);
	}
	if (currentElement == searchElement) {
		results.push_back(currentNode);
	}
	for (int i = 0; i < currentNode->getChildCount(); i++) {
		getNodesByElement(searchElement, caseInsensitive, 
			(*currentNode)[i], results);
	}
}
