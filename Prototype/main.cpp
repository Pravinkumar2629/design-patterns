/*
 * main.cpp
 *
 *  Created on: Dec 29, 2020
 *      Author: pravinkumar
 */

#include <string>
#include  <sstream>
#include <fstream>


struct StreamBase{
	std::ofstream ostream;
	std::ifstream istream;

	StreamBase(): StreamBase("default.dax"){}
	StreamBase(const std::string &streamname) :
		ostream(streamname, std::fstream::out | std::fstream::binary | std::fstream::app)
		,istream(streamname,  std::fstream::in |std::fstream::binary)
	{}
	template <typename T>
	virtual StreamBase& operator << (T&& val){
		ostream << val << std::endl;
		return *this;
	}
};


struct Serializable{
	StreamBase stream;
	virtual std::string Serialize() = 0;
	virtual std::string Deserialize() = 0;
	virtual ~Serializable(){};
};

class CustomerDetails : Serializable{
	std::string mobile;
	std::string email;
	~CustomerDetails(){}

	std::string Serialize(){
		std::ostringstream oss;

		oss << mobile << email;
	}
};

class Account : Serializable{
	std::string name;
	std::string type;
	int id ;
	CustomerDetails *details;

	void Serialize(){

	}

};


int main(){

}




