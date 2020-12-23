/*
 * HTMLElementV1.h
 *
 *  Created on: Dec 22, 2020
 *      Author: pravinkumar
 */

#ifndef HTMLELEMENTV1_H_
#define HTMLELEMENTV1_H_

#include "HTMLBuilderImpl.h"

#include <string>
#include <vector>

using namespace std;
class HTMLBuilderImpl;

class HTMLElementV1 {
private:
	string name;
	string text;
	const size_t indent = 5;
	vector<HTMLElementV1> elements;

	HTMLElementV1() ;
	HTMLElementV1(const string &name_) ;
	HTMLElementV1(const string &name_, const string &text_);

	friend class HTMLBuilderImpl;
public:
	~HTMLElementV1();
	string str(int) const ;
	static HTMLBuilderImpl* create(string);
};

#endif /* HTMLELEMENTV1_H_ */
