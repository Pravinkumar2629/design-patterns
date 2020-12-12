/*
 * SingleResponsibility.cpp
 *
 *  Created on: Dec 12, 2020
 *      Author: pravinkumar
 */

#include "SingleResponsibility.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
struct Journal{
	std::string m_title;
	std::stringstream ss;
	std::vector<std::string> m_entries{};
	int count {0};

	Journal(const std::string& title):m_title(title){
	}
	void add_entry(const std::string& entry ){
		ss.str("");
		++ count;
		ss << "Adding Entry " << count<< " : " << entry;
		m_entries.push_back(ss.str());
	}
	std::string to_string(){
		ss.str("");
		ss << m_title << "\n\n";
		for(auto entry : m_entries){
			ss << entry << std::endl;
		}
		return ss.str();
	}
	void SaveData(){
		// your save data code goes here;

		/*
		 * BUT!.. wait a minute; your journal is not indented to have this functionality
		 * *
		 * Because, persistence of data is out of the scope here;
		 * Your journal class will only be serving it own purpose;
		 * *
		 * You can think of a scenario where you cannot ask a cricketer to make tea for you;
		 * Cricketer's purpose is to play cricket; not to make you tea;
		 * *
		 * */
	}
};

/*
 * So you probably have to go for the below option;
 *
 * */

struct PersistanceManager{
	void SaveJournal(Journal j, const std::string &filename){
		//Save your data;
		std::ofstream os(filename, std::fstream::out);
		os << j.to_string();
	}

	/*
	 * So by now this is more readable isn't it ?
	 *
	 * */
};


void SingleResponsibility::Run(){
	Journal j("Dear diary");
	j.add_entry("I ate a bug : (");
	j.add_entry("I cried : |");
	j.add_entry("I couldn't type; I m laughing");

	std::cout << j.to_string();


}
