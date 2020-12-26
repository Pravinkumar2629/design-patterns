/*
 * PersonJobBuilder.h
 *
 *  Created on: Dec 26, 2020
 *      Author: pravinkumar
 */

#ifndef PERSONJOBBUILDER_H_
#define PERSONJOBBUILDER_H_

#include "PersonBase.h"
#include <string>

class Person;

class PersonJobBuilder : public PersonBase {
public:
	PersonJobBuilder(Person &person_);
	PersonJobBuilder& as(const std::string &designation);
};

#endif /* PERSONJOBBUILDER_H_ */
