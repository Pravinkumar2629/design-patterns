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

void ProcessBeforeDesignPrinciple() {
	Product p1{"Apple", Color::GREEN, Size::SMALL};
	Product p2{"Bike", Color::BLUE, Size::LARGE};
	Product p3{"Laptop", Color::RED, Size::MEDIUM};
	auto v = std::vector<Product*>{&p1, &p2, &p3};
	ProductFilter pf;
	for(auto &i : pf.filter_by_color(v, Color::GREEN)){
		std::cout << "item " << i->name << " is green" << std::endl;
	}

}

void OpenClosed::Run() {
	ProcessBeforeDesignPrinciple();
}
