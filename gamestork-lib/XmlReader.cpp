//-----------------------------------------------------------------------------
/**
File: XmlReader.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Header file for an XML parsing reader
*/
//-----------------------------------------------------------------------------

#include "XmlReader.h"


XmlReader::XmlReader()
	: document(), nodeStack(), stream(), xmlReady(false)
{
}


XmlReader::XmlReader(const std::string filename)
	:document(), nodeStack(), stream(filename), xmlReady(false)
{
	if (!stream.is_open()) {
		throw std::ios_base::failure(filename + " could not be opened");
	}
	read();
}

XmlReader::~XmlReader()
{
	if (stream.is_open()) {
		stream.close();
	}
}

void XmlReader::open(const std::string filename)
{
	document = XmlDocument();
	xmlReady = false;
	nodeStack = std::stack<XmlNode>();
	if (stream.is_open()) {
		stream.close();
	}
	stream.open(filename);
	if (!stream.is_open()) {
		throw std::ios_base::failure(filename + " could not be opened");
	}
	read();
}

bool XmlReader::isXmlReady() const
{
	return xmlReady;
}

XmlDocument XmlReader::getDocument() const
{
	return document;
}

void XmlReader::read()
{
	XML_READER_STATE state = XMLSTATE_PROLOG_OPEN;
	while (state != XMLSTATE_FINISHED && state != XMLSTATE_INVALID) {
		switch (state) {
		case XMLSTATE_PROLOG_OPEN:
			state = prologOpening();
			break;
		case XMLSTATE_PROLOG_KEYVAL:
			state = prologKeyValPair();
			break;
		case XMLSTATE_ELEMENT_OPEN:
			state = elementOpening();
			break;
		case XMLSTATE_ELEMENT_KEYVAL:
			state = elementKeyValPair();
			break;
		case XMLSTATE_ELEMENT_INNERVALUE:
			state = elementInnerValue();
			break;
		case XMLSTATE_ELEMENT_BODY:
			state = elementBody();
			break;
		case XMLSTATE_ELEMENT_CLOSE:
			state = elementClosing();
			break;
		case XMLSTATE_ELEMENT_SELFCLOSE:
			state = elementClosing(true);
			break;
		default:
			throw std::runtime_error("Unknown state reached");
		}
	}
	if (state == XMLSTATE_FINISHED) {
		document.setRoot(nodeStack.top());
		nodeStack.pop();
		xmlReady = true;
	} else if (state == XMLSTATE_INVALID) {
		document = XmlDocument();
		nodeStack = std::stack<XmlNode>();
	}
	if (stream.is_open()) {
		stream.close();
	}
}

XML_READER_STATE XmlReader::prologOpening()
{
	if (!stream.is_open()) {
		return XMLSTATE_INVALID;
	}
	// verify that this is a valid prolog opener
	// if it isn't, this file can't be read
	std::string buffer(6, '\0');
	stream.read(&buffer[0], 6);
	if (buffer != "<?xml ") {
		return XMLSTATE_INVALID;
	}
	// identify the next bit of data in the stream and change state
	char next;
	do {
		if (!stream.good()) {
			return XMLSTATE_INVALID;
		}
		stream.get(next);
		if (isalpha(next) || next == '_' || next == ':') {
			// alpha character indicates the beginning of a key/value pair
			// That character will be needed, so stick it back in the stream
			stream.unget(); 
			return XMLSTATE_PROLOG_KEYVAL;
		} else if (next == '?') {
			// this looks like the prolog close tag, so check the next char
			// to make sure. If it isn't the expected '>', then this isn't
			// valid XML
			stream.get(next);
			if (next != '>') return XMLSTATE_INVALID;
			do {
				stream.get(next);
			} while (isspace(next));
			if (next == '<') {
				return XMLSTATE_ELEMENT_OPEN;
			} else {
				return XMLSTATE_INVALID;
			}
		}
	} while (isspace(next)); // ignore whitespace characters
	// If this point is reached, the file is not valid XML
	return XMLSTATE_INVALID;
}

