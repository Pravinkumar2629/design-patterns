/*
 * PersonBuilder.h
 *
 *  Created on: Dec 25, 2020
 *      Author: pravinkumar
 */

#ifndef PERSONBUILDER_H_
#define PERSONBUILDER_H_

#include "PersonBuilderBase.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"
#include "PersonEducationBuilder.h"

class PersonBuilder: protected PersonAddressBuilder<PersonBuilder>,
		protected PersonEducationBuilder<PersonBuilder>,
		protected PersonJobBuilder<PersonBuilder> {
	Person p;
public:
	auto lives() {
		return static_cast<PersonAddressBuilder&>(*this);
	}
	auto works() {
		return static_cast<PersonJobBuilder&>(*this);
	}
	auto graduated() {
		return static_cast<PersonEducationBuilder&>(*this);
	}
	auto build() const{
		return p;
	}
	auto to_string() const{
		return p.str();
	}
public:
	PersonBuilder() :
			PersonBuilderBase(p), PersonAddressBuilder(p), PersonEducationBuilder(
					p), PersonJobBuilder(p) {
	}
	virtual ~PersonBuilder() {
	}
};

#endif /* PERSONBUILDER_H_ */
