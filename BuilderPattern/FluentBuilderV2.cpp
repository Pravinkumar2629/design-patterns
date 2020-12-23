/*
 * FluentBuilderV2.cpp
 *
 *  Created on: Dec 22, 2020
 *      Author: pravinkumar
 */

#include "FluentBuilderV2.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

class Tag {
public:
	std::string name;
	std::string text;
	std::vector<Tag> children;
	std::vector<std::pair<std::string, std::string>> attributes;

	Tag(const std::string &name_, const std::string &text_) :
			name(name_), text(text_) {

	}

	std::string str(int indent = 1) const {
		std::ostringstream oss { };
		oss << std::setw(indent) << " " << "<" << name;
		for (const auto &attrib : attributes) {
			oss << " " << attrib.first << "=" << attrib.second;
		}
		if (text.length() == 0 && children.size() == 0) {
			oss << " />";
		} else {
			oss << ">\n";
			if (text.length() > 0) {
				oss << std::setw(indent+1) << " " << text << "\n";
			}
			for (const auto &child : children) {
				oss << std::setw(indent+1) << " " << child.str(indent + 1);
			}
			oss << "\n" << std::setw(indent) << " " << "</" << name << ">";
		}
		return oss.str();
	}
};

class P: public Tag {
public:
	P(const std::string &_text) :
			Tag { "P", _text } {

	}
	P(const std::string &_text, const Tag &child) :
			Tag { "P", _text } {
		children.emplace_back(child);
	}
};

class IMG: public Tag {
public:
	IMG(const std::string &url) :
			Tag { "IMG", "" } {
		attributes.emplace_back(std::make_pair("src", url));
	}
	IMG(const std::string &url, const Tag &child) :
			Tag { "IMG", "" } {
		children.emplace_back(child);
		attributes.emplace_back(std::make_pair("src", url));
	}
};

void FluentBuilderV2::Run() {
	P tags {
		"Some text here",
		IMG {
			"google.com/image1",
			IMG {
				"Google.com/imag2"
				}
		}
	};
	std::cout << tags.str() << std::endl;
}

FluentBuilderV2::~FluentBuilderV2() {
	// TODO Auto-generated destructor stub
}

