/*
 * LiskovSubstitutionPrinciple.cpp
 *
 *  Created on: Dec 17, 2020
 *      Author: pravinkumar
 */

#include "LiskovSubstitutionPrinciple.h"
#include <iostream>

class Rectangle {
protected:
	int m_width;
	int m_height;
public:
	Rectangle(int width, int height) :
			m_width(width), m_height(height) {

	}
	virtual ~Rectangle() {
	}

	int getMHeight() const {
		return m_height;
	}

	virtual void setMHeight(int mHeight) {
		m_height = mHeight;
	}

	int getMWidth() const {
		return m_width;
	}

	virtual void setMWidth(int mWidth) {
		m_width = mWidth;
	}

	int area() {
		return m_width * m_height;
	}

};

class Square: public Rectangle {
public:
	Square(int size) : Rectangle(size,size) {
	}
	void setMHeight(int value) override {
		Rectangle::m_height = Rectangle::m_width = value;
	}
	void setMWidth(int value) override {
		Rectangle::m_height = Rectangle::m_width = value;
	}
};

/*
 * Going write a function with base class parameter;
 * So that the child classes get upcasted when they passed to this method;
 * we can just hold the reference to it;
 * */
void TestRectangle(Rectangle &rect) {
	int w = rect.getMWidth();
	rect.setMHeight(10);
	std::cout << "Expected area is " << w * 10 << std::endl;
	std::cout << "Actual area is " << rect.area() << std::endl;
}

void LiskovSubstitutionPrinciple::Run() {
	Rectangle r { 5, 6 };
	Square s { 5 };
	TestRectangle(r);
	TestRectangle(s);
}

LiskovSubstitutionPrinciple::~LiskovSubstitutionPrinciple() {
}

