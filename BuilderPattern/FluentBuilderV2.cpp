/*
 * FluentBuilderV2.cpp
 *
 *  Created on: Dec 22, 2020
 *      Author: pravinkumar
 */

#include "FluentBuilderV2.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Tag {
public:
	std::string name;
	std::string text;
	std::vector<Tag> children;
	std::vector<std::pair<std::string, std::string>> attributes;

	Tag(const std::string &name_, const std::string &text_) : name(name_), text(text_) {

	}

	std::string str() const {
		std::ostringstream oss;

		oss << "<" << name;
		for (const auto &attrib : attributes) {
			oss << " " << attrib.first << "=" << attrib.second;
		}
		if (text.length() == 0 && children.size() == 0) {
			oss << "/>";
		} else {
			oss << ">";
			for (const auto &child : children) {
				oss << child.str();
			}
			oss << "</" << name << ">";
		}
		return oss.str();
	}
};

class P: public Tag {
public:
	P(const std::string &text) :
			Tag { "P", text } {

	}
	P(const std::string &text, const Tag &child) :
			Tag { "P", text } {
		children.emplace_back(child);
	}
};

class IMG: public Tag {
public:
	IMG(const std::string &url) :
			Tag { "IMG", text } {

	}
	IMG(const std::string &url, const Tag &child) :
			Tag { "IMG", text } {
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

