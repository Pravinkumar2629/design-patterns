/*
 * PersonBuilder.h
 *
 *  Created on: Dec 26, 2020
 *      Author: pravinkumar
 */

#ifndef PERSONBUILDER_H_
#define PERSONBUILDER_H_
#include "Person.h"

#include "PersonBase.h"

class PersonBuilder : public PersonBase{
	Person p;
public:
	PersonBuilder();
};

#endif /* PERSONBUILDER_H_ */
