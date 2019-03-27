//
//  Polygon.cpp
//  Polygon
//
//  Created by Stone Blair on 12/5/18.
//  Copyright © 2018 Stone Blair. All rights reserved.
//

#include <stdio.h>
#include "Polygon.h"
#include <cmath>
#include <iostream>
using namespace std;

//constructor
Polygon::Polygon(size_t capacity):_size(0),_capacity(capacity){
    _points = new Point*[_capacity];
}
//copy constructor
Polygon::Polygon(const Polygon& polygon):_size(polygon._size), _capacity(polygon._capacity){
    _points = new Point*[_capacity];
    for(int i = 0; i< _size; i++){
        _points[i] = new Point(* polygon._points[i]);
    }
    for(size_t j = _size; j < _capacity; j++){
        _points= nullptr;
    }
}
//destructor
Polygon::~Polygon(){
    for(int i = 0 ; i<_size; i++){
        delete _points[i];
    }
    delete[] _points;
    
}
//returns the point at a given index
// param index is given index
//returns a point pointer
Point* Polygon::Get(size_t index)const{
    for(int i = 0; i < _size; i++){
        if(i == index){
            return _points[i];
        }
    }
    return nullptr;
}

//calculates the area of any polygon
//returns the area of any polygon
double Polygon::GetArea()const{
    double sum =0;
    for(int i = 0; i <_size-1; i++){
        sum += _points[i]->GetX() * _points[i+1]->GetY() - _points[i]->GetY() * _points[i+1]->GetX();
    }
    sum += _points[_size-1]->GetX() * _points[0]->GetY() - _points[_size-1]->GetY() * _points[0]->GetX();
    
    return abs(sum/2);
}
//calculates the perimeter of any polygon
//returns the perimeter of any polygon
double Polygon::GetPerimeter()const{
    double perimeter= 0;
    for(int i = 0; i < _size-1; i++){
        perimeter += _points[i]->Distance(*_points[i+1]);
    }
    perimeter += _points[_size-1]->Distance(*_points[0]);
    return perimeter;
}
//Reads and initializes polygon
// param the data that initializes the polygon comes from the input
//returns the number of points read by the method
int Polygon::Read(istream& input){
    Point p;
    int count = 0;
    string line;
    
    while(input.good()){
        p.Read(input);
        if(Add(p)){
            count++;
        }
    }
    
    return count;
}

//writes the string representation of the polygon to an output source
//param out is the output source the polygon is sent to
void Polygon::Write(ostream& out)const{
    for(int i = 0; i<_size; i++){
        out << "P" << i+1<< ": ";
        _points[i]->Write(out);
        
    }
    
}
//Adds a new point to the polygon based upon x and y values
//param x and y are used to create a new point which is added to the polygon
//returns true if successfully added the point to the polygon
bool Polygon::Add(double x, double y){
    if(!IsFull()){
        _points[_size++] = new Point(x,y);
        return true;
    }
    return false;
}

//Adds a new point to the polygon
//param newPoint is attmpted to be added to the polygon
//returns true if successfully added the point to the polygon
bool Polygon::Add(const Point& newPoint){
    return this->Add(newPoint.GetX(),newPoint.GetY());
}

//tells whether or not the polygon is full of points
//returns true of false if the polygon is full
bool Polygon::IsFull()const{
    return _capacity==_size;
}

//gives the number of points make up the polygon
//returns the number of points that compose the polygon
size_t Polygon::GetNumPoints()const{
    return _size;
}
