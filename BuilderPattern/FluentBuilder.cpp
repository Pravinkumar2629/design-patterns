/*
 * FluentBuilder.cpp
 *
 *  Created on: Dec 21, 2020
 *      Author: pravinkumar
 */

#include "FluentBuilder.h"
#include "HTMLElementV1.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;


void FluentBuilder::Run() {
	auto element = HTMLElement::create("paragraph").add_child("text",
			"text One").add_child("text", "text two").add_child("text",
			"text three").add_child("text", "text four").build();
	std::cout << element.str();
}
