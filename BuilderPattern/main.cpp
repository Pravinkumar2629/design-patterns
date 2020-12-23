/*
 * main.cpp
 *
 *  Created on: Dec 20, 2020
 *      Author: pravinkumar
 */


#include "HTMLBuilder.h"
#include "FluentBuilderV2.h"
#include "FluentBuilder.h"

int main(){
	Run(); //HTML Builder Run();

	FluentBuilder v1;
	v1.Run();

	FluentBuilderV2 v2;
	v2.Run();

}
