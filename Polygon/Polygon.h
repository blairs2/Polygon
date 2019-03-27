//
//  Polygon.h
//  Polygon
//
//  Created by Stone Blair on 12/5/18.
//  Copyright © 2018 Stone Blair. All rights reserved.
//

#pragma once
#include "Point.h"
#include <string>
#include <cmath>
#include <iostream>
using std::ostream;
using std::istream;
using std::string;


class Polygon{
    Point** _points;
    size_t _size, _capacity;
    
public:
    Polygon(size_t);
    Polygon(const Polygon&);
    ~Polygon();
    double GetArea()const;
    double GetPerimeter()const;
    int Read(istream&);
    void Write(ostream&)const;
    Point* Get(size_t) const;
    bool Add(const Point&);
    bool Add(double, double);
    bool IsFull()const;
    size_t GetNumPoints()const;
};
