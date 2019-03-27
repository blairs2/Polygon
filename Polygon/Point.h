//
//  Header.h
//  Polygon
//
//  Created by Stone Blair on 12/4/18.
//  Copyright © 2018 Stone Blair. All rights reserved.
//

#pragma once
using namespace std;
#include <iostream>
#include <fstream>


class Point{
    double _x,_y;
public:
    Point(double=0,double=0);
    Point(const Point&);
    double GetX()const;
    double GetY()const;
    double Distance(const Point&)const;
    void Read(istream&);
    void Write(ostream&)const;
};
