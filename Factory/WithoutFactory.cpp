/*
 * WithoutFactory.cpp
 *
 *  Created on: Dec 26, 2020
 *      Author: pravinkumar
 */

#include <cmath>

class Point {
	int _x, _y;
public:
	//When wanted to make point with x and y;
	Point(int x, int y) :
			_x(x), _y(y) {
	}
	// when wanted to make rho and theta;
	/*

	Point(int rho, int theta) :
			_x(rho * std::sin(theta)), _y(rho * std::cos(theta)) {

	}

	*/
	//The whole above thing is not allowed as it is against funciton overloading rules;
};

enum class PointType {
	Regular, Cartesian
};

class PointV2 {
	int _x, _y;
public:
	PointV2(int x , int y, PointType type) {
		if(type == PointType::Regular){
			_x = x;
			_y =  y;
		}
		else{
			_x = x * std::sin(x);
			_y = y * std::cos(y);
		}
	}
	//Ok the above works..  but it is still kind of not ok. isn't it ?

};










