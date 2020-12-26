/*
 * PersonBuilder.h
 *
 *  Created on: Dec 25, 2020
 *      Author: pravinkumar
 */

#ifndef PERSONBUILDERBASE_H_
#define PERSONBUILDERBASE_H_

#include "Person.h"


class PersonBuilderBase {
	Person &_p;

protected:
	PersonBuilderBase(Person &p) :
			_p(p) {
	}
	virtual ~PersonBuilderBase(){}
	Person& P() {
		return _p;
	}
};

#endif /* PERSONBUILDERBASE_H_ */

