/*
 * copyconstructors.cpp
 *
 *  Created on: Jan 1, 2021
 *      Author: pravinkumar
 */

#include <iostream>
#include <string>

#include "Prototype.h"

class File {
public:
	virtual ~File() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	int save(const std::string &file_name) {
		std::cout << "Saving the file " << std::endl;
		return 0;
	}
};

class FileAttributes {
public:
	std::string author { };
	//std::string actual_path;
	bool _is_readonly;

	//std::string _last_modified;

	//commented the attributes just to keep this simple;

	FileAttributes(const bool is_readonly) :
			_is_readonly(is_readonly) {
	}
	FileAttributes(const bool is_readonly, const std::string &author_) :
			_is_readonly(is_readonly), author(author_) {
	}
};

class SourceFile: public File {
public:
	std::string _name;
	FileAttributes *attributes;

	SourceFile(const std::string &name, const bool is_readonly) :
			_name(name), attributes(new FileAttributes(is_readonly)) {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	SourceFile(const std::string &name, const bool is_readonly, const std::string &author_name) :
				_name(name), attributes(new FileAttributes(is_readonly, author_name)) {
			std::cout << __PRETTY_FUNCTION__ << std::endl;
		}

	SourceFile(const SourceFile &other) :
			_name(other._name), attributes(
					new FileAttributes(other.attributes->_is_readonly)) {
		std::cout << __PRETTY_FUNCTION__ << "cons" << std::endl;
	}
	SourceFile& operator =(const SourceFile &right) {
		_name = right._name;
		attributes = new FileAttributes(right.attributes->_is_readonly);
		std::cout << __PRETTY_FUNCTION__ << "assign" << std::endl;
		return *this;
	}
private:

public:

	static SourceFile* new_cpp_source_file(const std::string &name,
			const std::string &author) {
		//you may have an already created object here to use that as the base object and copy the remaining inputs to it
		// but im going to create a new object just for the sake of simplicity;

		// in large objects, we may have to create a new object from already created objected using the copy constructor;

		// that's how prototype/ template concept works;

		// NOW, without any templates I am going to create the new object here itself;

		return new SourceFile(name, false, author);
		//here the false attribute is used without the knowledge of the input, we may think this of the part of using prototypes;

	}

	virtual ~SourceFile() {
		delete attributes;
		std::cout << __PRETTY_FUNCTION__ << std::endl;

	}
};

int clone_functions() {
	SourceFile file1 { "main.cpp", false };
	SourceFile file2 = file1;
	file2._name = "pravin";
	file2 = file1; // copy assignment
	SourceFile fil3(file2);		//copy constructor

	SourceFile *cpp_file = SourceFile::new_cpp_source_file("prototype.cpp", "Pravinkumar");

	return 0;
}
