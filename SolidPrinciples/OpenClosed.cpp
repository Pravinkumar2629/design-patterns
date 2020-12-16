/*
 * OpenClosed.cpp
 *
 *  Created on: Dec 16, 2020
 *      Author: pravinkumar
 */

#include "OpenClosed.h"
#include <iostream>
#include <string>
#include <vector>

enum class Color {
	RED, GREEN, BLUE
};
enum class Size {
	SMALL, MEDIUM, LARGE
};

struct Product {
	std::string name;
	Color color;
	Size size;
};

struct ProductFilter {
	std::vector<Product*> filter_by_color(std::vector<Product*> items,
			Color color) {
		std::vector<Product*> ret;
		for (auto &i : items) {
			if (color == i->color) {
				ret.push_back(i);
			}
		}
		return ret;
	}
	std::vector<Product*> filter_by_size(std::vector<Product*> items,
			Size size) {
		std::vector<Product*> ret;
		for (auto &i : items) {
			if (size == i->size) {
				ret.push_back(i);
			}
		}
		return ret;
	}
	std::vector<Product*> filter_by_size_and_color(std::vector<Product*> items,
			Size size, Color color) {
		std::vector<Product*> ret;
		for (auto &i : items) {
			if (size == i->size && color == i->color) {
				ret.push_back(i);
			}
		}
		return ret;
	}
};
//------------------------------------------------------------------------------AFter;

template<typename T> struct Specification;
template<typename T> struct AndSpecification;

template<typename T>
struct Specification {
	virtual bool is_satisfied(T *spec) = 0;
	virtual ~Specification() {
	}

	AndSpecification<T> operator &&(Specification<T> &right) {
		return AndSpecification<T>(*this, right);
	}

};

template<typename T>
struct AndSpecification: public Specification<T> {
	Specification<T> &_first;
	Specification<T> &_second;
	AndSpecification(Specification<T> &first, Specification<T> &second) :
			_first(first), _second(second) {

	}
	bool is_satisfied(T *item) {
		return _first.is_satisfied(item) && _second.is_satisfied(item);
	}
};

template<typename T>
struct Filter {
	virtual std::vector<T*> filter(std::vector<T*> items,
			Specification<T> &spec) = 0;
	virtual ~Filter() {
	}
};

struct ColorSpecification: public Specification<Product> {
	Color _color;
	ColorSpecification(Color color) {
		_color = color;
	}
	bool is_satisfied(Product *p) override {
		return p->color == _color;
	}
	~ColorSpecification() {
	}
};

struct SizeSpecification: public Specification<Product> {
	Size _size;
	SizeSpecification(Size size) {
		_size = size;
	}
	bool is_satisfied(Product *p) override {
		return p->size == _size;
	}
	~SizeSpecification() {
	}
};

struct ProductFilterV2: public Filter<Product> {
	std::vector<Product*> filter(std::vector<Product*> items,
			Specification<Product> &spec) {
		std::vector<Product*> itemsRet;
		for (auto item : items) {
			if (spec.is_satisfied(item)) {
				itemsRet.push_back(item);
			}
		}
		return itemsRet;
	}
	~ProductFilterV2() {
	}
};

void ProcessAfterDesignPrinciple() {
	Product p1 { "Apple", Color::GREEN, Size::MEDIUM };
	Product p2 { "Bike", Color::BLUE, Size::LARGE };
	Product p3 { "Laptop", Color::RED, Size::MEDIUM };
	auto v = std::vector<Product*> { &p1, &p2, &p3 };
	ProductFilterV2 pfv2;
	ColorSpecification cspec(Color::RED);
	for (auto &i : pfv2.filter(v, cspec)) {
		std::cout << "item " << i->name << " is Red" << std::endl;
	}

	SizeSpecification sspec(Size::MEDIUM);
	for (auto &i : pfv2.filter(v, sspec)) {
		std::cout << "item " << i->name << " is Medium" << std::endl;
	}

	AndSpecification<Product> andSpec(cspec, sspec);
	for (auto &i : pfv2.filter(v, andSpec)) {
		std::cout << "item " << i->name << " is green and Medium" << std::endl;
	}

	auto andSpecOne = cspec && sspec;
	for (auto &i : pfv2.filter(v, andSpec)) {
		std::cout << "item " << i->name << " is green and Medium" << std::endl;
	}

}

void ProcessBeforeDesignPrinciple() {
	Product p1 { "Apple", Color::GREEN, Size::SMALL };
	Product p2 { "Bike", Color::BLUE, Size::LARGE };
	Product p3 { "Laptop", Color::RED, Size::MEDIUM };
	auto v = std::vector<Product*> { &p1, &p2, &p3 };
	ProductFilter pf;
	for (auto &i : pf.filter_by_color(v, Color::GREEN)) {
		std::cout << "item " << i->name << " is green" << std::endl;
	}

}

void OpenClosed::Run() {
	ProcessBeforeDesignPrinciple();
	ProcessAfterDesignPrinciple();
}
