/*
 * PersonAddressBuilder.h
 *
 *  Created on: Dec 26, 2020
 *      Author: pravinkumar
 */

#ifndef PERSONADDRESSBUILDER_H_
#define PERSONADDRESSBUILDER_H_

#include <string>

#include "PersonBase.h"

class Person;
class PersonAddressBuilder : public PersonBase {
public:
	PersonAddressBuilder(Person &person_);
	PersonAddressBuilder& in(const std::string &city);
};

#endif /* PERSONADDRESSBUILDER_H_ */
