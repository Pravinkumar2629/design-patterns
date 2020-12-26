/*
 * PersonAddressBuilder.cpp
 *
 *  Created on: Dec 26, 2020
 *      Author: pravinkumar
 */

#include "PersonAddressBuilder.h"
#include "Person.h"

PersonAddressBuilder::PersonAddressBuilder(Person &person_) :
		PersonBase(person_) {
}

PersonAddressBuilder& PersonAddressBuilder::in(const std::string &city) {
	_person.city = city;
	return *this;
}
