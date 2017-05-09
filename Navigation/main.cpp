//
//  main.cpp
//  Navigation
//
//  Created by Danny  on 4/11/17.
//  Copyright © 2017 Danny . All rights reserved.
//

#include <iostream> // for testing and printing to terminal
#include "map.hpp"
#include "path.hpp"
#include "PathFinding.hpp"

#include <ctime> // for rand
#include <stdlib.h> // for rand


using namespace std;

const int oneDLength = 25;
const int twoDLength = 5;
const float resolution = .4;

int main(int argc, const char* argv[]) {
    //srand((uint)time(NULL)); // NULL gives current time as a seed
    int occupancyGrid[oneDLength];
    
   int r = 0;
    for (int i = 0; i < oneDLength; i++){
//        int r = rand() % 100;
//        cout << i << " : " << r << endl;
        
        occupancyGrid[i] = r;
    }
    
    PathFinding pf(occupancyGrid, oneDLength, twoDLength, resolution);
    
    
    pf.setCurrentIndex(6);
    pf.setEnd(22);
    pf.printIndex();
    pf.findPath();
    //pf.setPathOnMap();
    pf.printMap();
    
    
//    vector<int> path = pf.getPath();
//    
//    cout << "Size: " << path.size() << endl;
    
//    cout << "Printing path" << endl;
//    cout << "-------------" << endl;
//    for (int i = 0; i < path.size(); i++) {
//        cout << path[i];
//        if (i != path.size() - 1)
//            cout << " -> ";
//    }
//    cout << endl;
    pf.printPath();
    cout << "Distance(m) is " << pf.calcDistance() << endl;
    
    
    return 0;
}
