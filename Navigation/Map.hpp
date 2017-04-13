//
//  Map.hpp
//  Navigation
//
//  Created by Danny  on 4/11/17.
//  Copyright © 2017 Danny . All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include "GlobalConstants.hpp"
#include <vector>
#include <iostream>

using std::vector;

struct Node {
    Node* next;
    int index; //the index is points to
    mapObject item;
    
    
    Node () {
        next = nullptr;
        item = unknown;
        index = -1; // -1 = unknown
    }
    
    Node (int indexx) {
        item = unknown;
        next = nullptr;
        index = indexx;
    }
    Node(mapObject mObj) {
        item = mObj;
        next = nullptr;
        index = -1;
    }
    
    void setIndex(int i){
        index = i;
    }
    
    int getIndex() {
        return index;
    }
    //write deconstructor
};

struct LinkedList {
    Node* headPtr;
    
    LinkedList() {
        headPtr = nullptr;
    }
    
    // adds to the second place in the linked list since header has the map object info
    void add(Node* n) {
        Node* head = headPtr; //PROBLEM HERE
        if (headPtr == nullptr) {
            headPtr = n;
        } else if (head->next == nullptr) {
            headPtr->next = n;
        } else {
            Node* tempNode = headPtr->next;
            headPtr->next = n;
            n->next = tempNode;
        }

    }
    //write deconstructor
};

class Map {
    private:
        vector<LinkedList*> map;
        int startIndex;
        int endIndex;
        int oneDLength; // *STARTS FROM ONE* one dimensonal array length (number of squares in occupancyGrid)
        int twoDLength; // *STARTS FROM ONE* two dimensonal length (just length or width since its a square map)
        void emptyInitialize(); // Creates empty node on top of
        void emptyLink(); // links node to surrounding node (call after emptyInitialize
        int twoToOneD(int row, int collum);
        void oneToTwoD(int a, int& row, int &collum); // will return values in x and y
        //Node* getLastNode(int linkedListIndex);
    public:
        // Map();
        Map(int oLength, int tLength); // 1D and 2D length
        Map(int occupancyGrid, int oLength, int tLength);
        //~Map();
        void updateMap(int occupancyGird);
    
    
        // set and get functions
        void setStart(int start);
        int getStaart();
        void setFinish(int finish);
        int getFinish();
        void setNodeObject(mapObject mObj);
        mapObject getNodeObject();
    
        // functions for testing
        void printMap();
        void printLinkedList();
    
    
};

#endif /* Map_hpp */
