/*
 * poc.cpp
 *
 *  Created on: Dec 26, 2020
 *      Author: pravinkumar
 */


#include <iostream>
#include <memory>

class Parent;
class Object {
public:
	int x{0};
	static std::unique_ptr<Parent> create(){
		return std::make_unique<Parent>();
	}
};
class Child;
class Child2;
class Parent {
protected:
	Object ob;
public:
	std::unique_ptr<Child> use_child() const {
		return std::make_unique<Child>();
	}
	auto use_child2() const {
		return std::make_unique<Child2>();
	}
	void do_complete() {
		std::cout << "Completing" << std::endl;
	}
};

class Child: public Parent {
public:
	Child& doSomething() {
		ob.x = 1;
		std::cout << "Doing something" << std::endl;
		return *this;
	}

};

class Child2: public Parent {
public:
	Child2& doNothing() {
		ob.x = 0;
		std::cout << "Doing Nothing" << std::endl;
		return *this;
	}
};

//int main() {
//	Object::create()->use_child()->doSomething().doSomething().use_child2()->doNothing().doNothing().do_complete();
//}


