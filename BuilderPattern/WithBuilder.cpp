/*
 * BuilderV1.cpp
 *
 *  Created on: Dec 18, 2020
 *      Author: pravinkumar
 */

#include "WithBuilder.h"

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


class HTMLElementWithBuilder {
	string name;
	string text;
	const size_t indent = 5;

public:
	vector<HTMLElementWithBuilder> elements;
	HTMLElementWithBuilder(const string &name_) :
			name(name_), text("") {
	}

	HTMLElementWithBuilder(const string &name_, const string &text_) :
			name(name_), text(text_) {
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
	void add_child(string tag, string text) {
		HTMLElementWithBuilder element(tag, text);
		elements.emplace_back(element);
	}
	void Print() {
		std::cout << str(1);
	}
	~HTMLElementWithBuilder() {

	}

};


void Run() {
	HTMLElementWithBuilder builder { "paragraph" };
	builder.add_child("text", "text One");
	builder.add_child("text", "text two");
	builder.add_child("text", "text three");
	builder.add_child("text", "text four");

	builder.Print();

}
