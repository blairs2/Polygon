//
//  Polygon.hpp
//  Polygon
//
//  Created by Stone Blair on 12/4/18.
//  Copyright © 2018 Stone Blair. All rights reserved.
//

# pragma once
#include <string>
#include "Polygon.h"
#include <iostream>
#include <cmath>
#include <iomanip>



class PolygonList{
    size_t _capacity;
    Polygon** _polygons;
    size_t _size;
public:
    PolygonList(size_t);
    ~PolygonList();
    size_t Read( istream&);
    size_t Write( ostream&)const;
    Polygon* Get(size_t) const;
    bool Add(const Polygon&);
    bool IsFull()const;
    size_t GetSize()const;
    void Clear();
    size_t GetCapacity()const;
    
    
};
