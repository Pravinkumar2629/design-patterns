/*
 * FluentBuilder.cpp
 *
 *  Created on: Dec 21, 2020
 *      Author: pravinkumar
 */

#include "FluentBuilder.h"

FluentBuilder::~FluentBuilder() {

}

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;
string open_tag(string name) {
	return "<" + name + "> ";
}
string close_tag(string name) {
	return " </" + name + ">";
}

class HTMLBuilder;

class HTMLElement {
	friend class HTMLBuilder;

private:
	string name;
	string text;
	const size_t indent = 5;
	vector<HTMLElement> elements;

	HTMLElement(const string &name_) :
			name(name_), text("") {
	}
	HTMLElement(const string &name_, const string &text_) :
			name(name_), text(text_) {
	}

public:
	~HTMLElement() {

	}
	string str(int indent_size = 1) const {
		ostringstream oss;
		cout << open_tag(name) << endl;
		for (auto &element : elements) {
			oss << std::setw(indent_size * indent) << " "
					<< open_tag(element.name) << element.text
					<< close_tag(element.name) << endl;
		}
		oss << close_tag(name) << endl;
		return oss.str();
	}
	static HTMLBuilder create(const string &root_name) {
		HTMLBuilder builder(root_name);
		return builder;
	}
};

class HTMLBuilder {
	HTMLElement root;
public:
	HTMLBuilder(const string &root_) :
			root(root_) {

	}
	HTMLBuilder& add_child(string tag, string text) {
		HTMLElement element(tag, text);
		root.elements.emplace_back(element);
		return *this;
	}
	HTMLElement& build() const {
		return root;
	}
	void print_to_console() const {
		std::cout << root.str(1);
	}

};

void FluentBuilder::Run() {
	auto element = HTMLElement::create("paragraph")
			.add_child("text", "text One")
			.add_child("text", "text two")
			.add_child("text", "text three")
			.add_child("text", "text four")
			.build();
	std::cout << element.str();
}
