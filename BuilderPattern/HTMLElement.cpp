/*
 * HTMLElement.cpp
 *
 *  Created on: Dec 22, 2020
 *      Author: pravinkumar
 */

#include "HTMLElement.h"

#include <iostream>
#include <iomanip>

using namespace std;



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
	cout << "<" << name << ">" << endl;
	for (auto &element : elements) {
		oss << std::setw(indent_size * indent) << " " << "<" << element.name
				<< ">" << element.text << "</" << element.name << ">" << endl;
	}
	oss <<"</" <<name << ">"<< endl;
	return oss.str();
}


HTMLBuilder* HTMLElement::create(string root_name) {
	return new HTMLBuilder(root_name);
}



//string open_tag(string &name) {
//	return string("<" + name + "> ");
//}
//string close_tag(string &name) {
//	return string(" </" + name + ">");
//}
