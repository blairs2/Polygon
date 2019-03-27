//
//  Polygon.cpp
//  Polygon
//
//  Created by Stone Blair on 12/4/18.
//  Copyright © 2018 Stone Blair. All rights reserved.
//

#include "PolygonList.h"
#include "Polygon.h"


//constructor
PolygonList::PolygonList(size_t capacity): _size(0), _capacity(capacity){
    _polygons = new Polygon*[_capacity];
    
}
//destructor
PolygonList::~PolygonList(){
    for(int i = 0; i < _size; i++){
        delete _polygons[i];
    }
    delete[] _polygons;
}
//Reads and initializes polygonList
// param the data that initializes the polygonlist comes from the input
//returns the number of polygons read by the method
size_t PolygonList::Read( istream& input){
    Polygon* p;
    Point point;
    int numPoints;
    int count = 0;
    string line;
    
        while(input.good()){
            input >> numPoints;
            p = new Polygon(numPoints);
            for(int i = 0; i<numPoints; i++){
                point.Read(input);
                p->Add(point);

            }
            if(Add(*p)){
                count++;
            }
        }
    
    return count;
}
//writes the string representation of the polygonlist to an output source
//param out is the output source the polygonlist is sent to
size_t PolygonList::Write( ostream& out)const{
    for(int i =0; i< _size; i++){
        out << "Polygon" << i +1 << ": " << _polygons[i]->GetNumPoints() << " Points"<< endl;
        _polygons[i]->Write(out);
        out << endl;
    }
    return _size;
}

//returns the polygon at a given index
// param index is given index
//returns a polygon pointer
Polygon* PolygonList::Get(size_t index) const{
    return _polygons[index];
}
//Adds a new polygon to the polygonlist
//param poly is copied and is attmpted to be added to the polygonlist
//returns true if successfully added the polygon to the polygonlist
bool PolygonList::Add(const Polygon& poly){
    if(!IsFull()){
        _polygons[_size++] = new Polygon(poly);
        return true;
    }
    return false;
}
//tells whether or not the polygonlist is full of polygons
//returns true of false if the polygonlist is full
bool PolygonList::IsFull()const{
    return _capacity== _size;
}
//gives the size of the polygonlist
//returns the number of polygons inside the list
size_t PolygonList::GetSize()const{
    return _size;
}

size_t PolygonList::GetCapacity()const{
    return _capacity;
}
void PolygonList::Clear(){
    _size = 0;
}
