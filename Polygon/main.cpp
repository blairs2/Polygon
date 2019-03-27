// Extra Credit
//  main.cpp
//  Polygon
//
//  Created by Stone Blair on 12/4/18.
//  Copyright © 2018 Stone Blair. All rights reserved.
//
//

// Input files must be in this format
//3             new Polygon with 3 points
//3 5           p1
//2 7           p2
//9 8           p3
//6             New polygon with 6 points (The 6 points following)
//3 5
//2 7
//9 8
//3 5
//2 7
//9 8
//4
//2 2
//3 3
//1 1
//0 0

#include <iostream>
#include "Point.h"
#include "Polygon.h"
#include "PolygonList.h"
#include <iomanip>
#include <sstream>
using std::stringstream;
using namespace std;

int main(int argc, const char * argv[]) {
    bool repeat = true;
    int option, numPolygons;
    string file;
    cout << "Number of polygons to hold in list: "<< endl;
    cin >> numPolygons;
    PolygonList polygons(numPolygons);
    
    cout<< "1. Load\n2. Save\n3. List\n4. Add\n5. Calculate\n6. Exit\n7. Clear\n=============="<< endl;
    cin >> option;
    while(repeat){
        
        if(option == 1){
            cout << "Input file name: ";
            cin >> file;
            ifstream input(file);
            if(input.fail()){
                cerr << "Error -- couldn't open file.";
                exit(1);
            }
            cout << polygons.Read(input) << " polygons loaded."<< endl;
            input.close();
        }
        else if(option ==2){
            cout << "Output file name: ";
            cin >> file;
            ofstream out(file);
            if(out.fail()){
                cerr << "Error -- couldn't open file.";
                exit(1);
            }

            cout << polygons.Write( out) << " polygons saved";
            cout<< endl;
            out.close();


        }
        else if(option ==3){
            cout << "polygons =============\n"<< endl;
            polygons.Write( cout);

        }
        else if(option ==4){
            if(!polygons.IsFull()){
                cout << "Unsuccessfull. List is full."<< endl;
            }else {
                int pointsInPolygon, x,y;
                cout<< "How many points:";
                cin >> pointsInPolygon;
                Polygon p(pointsInPolygon);
                for(int i = 0; i < pointsInPolygon; i++){
                    cout << "P" << i+1<< ": ";
                    cin >> x >> y;
                    p.Add(x,y);
                }

                if(polygons.Add(p)){
                    cout << "Successfully added polygon"<< endl;
                }
            }
        }
        else if(option ==5){
            for(int i = 0; i < polygons.GetSize(); i++){
                cout << "Polygon" << i+1 << endl;
                cout << "Area: " << polygons.Get(i)->GetArea() << endl;
                cout << "Perimeter: " << polygons.Get(i)->GetPerimeter() << endl;
            }

        } else if(option ==6){
            char changeSize;
            size_t newSize;
            polygons.Clear();
            // Just for Fun
            //-----------
            cout << "Do you want to change size of polygon list (y/n): ";
            cin >> changeSize;
            if(toupper(changeSize)=='Y'){
                cout << "New size: ";
                cin >> newSize;
                polygons = PolygonList(newSize);
                cout << "PolygonList size changed to "<< polygons.GetCapacity() << endl;
            }
            //-------------repeat = false;
        }
        else if(option ==7){
            repeat = false;
        }
        else{
            cout << "Not valid option -- Try again." << endl;
        }

        cout<< "1. Load\n2. Save\n3. List\n4. Add\n5. Calculate\n6. Exit\n\n7. Clear=============="<< endl;
        cin >> option;
    }

    return 0;
}
