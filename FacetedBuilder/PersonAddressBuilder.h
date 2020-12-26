/*
 * PersonAddressBuilder.h
 *
 *  Created on: Dec 25, 2020
 *      Author: pravinkumar
 */

#ifndef PERSONADDRESSBUILDER_H_
#define PERSONADDRESSBUILDER_H_

#include "PersonBuilderBase.h"

template<typename T>
class PersonAddressBuilder : virtual public PersonBuilderBase {
public:
	PersonAddressBuilder<T>& in(const std::string &area);
	T& then(){
		return reinterpret_cast<T&>(*this);
	}
public:
	PersonAddressBuilder(Person &p) : PersonBuilderBase(p){}
	virtual ~PersonAddressBuilder(){}
};

#endif /* PERSONADDRESSBUILDER_H_ */
