//
//  PathFinding.cpp
//  Navigation
//
//  Created by Danny  on 4/14/17.
//  Copyright © 2017 Danny . All rights reserved.
//

#include "PathFinding.hpp"
#include <cmath>

///////////////////////
/* PRIVATE FUNCTIONS */
///////////////////////

void PathFinding::reorderHelper(vector<int> &vec) {
    //int highest;
    int index;
    int dis;
    int endIndex = map->getFinishIndex();
    vector<int> distancesFromEnd;
    
    for (int i = 0; i < vec.size(); i++) { // initialize end distance
        dis = abs(vec[i] - endIndex);
        distancesFromEnd.push_back(dis);
    }
    
    for (int i = 0; i < distancesFromEnd.size(); i++) {
        //highest = distancesFromEnd[i];
        index = i;
        
        for (int x = (i + 1); x < distancesFromEnd.size(); x++) {
            if (distancesFromEnd[index] < distancesFromEnd[x]) {
                //highest = distancesFromEnd[x];
                index = x;
            }
        }
        
        if (index != i) { // swap both vectors
            int temp = distancesFromEnd[i];
            distancesFromEnd[i] = distancesFromEnd[index];
            distancesFromEnd[index] = temp;
            
            temp = vec[i];
            vec[i] = vec[index];
            vec[index] = temp;
        }
    }
    
}

/* PUBLIC FUNCTIONS */

// 
PathFinding::PathFinding(int occupancyGrid[], int oneL, int twoL, float resolution){
    map = new Map(oneL, twoL);
    map->updateMap(occupancyGrid);
    this->resolution = resolution;
    solutionFound = false;
}

// reorder map based of end index
// endIndex must be set before calling reorder
void PathFinding::reorder() {
    vector<int> temp;
    int len = map->getOneDLength();
    
    for (int i = 0; i < len; i++) {
        temp = map->getAdjPaths(i);
        reorderHelper(temp);
        map->eraseAdjPaths(i, temp);
    }
}

void PathFinding::printLinkedList() {
    map->printLinkedList();
}

void PathFinding::updateEnd(int index) {
    map->setFinishIndex(index);
    reorder();
}

bool PathFinding::findPath() {
    
    return true;
}

bool PathFinding::isSolution(){
    return solutionFound;
}
