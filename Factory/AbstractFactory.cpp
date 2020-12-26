/*
 * AbstractFactory.cpp
 *
 *  Created on: Dec 26, 2020
 *      Author: pravinkumar
 */

#include <string>
#include <memory>
#include <iostream>
#include <map>
#include <functional>

struct HotDrink {
	virtual void make_hot_drink(const int &volume) = 0;
	virtual ~HotDrink() = default;
};

struct Tea: public HotDrink {
	void make_hot_drink(const int &volume) override {
		std::cout << "Making tea of " << volume << ", ml";
	}
};
struct Coffee: public HotDrink {
	void make_hot_drink(const int &volume) override {
		std::cout << "Making Coffee " << volume << ", ml";
	}
};

struct HotDrinkFactory {
	virtual std::unique_ptr<HotDrink> make() const = 0;
	virtual ~HotDrinkFactory() {
	}

};
struct TeaFactory: public HotDrinkFactory {
	std::unique_ptr<HotDrink> make() const {
		return std::make_unique<Tea>();
	}
	virtual ~TeaFactory() {
	}
};

struct CoffeeFactory: public HotDrinkFactory {
	std::unique_ptr<HotDrink> make() const {
		return std::make_unique<Coffee>();
	}
	virtual ~CoffeeFactory() {
	}
};

class DrinkFactory {
	std::map<std::string, std::unique_ptr<HotDrinkFactory>> drinks;
public:
	DrinkFactory() {
		drinks["tea"] = std::make_unique<TeaFactory>();
		drinks["coffee"] = std::make_unique<CoffeeFactory>();
	}
	void operator[](const std::string &name) {
		auto drink = drinks[name]->make();
		drink->make_hot_drink(200);
	}
	void make_drink(const std::string &name) {
		(*this)[name];
	}
};

struct FunctionalDrinkFactory {
	std::map<std::string, std::function<std::unique_ptr<HotDrink>()> > drinks;
	FunctionalDrinkFactory() {
		drinks["tea"] = [] {
			return std::make_unique<Tea>();
		};
		drinks["coffee"] = [] {
			return std::make_unique<Coffee>();
		};
	}
	;
	void operator[](const std::string &name) {
		auto x = drinks[name]();
		x->make_hot_drink(200);
	}
	void make_drink(const std::string &name) {
		(*this)[name];
	}
};

void use_abstract_factory() {
	DrinkFactory df;
	df["tea"];
	df.make_drink("coffee");
}
