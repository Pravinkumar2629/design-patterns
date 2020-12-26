/*
 * Point.cpp
 *
 *  Created on: Dec 26, 2020
 *      Author: pravinkumar
 */
#include <cmath>

//Using Factory methods
class Point {
	int _x, _y;
	Point(int x, int y) :
			_x(x), _y(y) {
	}
public:
	//Factory methods;
	static Point NewCartesianPoint(int rho, int theta) {
		return { ( rho * std::sin(theta) ), ( rho * std::cos(theta) )};
	}
	static Point NewPoint(int x, int y) {
		return {x, y};
	}
};

class PointV2 {

	int _x;
	int _y;
	PointV2(int x, int y) :
			_x(x), _y(y) {
	}
	friend class PointFactory;  //if this is in case of modifying Pointv2; Breaking Open closed principle
};
struct PointFactory {

	//The problem is that, Point constructors are private; so can't access it to create object;
	static PointV2 NewCartesianPoint(int rho, int theta) {
		return {(rho * std::sin(theta)), (rho * std::cos(theta))};
	}
	static PointV2 NewPoint(int x, int y) {
		return {x, y};
	}
};



class PointV3 {
	int _x, _y;
	PointV3(int x, int y) :
			_x(x), _y(y) {
	}
private:
	struct PointFactoryI {
		static PointV3 NewCartesianPoint(int rho, int theta) {
			return {(rho * std::sin(theta)), (rho * std::cos(theta))};
		}
		static PointV3 NewPoint(int x, int y) {
			return {x, y};
		}
	};
public:
	static PointFactoryI Factory;
};


void use_Points() {
	//Factory method;
	auto point = Point::NewPoint(10, 11);
	auto point2 = Point::NewCartesianPoint(2, 60);

	//Factory class approach
	auto point3 = PointFactory::NewCartesianPoint(2, 61);
	auto point4 = PointFactory::NewPoint(6, 1);

	//Inner class Factory approach
	auto point5 = PointV3::Factory.NewCartesianPoint(2, 61);
	auto point6 = PointV3::Factory.NewPoint(6, 1);
}
