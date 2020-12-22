/*
 * HTMLBuilderImpl.cpp
 *
 *  Created on: Dec 22, 2020
 *      Author: pravinkumar
 */

#include "HTMLBuilderImpl.h"
#include "HTMLElementV1.h"
#include <iostream>

HTMLBuilder::HTMLBuilder() {
}

HTMLBuilder::HTMLBuilder(string root_) {
	root.name = root_;
}
HTMLBuilder& HTMLBuilder::add_child(string tag, string text) {
	HTMLElement element(tag, text);
	root.elements.emplace_back(element);
	return *this;
}

HTMLBuilder::operator HTMLElement() {
	return root;
}

HTMLElement HTMLBuilder::build() const {
	return root;
}
void HTMLBuilder::print_to_console() const {
	std::cout << root.str(1);
}
