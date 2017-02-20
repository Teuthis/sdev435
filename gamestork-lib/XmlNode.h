//-----------------------------------------------------------------------------
/**
File: XmlNode.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Header file for an XML node
*/
//-----------------------------------------------------------------------------

#pragma once

#include <memory>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdexcept>

/// Represents an XML element and its attributes and value/children
class XmlNode
{
public:
	/// Default constructs a new XmlNode
	XmlNode();

	/// Constructs a new XmlNode of the specified element type
	/// @param element The element type of the new node
	XmlNode(std::string element);

	/// Destroys the current XmlNode and all its children
	~XmlNode();

	/// Adds a new child node of the specified element type
	/// @param newElement The element type of the new child
	/// @return A weak to the newly created child node
	std::shared_ptr<XmlNode> addChild(std::string newElement);

	/// Adds a new child node of the specified element type
	/// @param newElement The element type of the new child
	/// @param value The inner value of the new child
	/// @return A weak to the newly created child node
	std::shared_ptr<XmlNode> addChild(
		std::string newElement, std::string value);

	/// Adds an existing XmlNode as a child of the current node
	/// @param The XmlNode to add
	/// @return A weak pointer to the newly added child node
	std::shared_ptr<XmlNode> addChild(XmlNode child);

	/// Adds an existing XmlNode as a child of the current node
	/// @param A unique pointer to the XmlNode to add
	/// @return A weak pointer to the newly added child node
	//XmlNode & addChild(std::unique_ptr<XmlNode> child);

	/// Sets a new attribute or changes an existing attribute
	/// @param key The identifying key for the new attribute
	/// @param value The value of the new attribute
	void setAttribute(const std::string key, std::string value);

	/// Gets the list of existing attribute keys
	/// @return A vector containing all the attribute key strings
	const std::vector<std::string> keys() const;

	/// Gets the current value of the given attribute
	/// @param key The identifying key of the attribute to retrieve
	/// @return The value of the requested attribute or an empty string if
	///			the key does not exist
	std::string getAttribute(std::string key) const;

	/// Sets or changes the node's element type
	/// @param newElement The new element type string
	void setElement(std::string newElement);

	/// Gets the node's element type
	/// @return The current element type string
	std::string getElement() const;

	/// Sets the node's inner value
	/// @param value The new inner value
	/// @throw 
	void setInnerValue(std::string value);

	std::string getInnerValue();

	/// Gets the number of children this node contains
	/// @return The number of child nodes
	size_t getChildCount() const;

	/// Gets a pointer to the child node at the given index
	/// @param index The index of the child node to get
	/// @return A reference to the requested XmlNode
	std::shared_ptr<XmlNode> operator[](int index);

	/// Gets the node's contents in XML text format
	/// @param recurse Boolean indicating whether to recursively get the XML
	///				for the node's children. Defaults to true.
	/// @return An XML string representing the node and possibly its children
	std::string toXmlString(bool recurse = true) const;

	
private:
	/// The XML element type
	std::string element;

	/// Attribute key/value pairs
	std::map<std::string, std::string> attributes;

	/// Inner XML value
	std::string innerValue;

	/// Child node collection
	std::vector<std::shared_ptr<XmlNode>> children;

	/// Gets the node's contents in XML text format
	/// @param stream Reference to a stringstream object to write the XML to
	/// @param recurse Boolean indicating whether to recursively get the XML
	///				for the node's children. Defaults to true.
	/// @param depth The nesting depth for XML indenting
	void toXmlString(std::stringstream &stream, bool recurse, int depth = 0) const;
};

