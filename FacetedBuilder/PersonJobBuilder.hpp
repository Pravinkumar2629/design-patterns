/*
 * PersonJobBuilder.h
 *
 *  Created on: Dec 25, 2020
 *      Author: pravinkumar
 */

#ifndef PERSONJOBBUILDER_H_
#define PERSONJOBBUILDER_H_
#include "Builder.h"
#include "PersonBuilderBase.h"

template<typename T>
class PersonJobBuilder: virtual public PersonBuilderBase {
public:
	PersonJobBuilder<T>&  as(const std::string &designation);
	T& then(){
		return reinterpret_cast<T&>(*this);
	}
public:
	PersonJobBuilder(Person &p) : PersonBuilderBase(p){}
	virtual ~PersonJobBuilder(){}
};

#endif /* PERSONJOBBUILDER_H_ */
