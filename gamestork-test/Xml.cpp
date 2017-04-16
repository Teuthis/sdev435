//-----------------------------------------------------------------------------
/**
File: Xml.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Unit tests related to XML system
*/
//-----------------------------------------------------------------------------

#include <UnitTest++.h>
#include "XmlNode.h"
#include "XmlDocument.h"
#include "XmlWriter.h"
#include "XmlReader.h"
#include <fstream>
#include <cstdio>

SUITE(XmlTests) {

	TEST(AddChildren) {
		XmlNode root("root");
		root.addChild("firstChild");
		XmlNode secondChild("secondChild");
		root.addChild(secondChild);
		CHECK_EQUAL(2, root.getChildCount());
	}

	TEST(XmlString) {
		XmlNode root("ROOT");
		root.addChild("FIRSTCHILD");
		XmlNode secondChild("SECONDCHILD");
		secondChild.setAttribute("class", "btn btn-primary");
		root.addChild(secondChild)->addChild("THIRDCHILD", "stuff");
		std::string xml = root.toXmlString();
		CHECK(xml == "<ROOT>\n  <FIRSTCHILD></FIRSTCHILD>\n  <SECONDCHILD class=\"btn btn-primary\">\n    <THIRDCHILD>stuff</THIRDCHILD>\n  </SECONDCHILD>\n</ROOT>\n");
	}

	TEST(XmlFindByElementMatchCase) {
		XmlDocument doc("root");
		auto root = doc.getRoot();
		root->addChild("firstChild");
		XmlNode secondChild("secondChild");
		secondChild.setAttribute("class", "btn btn-primary");
		auto second = root->addChild(secondChild); 
		second->addChild("thirdchild", "stuff");
		second->addChild("thirdChild", "different stuff");
		second->addChild("thirdchild", "more stuff");
		auto searchResults = doc.getNodesByElement("thirdchild");
		CHECK_EQUAL(2, searchResults.size());
	}

	TEST(XmlFindByElementCaseInsensitive) {
		XmlDocument doc("root");
		auto root = doc.getRoot();
		root->addChild("firstChild");
		XmlNode secondChild("secondChild");
		secondChild.setAttribute("class", "btn btn-primary");
		auto second = root->addChild(secondChild);
		second->addChild("thirdchild", "stuff");
		second->addChild("thirdChild", "different stuff");
		second->addChild("thirdchild", "more stuff");
		auto searchResults = doc.getNodesByElement("thirdchild", true);
		CHECK_EQUAL(3, searchResults.size());
	}

	TEST(XmlDocString) {
		XmlDocument doc("root");
		auto root = doc.getRoot();
		root->addChild("firstChild");
		std::string xml = doc.toXmlString();
		CHECK(xml == "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<root>\n  <firstChild></firstChild>\n</root>\n");
	}

	TEST(XmlWriting) {
		XmlDocument doc("root");
		auto root = doc.getRoot();
		root->addChild("firstChild");
		XmlWriter writer(doc);
		std::string fn = "./gamestorkunittest.xml";
		bool writeSuccess = writer.write(fn);
		std::ifstream testreader;
		testreader.open(fn, std::ios::in);
		bool reopenSuccess = testreader.is_open();
		std::string xml;
		if (reopenSuccess) {
			std::string tmp;
			while (std::getline(testreader, tmp)) {
				xml += tmp;
				xml += '\n';
			}
			testreader.close();
			remove(fn.c_str());
		}
		CHECK(writeSuccess && reopenSuccess && xml == doc.toXmlString());
	}

	TEST(XmlReaderBadFileThrow) {
		XmlReader reader;
		CHECK_THROW(reader.open("notarealfile.xml"), std::ios_base::failure);
	}

	TEST(XmlReaderGoodFileSimpleRead) {
		XmlReader reader("C:\\xmlTestDocs\\validSimple.xml");
		CHECK(reader.isXmlReady());
	}

	TEST(XmlReaderGoodFileSimpleContent) {
		XmlReader reader("C:\\xmlTestDocs\\validSimple.xml");
		size_t numAbility = 0;
		if (reader.isXmlReady()) {
			numAbility = reader.getDocument().getNodesByElement("ability", true).size();
		}
		CHECK_EQUAL(6, numAbility);
	}

	TEST(XmlReaderGoodFileNewline) {
		XmlReader reader("C:\\xmlTestDocs\\validNewLineInAttribVal.xml");
		CHECK(reader.isXmlReady());
	}

	TEST(XmlReaderBadElementClose) {
		XmlReader reader("C:\\xmlTestDocs\\badElementClose.xml");
		CHECK(!reader.isXmlReady());
	}

	TEST(XmlReaderBadNoProlog) {
		XmlReader reader("C:\\xmlTestDocs\\badNoProlog.xml");
		CHECK(!reader.isXmlReady());
	}

	TEST(XmlReaderBadNesting) {
		XmlReader reader("C:\\xmlTestDocs\\badInnerValAndChild.xml");
		CHECK(!reader.isXmlReady());
	}

	TEST(XmlReadOwnWriting) {
		XmlDocument doc("root");
		auto root = doc.getRoot();
		root->addChild("firstChild");
		XmlWriter writer(doc);
		std::string fn = "./gamestorkunittest_writeread.xml";
		bool writeSuccess = writer.write(fn);
		XmlReader reader(fn);
		remove(fn.c_str());
		CHECK(reader.isXmlReady());
	}
}