XML_READER_STATE XmlReader::prologKeyValPair()
{
	if (!stream.is_open()) return XMLSTATE_INVALID;

	char next = 0;
	stream.get(next); // the next char in the stream
	if (!isalpha(next) && next != '_' && next != ':') {
		// attributes must start w/ a letter or underscore
		// additional chars are allowed in the name, provided they aren't
		// at the beginning. The while test is broader because of this,
		// so this test covers the special start case
		return XMLSTATE_INVALID;
	}
	
	std::string attribName; // attribute name being read
	while (isalnum(next) || next == '_' || next == '-' || next == '.' 
		|| next == ':') {
		attribName += next;
		stream.get(next);
		if (!stream.good()) return XMLSTATE_INVALID;
	}
	
	// the only valid character after an attribute name is '='
	if (next != '=') return XMLSTATE_INVALID;
	
	// after the '=', only a single or double quote is allowed. 
	// save the appropriate quote type for finding the end of the value string
	stream.get(next);
	if (next != '\'' && next != '"') return XMLSTATE_INVALID;
	char delimiter = next;
	std::string value; //the value for our attribute
	stream.get(next);
	// in a value, anything except the delimiter is fair game
	while (next != delimiter) {
		if (!stream.good()) return XMLSTATE_INVALID;
		value += next;
		stream.get(next);
	}
	
	// key/value pair read successfully. Only version & encoding are currently
	// supported in prolog. Anything else is ignored.
	std::transform(attribName.begin(), attribName.end(),
		attribName.begin(), tolower);
	if (attribName == "version") {
		//TODO enable setting document version
	} else if (attribName == "encoding") {
		//TODO enable setting document encoding
	}

	// find the next state operation
	do {
		stream.get(next);
	} while (isspace(next));
	if (isalpha(next) || next == '_' || next == ':') {
		stream.unget();
		return XMLSTATE_PROLOG_KEYVAL;
	} else if (next == '?') {
		// this looks like the prolog close tag, so check the next char
		// to make sure. If it isn't the expected '>', then this isn't
		// valid XML
		stream.get(next);
		if (next != '>') return XMLSTATE_INVALID;
		do {
			stream.get(next);
		} while (isspace(next));
		if (next == '<') {
			return XMLSTATE_ELEMENT_OPEN;
		} else {
			return XMLSTATE_INVALID;
		}
	} else {
		return XMLSTATE_INVALID;
	}
}

XML_READER_STATE XmlReader::elementOpening()
{
	if (!stream.is_open()) return XMLSTATE_INVALID;
	char next = 0;
	stream.get(next);
	if (!isalpha(next) && next != '_' && next != ':') return XMLSTATE_INVALID;
	std::string elementName;
	
	// read the name in until an invalid name character is found
	while (isalnum(next) || next == '_' || next == '-' || next == '.' 
		|| next == ':') {
		elementName += next;
		stream.get(next);
		if (!stream.good()) return XMLSTATE_INVALID;
	}
	stream.unget();
	
	nodeStack.push(XmlNode(elementName));
	return XMLSTATE_ELEMENT_BODY;
}

XML_READER_STATE XmlReader::elementBody()
{
	if (!stream.is_open()) return XMLSTATE_INVALID;
	char next = 0;
	stream.get(next);
	// skip past whitespace
	while (isspace(next)) {
		stream.get(next);
		if (!stream.good()) return XMLSTATE_INVALID;
	}

	// determine next state
	if (next == '/') {
		return XMLSTATE_ELEMENT_SELFCLOSE;
	} else if (next == '>') {
		// child element or inner value coming next
		// scan past whitespace
		do {
			stream.get(next);
			if (!stream.good()) return XMLSTATE_INVALID;
		} while (isspace(next));

		// If we get a <, this has children. Otherwise, it's an innervalue
		if (next == '<') {
			stream.get(next);
			if (next == '/') {
				return XMLSTATE_ELEMENT_CLOSE;
			} else {
				stream.unget();
				return XMLSTATE_ELEMENT_OPEN;
			}
		} else {
			stream.unget();
			return XMLSTATE_ELEMENT_INNERVALUE;
		}
	} else if (isalpha(next) || next == '_' || next == ':') {
		// looks like an attribute
		stream.unget();
		return XMLSTATE_ELEMENT_KEYVAL;
	} else {
		// nothing else is valid
		return XMLSTATE_INVALID;
	}
}

