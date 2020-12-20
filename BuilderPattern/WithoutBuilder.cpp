/*
 * WithoutBuilder.cpp
 *
 *  Created on: Dec 18, 2020
 *      Author: pravinkumar
 */

#include "WithoutBuilder.h"

#include <iostream>
#include <string>
#include <sstream>


/*
 * when you want to create an object piece by piece, you will not want to do like below
 *
 * */
void CreateStrings(){
	std::string text;
	std::string word;
	std::string html;

	text = "This is a sample paragraph";
	word = "And Im a word in it";
	html = "<p>" ;
	html += text;
	html += word;
	html += "</p>";

	std::string words[]{"Hello", "world"};
	//same as the below;

	// now when you want to get your complete object you 'd want functions like str() which is
	// implmeneted below;

}
void pretty_print(std::string html){
	// now you cannot pretty print it. as you have just appended to a string
	std::cout << html << std::endl;
}



