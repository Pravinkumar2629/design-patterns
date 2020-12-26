/*
 * main.cpp
 *
 *  Created on: Dec 26, 2020
 *      Author: pravinkumar
 */

#include "Factory.h"


int main(){
	use_abstract_factory();
	return 0;
}


/*
#include <map>
#include <string>
#include <memory>

void v_main(){
	using namespace std;
	map<string, unique_ptr<int>> m;
	m["hello"] = make_unique<int>(0);
	m["hello1"] = make_unique<int>(1);
	m["hello2"] = make_unique<int>(2);
}
*/
