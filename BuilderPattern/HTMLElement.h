/*
 * HTMLElement.h
 *
 *  Created on: Dec 22, 2020
 *      Author: pravinkumar
 */

#ifndef HTMLELEMENT_H_
#define HTMLELEMENT_H_

#include <string>
#include <vector>
#include "HTMLBuilder.h"

using namespace std;
class HTMLBuilder;

class HTMLElement {
private:
	string name;
	string text;
	const size_t indent = 5;
	vector<HTMLElement> elements;

	HTMLElement() ;
	HTMLElement(const string &name_) ;
	HTMLElement(const string &name_, const string &text_);

	friend class HTMLBuilder;
public:
	~HTMLElement();
	string str(int) const ;
	static HTMLBuilder* create(string);
};

#endif /* HTMLELEMENT_H_ */
