/*
 * HTMLBuilderImpl.cpp
 *
 *  Created on: Dec 22, 2020
 *      Author: pravinkumar
 */

#include "HTMLBuilderImpl.h"
#include <iostream>

HTMLBuilderImpl::~HTMLBuilderImpl() {
	delete root;
}

HTMLBuilderImpl::HTMLBuilderImpl() : HTMLBuilderImpl("")  {
}

HTMLBuilderImpl::HTMLBuilderImpl(string root_) {
	root = new HTMLElementV1(root_);
}
HTMLBuilderImpl* HTMLBuilderImpl::add_child(string tag, string text) {
	HTMLElementV1 element(tag, text);
	root->elements.emplace_back(element);
	return this;
}

HTMLBuilderImpl::operator HTMLElementV1() {
	return *root;
}

HTMLElementV1& HTMLBuilderImpl::build() const {
	return *root;
}
void HTMLBuilderImpl::print_to_console() const {
	//std::cout << root.str(1);
}
