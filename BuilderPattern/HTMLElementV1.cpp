/*
 * HTMLElementV1.cpp
 *
 *  Created on: Dec 22, 2020
 *      Author: pravinkumar
 */

#include "HTMLElementV1.h"

#include <iostream>
#include <iomanip>

using namespace std;



HTMLElementV1::HTMLElementV1() {
}

HTMLElementV1::HTMLElementV1(const string &name_) :
		name(name_), text("") {
}
HTMLElementV1::HTMLElementV1(const string &name_, const string &text_) :
		name(name_), text(text_) {
}

HTMLElementV1::~HTMLElementV1() {

}

string HTMLElementV1::str(int indent_size) const {
	ostringstream oss;
	cout << "<" << name << ">" << endl;
	for (auto &element : elements) {
		oss << std::setw(indent_size * indent) << " " << "<" << element.name
				<< ">" << element.text << "</" << element.name << ">" << endl;
	}
	oss <<"</" <<name << ">"<< endl;
	return oss.str();
}


HTMLBuilderImpl* HTMLElementV1::create(string root_name) {
	return new HTMLBuilderImpl(root_name);
}



//string open_tag(string &name) {
//	return string("<" + name + "> ");
//}
//string close_tag(string &name) {
//	return string(" </" + name + ">");
//}
