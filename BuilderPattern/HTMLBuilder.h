/*
 * HTMLBuilderImpl.h
 *
 *  Created on: Dec 22, 2020
 *      Author: pravinkumar
 */


#ifndef Element_
#define Element_

#include "HTMLElementV1.h"
#include <string>

using namespace std;
class HTMLElementV1;

class HTMLBuilderImpl {
	HTMLElementV1 *root;
public:
	HTMLBuilderImpl();

	HTMLBuilderImpl(string root_);
	HTMLBuilderImpl* add_child(string tag, string text);

	operator HTMLElementV1();

	HTMLElementV1& build() const;
	void print_to_console() const;

	~HTMLBuilderImpl();
};

#endif
