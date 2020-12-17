/*
 * main.cpp
 *
 *  Created on: Dec 12, 2020
 *      Author: pravinkumar
 */

#include "SingleResponsibility.h"
#include "OpenClosed.h"
#include "LiskovSubstitutionPrinciple.h"
int main(){
	SingleResponsibility sr;
	sr.Run();

	OpenClosed opc;
	opc.Run();

	LiskovSubstitutionPrinciple lsp;
	lsp.Run();

}


