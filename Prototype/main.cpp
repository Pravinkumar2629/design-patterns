/*
 * main.cpp
 *
 *  Created on: Dec 29, 2020
 *      Author: pravinkumar
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Prototype.h"

struct StreamBase {
	std::ofstream ostream;
	std::ifstream istream;

	StreamBase() :
			StreamBase("default.dax") {
	}
	StreamBase(const std::string &streamname) :
			ostream(streamname, std::fstream::out | std::fstream::binary), istream(
					streamname, std::fstream::in | std::fstream::binary) {
	}
	template<typename T>
	StreamBase& operator <<(T &&val) {
		ostream << val << std::endl;
		return *this;
	}

	void next(std::string &buff, char delim) {
		std::getline(istream, buff, delim);
	}

	virtual ~StreamBase() {
	}
};

struct Serializer {
	std::ostringstream oss;

	template<typename T>
	Serializer& operator <<(T &&val) {
		oss << "value:" << val << ";";
		return *this;
	}

	template<typename T>
	Serializer& operator >>(T &val) {
		oss << "value: " << val << ";";
		return *this;
	}

	std::string to_string() {
		return oss.str();
	}
};

template<>
Serializer& Serializer::operator << <const std::string&>(
		const std::string &str) {
	oss << "value:" << str.c_str() << ";";
	return *this;
}

struct Deserializer {
	StreamBase &base;
	Deserializer(StreamBase &base_) :
			base(base_) {
	}

	template<typename T>
	Deserializer& operator >>(T &val) {
		std::string buff;
		base.next(buff, ';');
		std::string value = buff.substr(buff.find("value:") + 6, buff.size());
		if (typeid(val) == typeid(int)) {
			val = std::stoi(value);
		} else {
			val = value;
		}
		return *this;
	}
};

struct Serializable {
	Serializer stream;
	virtual Serializer& Serialize() = 0;
	virtual ~Serializable() {
	}
};

class CustomerDetails: Serializable {
public:
	std::string mobile;
	std::string email;

	CustomerDetails(const std::string &email_, const std::string &mobile_) :
			mobile(mobile_), email(email_) {
	}
	~CustomerDetails() {
	}
	Serializer& Serialize() {
		stream << mobile << email;
		return stream;
	}
};

class Account: Serializable {
public:
	std::string name;
	std::string type;
	CustomerDetails *details;

	Account(const std::string &name_, const std::string &type_,
			const std::string &email_, const std::string &mobile_) :
			name(name_), type(type_), details(
					new CustomerDetails(email_, mobile_)) {
	}
	Serializer& Serialize() {
		stream << name << type << details->Serialize().to_string();
		return stream;
	}
};

int main() {
	Account a("account_name", "savings", "sample@gmail.com", "9749571990");
	StreamBase base;
	base << a.Serialize().to_string();
	Deserializer d(base);
	Account b("", "", "", "");
	d >> b.name >> b.type >> b.details->mobile >> b.details->email;
	std::cout << b.Serialize().to_string() << std::endl;


	clone_functions();
}

