/*
 * main.cpp
 *
 *  Created on: Dec 29, 2020
 *      Author: pravinkumar
 */

#include <string>
#include  <sstream>
#include <fstream>

struct StreamBase {
	std::ofstream ostream;
	std::ifstream istream;

	StreamBase() :
			StreamBase("default.dax") {
	}
	StreamBase(const std::string &streamname) :
			ostream(streamname,
					std::fstream::out | std::fstream::binary
							| std::fstream::app), istream(streamname,
					std::fstream::in | std::fstream::binary) {
	}
	template<typename T>
	StreamBase& operator <<(T &&val) {
		ostream << val << std::endl;
		return *this;
	}

	virtual ~StreamBase() {
	}
};

struct Serializer {
	std::ostringstream oss;
	template<typename T>
	Serializer& operator <<(const std::string &str) {
		oss << "{ value : " << str.c_str() << ", size : " << str.size() << "};";
		return *this;
	}
	template<typename T>
	Serializer& operator <<(T &&val) {
		oss << "{ value : " << val << "};";
		return *this;
	}
	template<typename T>
	Serializer& operator >>(T &&val) {
		oss << "{ value : " << val << "};";
		return *this;
	}
	std::string to_string(){
		return oss.str();
	}
};

struct Serializable {
	Serializer stream;
	virtual Serializer& Serialize() = 0;
	virtual ~Serializable() {
	}
};

class CustomerDetails: Serializable {
	std::string mobile;
	std::string email;
public:
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
	std::string name;
	std::string type;
	int id;
	CustomerDetails *details;
public:
	Account(const std::string &name_, const std::string &type_, int id_,
			const std::string &email_, const std::string &mobile_) :
			name(name_), type(type_), id(id_), details(
					new CustomerDetails(email_, mobile_)) {
	}
	Serializer& Serialize() {
		stream << name << type << id << details->Serialize().to_string();
		return stream;
	}
};

int main() {
	Account a("Noname", "savings", 12, "sample@gmail.com", "9789671990");
	StreamBase base;
	base << a.Serialize().to_string();
}

