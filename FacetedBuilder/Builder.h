/*
 * PersonBuilder.h
 *
 *  Created on: Dec 25, 2020
 *      Author: pravinkumar
 */

#ifndef BUILDER_H_
#define BUILDER_H_

#include "Person.h"

template<class T> class Builder {
	T _obj;
public:
	Builder(const T &&obj) :
			_obj(obj) {
	}
	Builder() :
			_obj() {
	}
	T& build() const {
		return _obj;
	}
	virtual ~Builder() {

	}
};

#endif /* BUILDER_H_ */

/*
 *
 *
 *
 #include <iostream>
 #include <string>
 #include <sstream>


 class Person {
 std::string _name,
 _address,
 _zipCode,
 _worksAs,
 _salary,
 _graduatedIn,
 _graduatedFrom,
 _withGrade;  //Let's just keep it very simple. All are string properties;

 inline std::string str()const {
 std::ostringstream oss;
 oss << getName() << getAddress() << getZipCode() << getWorksAs()<< getSalary()
 << getGraduatedIn() << getWithGrade() << getGraduatedFrom() <<std::endl;
 return oss.str();
 }
 public:
 static PersonBuilder create(){
 return PersonBuilder();
 }


 const std::string& getAddress() const {
 return _address;
 }

 void setAddress(const std::string &address) {
 _address = address;
 }

 const std::string& getName() const {
 return _name;
 }

 void setName(const std::string &name) {
 _name = name;
 }

 const std::string& getSalary() const {
 return _salary;
 }

 void setSalary(const std::string &salary) {
 _salary = salary;
 }

 const std::string& getWorksAs() const {
 return _worksAs;
 }

 void setWorksAs(const std::string &worksAs) {
 _worksAs = worksAs;
 }

 const std::string& getZipCode() const {
 return _zipCode;
 }

 void setZipCode(const std::string &zipCode) {
 _zipCode = zipCode;
 }

 const std::string& getGraduatedFrom() const {
 return _graduatedFrom;
 }

 void setGraduatedFrom(const std::string &graduatedFrom) {
 _graduatedFrom = graduatedFrom;
 }

 const std::string& getGraduatedIn() const {
 return _graduatedIn;
 }

 void setGraduatedIn(const std::string &graduatedIn) {
 _graduatedIn = graduatedIn;
 }

 const std::string& getWithGrade() const {
 return _withGrade;
 }

 void setWithGrade(const std::string &withGrade) {
 _withGrade = withGrade;
 }
 };
 *
 *
 * */