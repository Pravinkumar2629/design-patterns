/*
 * PersonEducationBuilder.h
 *
 *  Created on: Dec 25, 2020
 *      Author: pravinkumar
 */

#ifndef PERSONEDUCATIONBUILDER_H_
#define PERSONEDUCATIONBUILDER_H_

#include "Builder.h"
#include "PersonBuilderBase.h"
template<typename T>
class PersonEducationBuilder :virtual public PersonBuilderBase {
public:
	PersonEducationBuilder<T>& in(const std::string &graduation);
	T& then(){
		return reinterpret_cast<T&>(*this);
	}
public:
	PersonEducationBuilder(Person &p) : PersonBuilderBase(p){}
	virtual ~PersonEducationBuilder(){}
};

#endif /* PERSONEDUCATIONBUILDER_H_ */
