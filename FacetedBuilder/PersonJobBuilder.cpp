/*
 * PersonJobBuilder.cpp
 *
 *  Created on: Dec 26, 2020
 *      Author: pravinkumar
 */

#include "PersonJobBuilder.h"
#include "PersonBase.h"
#include "Person.h"

PersonJobBuilder::PersonJobBuilder(Person &person_) : PersonBase(person_){}


PersonJobBuilder& PersonJobBuilder::as(const std::string &desingation){
	_person.designation = desingation;
	return *this;
}


