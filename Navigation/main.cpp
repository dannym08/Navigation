//
//  main.cpp
//  Navigation
//
//  Created by Danny  on 4/11/17.


/* 
    Example use of the navigation package. It will make a map thats twoDLength by twoDLength and it sets the starting index with the function setCurrentIndex and sets the end with setEnd. Then it will find a path and display that index on the map it prints out.
*/
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
    for (int i = 0; i < oneDLength; i++){ // function that randimizes the percent there is a wall for each map slot
        r = rand() % 100;
        //cout << i << " : " << r << endl;
        
        occupancyGrid[i] = r;
    }
    
    
    PathFinding pf(occupancyGrid, oneDLength, twoDLength, resolution);
    
    pf.setCurrentIndex(6);
    pf.setEnd(210);
    pf.printIndex();
    pf.findPath();
    pf.setPathOnMap(); // sets the map objects to path objet on the map it prints out on the terminal
    pf.printMap();
    
    

    pf.printPath();
    
    
    return 0;
}
