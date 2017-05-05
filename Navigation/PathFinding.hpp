//
//  PathFinding.hpp
//  Navigation
//
//  Created by Danny  on 4/14/17.
//  Copyright © 2017 Danny . All rights reserved.
//

#ifndef PathFinding_hpp
#define PathFinding_hpp

#include "Path.hpp"
#include "Map.hpp"
#include "GlobalConstants.hpp"

class PathFinding {
    private:
        Map* map; //**MAKE SURE NO MEMEORY LEAKS**
        Path path;
        float resolution; // the size of each cell within the map (in meters)
        bool solutionFound;
        void reorderHelper(vector<int> &vec); // reorder linked list based off distance to end
        vector<bool> visited;
    public:
        //PathFinding();
        //PathFinding(int occupancayGrid);
        PathFinding(int occupancyGrid[], int oneL, int twoL, float resolution);// One dimensional length, two dimensional length
        bool findPath();
        void setPathOnMap();
        void reorder(); // change links based off distance for shorest distance (end index must be set)
        bool isSolution();
        void clearVisited();
        void updateMap(int occupancyGird[]);
    
        void setOneDLength(int oneD);
        int getOneDLength();
        void setEnd(int index); // called by UI node
        void setCurrentIndex(int index);
        void setTwoDLength(int twoD);
        int getTwoDLength();
    
        //TEST FUNCTIONS
        void printLinkedList();
        void printMap();
        vector<int> getPath();
    
};

#endif /* PathFinding_hpp */
