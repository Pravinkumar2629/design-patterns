/*
 * Singleton.cpp
 *
 *  Created on: Jan 1, 2021
 *      Author: pravinkumar
 */
#include "Singleton.h"

#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <boost/lexical_cast.hpp>

class Database {
public:
	virtual int get_population(const std::string &city) = 0;
	virtual ~Database() {

	}
};

class SingletonDatabase: public Database {
	std::map<std::string, int> mapp;
	SingletonDatabase() {
		std::cout << "Initializing!.." << std::endl;
		std::fstream fs("data.txt", std::fstream::in);
		std::string name, population;
		while (std::getline(fs, name)) {
			std::getline(fs, population);
			//mapp.insert(std::make_pair(name, std::stoi(population)));
			mapp.insert(std::make_pair(name, boost::lexical_cast<int>(population)));
		}
	}

public:
	//For singleton we need to delete the copy constructors and copy assignment
	//operators, otherwise we can create the copy of singleton object
	// that would violate the principle of singleton;
	SingletonDatabase(const SingletonDatabase&) = delete;
	SingletonDatabase& operator=(const SingletonDatabase&) = delete;

	int get_population(const std::string &city) override {
		return mapp[city];
	}
	static SingletonDatabase instance;
	static SingletonDatabase& get_instance() {
		return instance;
	}
	virtual ~SingletonDatabase() {

	}

};

/*
 * Just comments
 *
 * */

SingletonDatabase SingletonDatabase::instance { };

auto singleton_record_finder(std::vector<std::string> cities) {
	unsigned long long int total_population{0};
	for (auto &city : cities) {
		total_population += SingletonDatabase::get_instance().get_population(
				city);
	}
	return total_population;
}

class DummyDatabase: public Database {
	std::map<std::string, int> mapp;
	DummyDatabase() {
			std::cout << "Initializing!.." << std::endl;
			{
				mapp.insert(std::make_pair("Ariyalur", 200));
				mapp.insert(std::make_pair("Madurai", 300));
				mapp.insert(std::make_pair("Chennai", 400));
				mapp.insert(std::make_pair("Sikazhi", 500));
			}
		}

public:
	//For singleton we need to delete the copy constructors and copy assignment
	//operators, otherwise we can create the copy of singleton object
	// that would violate the principle of singleton;
	DummyDatabase(const DummyDatabase&) = delete;
	DummyDatabase& operator=(const DummyDatabase&) = delete;

	int get_population(const std::string &city) override {
		return mapp[city];
	}
	static DummyDatabase instance;
	static DummyDatabase& get_instance() {
		return instance;
	}
	virtual ~DummyDatabase() {

	}
};

DummyDatabase DummyDatabase::instance {};

class RecordFinder{
	Database &db;
public:
	RecordFinder(Database &db_) : db(db_){}

	auto find(std::vector<std::string> cities) {
		unsigned long long int total_population{0};
		for (auto &city : cities) {
			total_population += db.get_population(city);
		}
		return total_population;
	}
};


/*
 *
 * For testing the functionality we don't need to query the singleton database origin data;
 * just for the sake of testing;
 *
 * So we would use a a dummy database for doing the testing;
 *
 * this way, we can be sure that the change original data would not affect the testing of this module;
 *
 * */
class Test {
public:
	int test_singleton_db() {
		std::vector<std::string> cities { "Ariyalur", "Madurai" };
		if (220000 == singleton_record_finder(cities)) {
			return 0;
		}
		return 1;
	}
	int test_singleton_db_v2() {
		RecordFinder rf(DummyDatabase::get_instance());
		std::vector<std::string> cities{ "Ariyalur", "Madurai" };
		if (500 == rf.find(cities)) {
			return 0;
		}
		return 1;
	}
};

int test_singleton() {
	Test test;
	if (test.test_singleton_db_v2() == 0) {
		std::cout << "Test complete; module is working fine" << std::endl;
	} else {
		std::cout << "Test complete; error in module" << std::endl;
	}
	return 0;
}

int use_singleton() {
	std::cout << "Printing the population of chennai "
			<< SingletonDatabase::get_instance().get_population("yn")
			<< std::endl;
	return 0;
}

