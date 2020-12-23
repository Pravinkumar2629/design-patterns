/*
 * HTMLBuilder.h
 *
 *  Created on: Dec 22, 2020
 *      Author: pravinkumar
 */


#ifndef Element_
#define Element_

#include <string>
#include "HTMLElement.h"

using namespace std;
class HTMLElement;

class HTMLBuilder {
	HTMLElement *root;
public:
	HTMLBuilder();

	HTMLBuilder(string root_);
	HTMLBuilder* add_child(string tag, string text);

	operator HTMLElement();

	HTMLElement& build() const;
	void print_to_console() const;

	~HTMLBuilder();
};

#endif
