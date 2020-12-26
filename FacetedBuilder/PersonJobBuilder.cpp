/*
 * PersonJobBuilder.cpp
 *
 *  Created on: Dec 25, 2020
 *      Author: pravinkumar
 */

#include "PersonJobBuilder.h"


template<typename T>
PersonJobBuilder<T>& PersonJobBuilder<T>::as(const std::string &designation) {
	P().setWorksAs(designation);
	return *this;
}
