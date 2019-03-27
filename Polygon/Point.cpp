//
//  Point.cpp
//  Polygon
//
//  Created by Stone Blair on 12/4/18.
//  Copyright © 2018 Stone Blair. All rights reserved.
//

#include <stdio.h>
#include "Point.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

//default constructor
Point::Point(double xValue, double yValue): _x(xValue), _y(yValue){
    
}
//Copy constructor
Point::Point(const Point& point): _x(point._x), _y(point._y){}

//Gives the y value of the point
// returns the y value held by the point
double Point::GetX()const{
    return _x;
}

//Gives the y value of the point
// returns the y value held by the point
double  Point::GetY() const{
    return _y;
}

//Finds the distance between two points
//Param: finds distance between this and p2
// return the distance between the two points
double Point::Distance( const Point& p2)const{
    return sqrt(pow(_x - p2._x,2) + pow(_y - p2._y,2));
}
//Reads input from a source
//param: initilaizes x and y based upon input from "input"
void Point::Read(istream& input){
    input >> _x >> _y;
}

//Prints the string represntation of a point to a output source
// param: sends the string representation of a point to an output source
void Point::Write(ostream& out)const{
    out << "[" << setprecision(1) << fixed << _x << ", " << setprecision(1) << fixed << _y << "]"<< endl;
}
