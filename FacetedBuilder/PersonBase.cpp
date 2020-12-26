/*
 * PersonBase.cpp
 *
 *  Created on: Dec 26, 2020
 *      Author: pravinkumar
 */

#include "Person.h"
#include "PersonBase.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

PersonBase::PersonBase(Person &person) :
		_person(person) {
}

PersonAddressBuilder PersonBase::lives() {
	return PersonAddressBuilder(_person);
}

Person& PersonBase::build(){
	return _person;
}

PersonBase& PersonBase::named(const std::string &name){
	_person.name = name;
	return *this;
}

PersonJobBuilder PersonBase::works() {
	return PersonJobBuilder(_person);
}