XML_READER_STATE XmlReader::elementKeyValPair()
{
	if (!stream.is_open()) return XMLSTATE_INVALID;

	char next = 0;
	stream.get(next); // the next char in the stream
	if (!isalpha(next) && next != '_' && next != ':') {
		// attributes must start w/ a letter or underscore
		// additional chars are allowed in the name, provided they aren't
		// at the beginning. The while test is broader because of this,
		// so this test covers the special start case
		return XMLSTATE_INVALID;
	}

	std::string attribName; // attribute name being read
	while (isalnum(next) || next == '_' || next == '-' || next == '.'
		|| next == ':') {
		attribName += next;
		stream.get(next);
		if (!stream.good()) return XMLSTATE_INVALID;
	}

	// the only valid character after an attribute name is '='
	if (next != '=') return XMLSTATE_INVALID;

	// after the '=', only a single or double quote is allowed. 
	// save the appropriate quote type for finding the end of the value string
	stream.get(next);
	if (next != '\'' && next != '"') return XMLSTATE_INVALID;
	char delimiter = next;
	std::string value; //the value for our attribute
	stream.get(next);
	// in a value, anything except the delimiter is fair game
	while (next != delimiter) {
		value += next;
		stream.get(next);
		if (!stream.good()) return XMLSTATE_INVALID;
	}

	// add the completed attribute key/value pair to the node
	if (nodeStack.size() == 0) return XMLSTATE_INVALID;
	nodeStack.top().setAttribute(attribName, value);
	return XMLSTATE_ELEMENT_BODY;
}

XML_READER_STATE XmlReader::elementInnerValue()
{
	if (!stream.is_open()) return XMLSTATE_INVALID;

	std::string innerValue;
	char next = 0;
	stream.get(next);
	while (next != '<') {
		innerValue += next;
		stream.get(next);
		if (!stream.good()) return XMLSTATE_INVALID;
	}
	
	// add the inner value to the node
	if (nodeStack.size() == 0) return XMLSTATE_INVALID;
	nodeStack.top().setInnerValue(innerValue);

	// verify that the element is being properly closed and return state
	stream.get(next);
	if (next != '/') return XMLSTATE_INVALID;
	return XMLSTATE_ELEMENT_CLOSE;
}

XML_READER_STATE XmlReader::elementClosing(bool selfClose)
{
	if (!stream.is_open() || !stream.good()) return XMLSTATE_INVALID;

	char next = 0;
	stream.get(next);
	if (!selfClose) {
		if (!isalpha(next) && next != '_' && next != ':') return XMLSTATE_INVALID;
		std::string elementName;
		while (isalnum(next) || next == '_' || next == '-' || next == '.'
			|| next == ':') {
			elementName += next;
			stream.get(next);
			if (!stream.good()) return XMLSTATE_INVALID;
		}
		if (nodeStack.size() == 0 ||
			elementName != nodeStack.top().getElement()) {
			// no node to close, or the elements don't match
			return XMLSTATE_INVALID;
		}
	}
	if (next != '>') return XMLSTATE_INVALID;
	
	// If this node isn't the root, take it off the stack and put it into the
	// tree of nodes
	if (nodeStack.size() > 1) {
		XmlNode node = nodeStack.top();
		nodeStack.pop();
		nodeStack.top().addChild(node);
	}

	// determine next state
	// scan past whitespace
	do {
		stream.get(next);
		if (!stream.good()) {
			if (nodeStack.size() == 1) {
				return XMLSTATE_FINISHED;
			}
			return XMLSTATE_INVALID;
		}
	} while (isspace(next));
	if (stream.eof()) {
		if (nodeStack.size() == 1) {
			return XMLSTATE_FINISHED;
		} else {
			return XMLSTATE_INVALID;
		}
	} else if (next == '<') {
		stream.get(next);
		if (next == '/') {
			return XMLSTATE_ELEMENT_CLOSE;
		} else if (isalpha(next) || next == '_' || next == ':') {
			stream.unget();
			return XMLSTATE_ELEMENT_OPEN;
		} else {
			return XMLSTATE_INVALID;
		}
	} else {
		return XMLSTATE_INVALID;
	}
}
