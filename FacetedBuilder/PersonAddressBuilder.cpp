/*
 * PersonAddressBuilder.cpp
 *
 *  Created on: Dec 25, 2020
 *      Author: pravinkumar
 */


//
#include "PersonAddressBuilder.h"


template<typename T>
PersonAddressBuilder<T>& PersonAddressBuilder<T>::in(const std::string &area) {
	P().setAddress(area);
	return *this;
}
