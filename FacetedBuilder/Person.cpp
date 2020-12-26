/*
 * Person.cpp
 *
 *  Created on: Dec 26, 2020
 *      Author: pravinkumar
 */

#include "Person.h"
#include "PersonBuilder.h"

PersonBuilder Person::create() {
	return PersonBuilder();
}
std::string Person::str() {
	return name +", works as : " + designation + " and lives in "+ city ;
}
