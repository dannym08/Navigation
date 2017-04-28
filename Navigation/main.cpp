//
//  main.cpp
//  Navigation
//
//  Created by Danny  on 4/11/17.
//  Copyright © 2017 Danny . All rights reserved.
//

#include <iostream>
#include "map.hpp"
#include "path.hpp"
#include "PathFinding.hpp"

#include <ctime>
#include <stdlib.h>


using namespace std;

const int oneDLength = 100;
const int twoDLength = 10;
const int resolution = 1;

int main(int argc, const char * argv[]) {
    srand((uint)time(NULL));
    int occupancyGrid[oneDLength];
   
    for (int i = 0; i < oneDLength; i++){
        int r = rand() % 100;
        //cout << i << " : " << r << endl;
        occupancyGrid[i] = r;
    }
//    
//    Map map(oneDLength, twoDLength);
//    map.updateMap(occupancyGrid);
//    map.setCurrentIndex(2);
//    map.setFinishIndex(14);
//    
//    map.printLinkedList();
//    
//    cout << "----------Path Testing-----------" << endl;
//    
//    Path path;
//
//    for (int i = 0; i < 10; i++) {
//        int r = rand() % 100;
//        path.push(r);
//    }
//    
//    while (!path.isEmpty()) {
//        cout << path.peekTop() << endl;
//        path.popTop();
//    }
    
    PathFinding pf(occupancyGrid, oneDLength, twoDLength, resolution);
    
//    pf.printLinkedList();
//    
//    cout << endl << "---------------------" << endl;
      pf.updateEnd(2);
//    pf.printLinkedList();
      pf.printMap();
    return 0;
}
