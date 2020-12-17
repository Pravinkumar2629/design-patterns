/*
 * DependencyInversion.cpp
 *
 *  Created on: Dec 17, 2020
 *      Author: pravinkumar
 */

#include "DependencyInversion.h"

#include <iostream>
#include <vector>
#include <tuple>
#include <string>

enum class Relationship {
	Parent, Child, Sibling, Friend
};

struct Person {
	std::string name;
};

using RelationshipRecord = std::vector<std::tuple<Person,Relationship, Person>>;

struct IRelationShipAPIs {
	virtual std::vector<Person> find_children_of(std::string &name) = 0;
	virtual ~IRelationShipAPIs() {
	}
	;
};

/*
 * Since this module is managing the low level data;
 *
 * this is an low level module; this is not abstractions; these are the low level options
 *
 * so this is low level modules
 *
 * */
struct Relationships: IRelationShipAPIs {
	RelationshipRecord relationships;
	void add_parent_children_relationship(Person &p1, Person &p2) {
		relationships.push_back(std::make_tuple(p1, Relationship::Parent, p2));
		relationships.push_back(std::make_tuple(p2, Relationship::Child, p1));
	}
	std::vector<Person> find_children_of(std::string &name) override {
		std::vector<Person> rec;
		for (auto&& [first, second, third] : relationships) {
			if (first.name == name && second == Relationship::Parent) {
				rec.push_back(third);
			}
		}
		return rec;
	}
};

/*
 * If suppose the relation managing low level module doesn't provide API's for;
 * accessing its data;
 * Then high level module has to depend on it; to get the data;
 *
 * WHICH IS NOT A GOOD IDEA TO DEPEND ON A LOW LEVEL MODULE;
 * BELOW IS AN EXAMPLE WHICH WE SHOULD NOT DO IN OUR WORKS;
 *
 * */
struct FindRelationships {
	Relationships &relationships;

	FindRelationships(Relationships &relationships_) :
			relationships(relationships_) {

	}

	//This is just gonna work statically;
	void FindChildrenOfAmutha() {
		for (auto&& [first, second, third] : relationships.relationships) {
			if (first.name == "Amutha" && second == Relationship::Parent) {
				std::cout << "Amutha has child " << third.name << std::endl;
			}
		}
	}
	/* Above is very bad idea of browsing the data;
	 *	instead take a look at the function provides; the api's
	 *
	 * */
};

/*
 * Below is the better way of acccessing the low level data;
 *
 * through abstraction;
 *
 * */
struct FindRelationshipsV2 {
	IRelationShipAPIs &api;
	FindRelationshipsV2(IRelationShipAPIs &api_) :
			api(api_) {

	}
	void FindChildrenOf(std::string &name) {
		for (auto &children : api.find_children_of(name)) {
			std::cout << name << " has a child " << children.name
					<< std::endl;
		}
	}

};

void Before() {
	Relationships r;
	Person p1 { "Amutha" };
	Person p2 { "Pravin" };
	r.add_parent_children_relationship(p1, p2);
	FindRelationships fr(r);
	fr.FindChildrenOfAmutha();
}

void After() {
	Relationships r;
	Person p1 { "Dhanabal" };
	Person p2 { "Prathivindhan" };
	r.add_parent_children_relationship(p1, p2);
	FindRelationshipsV2 fr(r);
	fr.FindChildrenOf(p1.name);
}

void DependencyInversion::Run() {
	Before();
	After();
}

DependencyInversion::~DependencyInversion() {
	// TODO Auto-generated destructor stub
}

