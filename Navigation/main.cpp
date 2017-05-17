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

const int oneDLength = 225; // LONGER ONE
const int twoDLength = 15; // SHORTER ONE
const float resolution = .4;

int main(int argc, const char* argv[]) {
    srand((uint)time(NULL)); // NULL gives current time as a seed
    int occupancyGrid[oneDLength];
    
    int r = 0;
    for (int i = 0; i < oneDLength; i++){
        r = rand() % 100;
        //cout << i << " : " << r << endl;
        
        occupancyGrid[i] = r;
    }
    //occupancyGrid[11] = 100; // wall
    
    PathFinding pf(occupancyGrid, oneDLength, twoDLength, resolution);
    
    pf.setCurrentIndex(6);
    pf.setEnd(210);
    pf.printIndex();
    pf.findPath();
    //pf.setPathOnMap();
    pf.printMap();
    
    

    pf.printPath();
    cout << "Distance(m) is " << pf.calcDistance() << endl;
    
    
    return 0;
}
