//-----------------------------------------------------------------------------
/**
File: XmlNode.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Implementation file for an XML node
*/
//-----------------------------------------------------------------------------

#include "XmlNode.h"

/// Default constructs a new XmlNode
XmlNode::XmlNode()
	: element("XMLNODE"), attributes(), innerValue(""), children()
{
}

/// Constructs a new XmlNode of the specified element type
/// @param element The element type of the new node
XmlNode::XmlNode(std::string element)
	: element(element), attributes(), innerValue(""), children()
{
}

/// Destroys the current XmlNode and all its children
XmlNode::~XmlNode()
{
}

/// Adds a new child node of the specified element type
/// @param element The element type of the new child
/// @return A reference to the newly created child node
std::shared_ptr<XmlNode> XmlNode::addChild(std::string newElement)
{
	children.push_back(std::make_shared<XmlNode>(XmlNode(newElement)));
	return children.at(children.size() - 1);
}

std::shared_ptr<XmlNode> XmlNode::addChild(
	std::string newElement, std::string value)
{
	children.push_back(std::make_shared<XmlNode>(XmlNode(newElement)));
	children[children.size() - 1]->innerValue = value;
	return children.at(children.size() - 1);
}

/// Adds an existing XmlNode as a child of the current node
/// @param The XmlNode to add
std::shared_ptr<XmlNode> XmlNode::addChild(XmlNode child)
{
	children.push_back(std::make_shared<XmlNode>(child));
	return children.at(children.size() - 1);
}

//XmlNode & XmlNode::addChild(std::unique_ptr<XmlNode> child)
//{
//	children.push_back(child);
//	return *(children.at(children.size() - 1));
//}

/// Sets a new attribute or changes an existing attribute
/// @param key The identifying key for the new attribute
/// @param value The value of the new attribute
void XmlNode::setAttribute(const std::string key, std::string value)
{
	attributes[key] = value;
}

/// Gets the list of existing attribute keys
/// @return A vector containing all the attribute key strings
const std::vector<std::string> XmlNode::keys() const
{
	std::vector<std::string> keys;
	for (auto pair : attributes) {
		keys.push_back(pair.first);
	}
	return keys;
}

/// Gets the current value of the given attribute
/// @param key The identifying key of the attribute to retrieve
/// @return The value of the requested attribute or an empty string if
///			the key does not exist
std::string XmlNode::getAttribute(std::string key) const
{
	auto iter = attributes.find(key);
	if (iter == attributes.end()) {
		return "";
	} else {
		return iter->second;
	}
}

/// Sets or changes the node's element type
/// @param newElement The new element type string
void XmlNode::setElement(std::string newElement)
{
	this->element = newElement;
}

/// Gets the node's element type
/// @return The current element type string
std::string XmlNode::getElement() const
{
	return element;
}

void XmlNode::setInnerValue(std::string value)
{
	innerValue = value;
}

std::string XmlNode::getInnerValue()
{
	return innerValue;
}

/// Gets the number of children this node contains
/// @return The number of child nodes
size_t XmlNode::getChildCount() const
{
	return children.size();
}

/// Gets a reference to the child node at the given index
/// @param index The index of the child node to get
/// @return A reference to the requested XmlNode
std::shared_ptr<XmlNode> XmlNode::operator[](int index)
{
	return children.at(index);
}

/// Gets the node's contents in XML text format
/// @param recurse Boolean indicating whether to recursively get the XML
///				for the node's children. Defaults to true.
/// @return An XML string representing the node and possibly its children
std::string XmlNode::toXmlString(bool recurse) const
{
	std::stringstream stream;
	toXmlString(stream, recurse, 0);
	return stream.str();
}

/// Gets the node's contents in XML text format
/// @param stream Reference to a stringstream object to write the XML to
/// @param recurse Boolean indicating whether to recursively get the XML
///				for the node's children. Defaults to true.
/// @param depth The nesting depth for XML indenting
void XmlNode::toXmlString(std::stringstream & stream, bool recurse, int depth) const
{
	for (int i = 0; i < depth; ++i) {
		stream << "  ";
	}
	stream << "<" << element;
	for (auto pair : attributes) {
		stream << " " << pair.first << "=\"" << pair.second << "\"";
	}
	stream << ">";
	if (children.size() == 0) {
		stream << innerValue;
	} else if (recurse) {
		stream << '\n';
		for (size_t i = 0; i < children.size(); i++) {
			children[i]->toXmlString(stream, recurse, depth + 1);
		}
		for (int i = 0; i < depth; ++i) {
			stream << "  ";
		}
	}
	stream << "</" << element << ">\n";
}
