/*
 * HTMLElementV1.cpp
 *
 *  Created on: Dec 22, 2020
 *      Author: pravinkumar
 */

#include "HTMLElementV1.h"
#include <iostream>
using namespace std;
string open_tag(string &name) {
	return string("<" + name + "> ");
}
string close_tag(string &name) {
	return string(" </" + name + ">");
}

HTMLElement::HTMLElement() {
}

HTMLElement::HTMLElement(const string &name_) :
		name(name_), text("") {
}
HTMLElement::HTMLElement(const string &name_, const string &text_) :
		name(name_), text(text_) {
}

HTMLElement::~HTMLElement() {

}

string HTMLElement::str(int indent_size) const {
	ostringstream oss;
	cout << open_tag(name) << endl;
	for (auto &element : elements) {
		oss << std::setw(indent_size * indent) << " " << open_tag(element.name)
				<< element.text << close_tag(element.name) << endl;
	}
	oss << close_tag(name) << endl;
	return oss.str();
}
HTMLBuilder HTMLElement::create(string root_name) {
	return {root_name};
}

HTMLElementV1::~HTMLElementV1() {
	// TODO Auto-generated destructor stub
}

