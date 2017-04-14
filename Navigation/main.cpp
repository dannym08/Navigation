//
//  main.cpp
//  Navigation
//
//  Created by Danny  on 4/11/17.
//  Copyright © 2017 Danny . All rights reserved.
//

#include <iostream>
#include "map.hpp"

using namespace std;

const int oneDLength = 16;
const int twoDLength = 4;

int main(int argc, const char * argv[]) {
    int occupancyGrid[oneDLength];
    
    for (int i = 0; i < oneDLength; i++){
        occupancyGrid[i] = 100;
    }
    Map map(oneDLength, twoDLength);
    map.updateMap(occupancyGrid);
    map.setCurrentIndex(2);
    map.setFinishIndex(14);
    
    map.printLinkedList();
    
    return 0;
}
