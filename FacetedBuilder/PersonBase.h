/*
 * PersonBase.h
 *
 *  Created on: Dec 26, 2020
 *      Author: pravinkumar
 */

#ifndef PERSONBASE_H_
#define PERSONBASE_H_

#include <string>

class Person;
class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBase {
protected:
	Person &_person;
	PersonBase(Person &person);
public:
	PersonBase& named(const std::string&);
	Person& build();
	PersonAddressBuilder lives();
	PersonJobBuilder works();
};

#endif /* PERSONBASE_H_ */
