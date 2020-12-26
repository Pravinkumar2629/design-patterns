/*
 * PersonEducationBuilder.cpp
 *
 *  Created on: Dec 25, 2020
 *      Author: pravinkumar
 */

#include "PersonEducationBuilder.h"

template <typename T>
PersonEducationBuilder<T>& PersonEducationBuilder<T>::in(
		const std::string &graduation) {
	P().setGraduatedIn(graduation);
	return *this;
}
