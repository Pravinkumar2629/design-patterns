/*
 * main.cpp
 *
 *  Created on: Dec 23, 2020
 *      Author: pravinkumar
 */

/* *
 * the idea is to combine builder of same root type; something like;
 *
 * 	Person works as so and so.....
 *
 * 	and lives in ....
 *
 * 	and married to ... etc
 *
 * 	has children named...
 *
 * 	etc.. the person class may have all these attributes. but if you see person becomes base for these attribs;
 *
 * 	and all these are separate in nature;
 *
 * 	idea. is to have a group of builders which are exposed by Person class to provide various build methods;
 * *
 * */

#include <iostream>
#include <memory>
#include <string>

#include "PersonBuilderV2.h"

int main() {
	auto person = Person::create()
			.named("Pravin")
			.lives()
				.in("Sirkazhi")
			.works()
				.as("Software Developer")
			.build();
	std::cout <<  person.str();
	return 0;
}
