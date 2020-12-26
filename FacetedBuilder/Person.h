/*
 * Person.h
 *
 *  Created on: Dec 26, 2020
 *      Author: pravinkumar
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class PersonBuilder;

class Person {
public:
	std::string name, designation, city;
	static PersonBuilder create();
	std::string str();
};

#endif /* PERSON_H_ */
