#include <UnitTest++.h>
#include "XmlNode.h"
#include "XmlDocument.h"
#include "XmlWriter.h"
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
		XmlNode root("root");
		root.addChild("firstChild");
		XmlNode secondChild("secondChild");
		secondChild.setAttribute("class", "btn btn-primary");
		root.addChild(secondChild)->addChild("thirdchild", "stuff");
		std::string xml = root.toXmlString();
		CHECK(xml == "<ROOT>\n  <FIRSTCHILD></FIRSTCHILD>\n  <SECONDCHILD class=\"btn btn-primary\">\n    <THIRDCHILD>stuff</THIRDCHILD>\n  </SECONDCHILD>\n</ROOT>\n");
	}

	TEST(XmlFindByElement) {
		XmlDocument doc("root");
		auto root = doc.getRoot();
		root->addChild("firstChild");
		XmlNode secondChild("secondChild");
		secondChild.setAttribute("class", "btn btn-primary");
		auto second = root->addChild(secondChild); 
		second->addChild("thirdchild", "stuff");
		second->addChild("thirdchild", "different stuff");
		auto searchResults = doc.getNodesByElement("thirdchild");
		CHECK_EQUAL(2, searchResults.size());
	}

	TEST(XmlDocString) {
		XmlDocument doc("root");
		auto root = doc.getRoot();
		root->addChild("firstChild");
		std::string xml = doc.toXmlString();
		CHECK(xml == "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<ROOT>\n  <FIRSTCHILD></FIRSTCHILD>\n</ROOT>\n");
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
}