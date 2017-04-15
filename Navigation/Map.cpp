//
//  Map.cpp
//  Navigation
//
//  Created by Danny  on 4/11/17.
//  Copyright © 2017 Danny . All rights reserved.
//

#include "Map.hpp"
//#include "GlobalConstants.hpp"
#include <iostream>

using std::endl;
using std::cout;

//////////////////////
/* PRIVATE FUNCTIONS*/
//////////////////////

// assumes oneDLength and twoDLength is set
// row and collum start at 0
int Map::twoToOneD(int row, int collum) {
    int a = (row * twoDLength) + collum;
    return a;
}

// assumes oneDLength and twoDLength is set
// row and collum start at zero
void Map::oneToTwoD(int a, int& row, int& collum) {
    row = a / twoDLength; //sets row number
    collum = a % twoDLength; //sets collum number
}

//Node* Map::getLastNode(int linkedListIndex) {
//    Node* n = map[linkedListIndex]->headPtr;
//    
//    if (n == nullptr) { // this should not happen
//        n = new Node(error);
//        return n;
//    }
//    while (n->next != nullptr) {
//        n = n->next;
//    }
//    
//    return n;
//}

// assumes oneDLength and twoDLength is set
// assumes length is above 9
// top left corner case
void Map::initialize(vector<mapObject> vec) {
    Node* n;
    LinkedList* linked;
    mapObject m = unknown;
        
    for (int i = 0; i < oneDLength; i++) {
        
        if (vec.size() > 0)
            m = vec[i];
        
        n = new Node(m);
        n->setIndex(i);
        linked = new LinkedList();
        linked->add(n);
        map.push_back(linked);
    }
}

// call after emptyInitialize
// has 9 different casses
void Map::emptyLink() {
    Node* a;
    Node* b;
    Node* c;
    Node* d;
    for (int i = 0; i < oneDLength; i++) {
        LinkedList* n  = map[i]; //the current linked list
        if (i == 0) { // top-left corner case
            a = new Node(i + 1); // right node
            n->add(a);
            b = new Node(twoDLength); //node udner
            n->add(b);
        } else if (i == (twoDLength - 1)) { // top-right corner case
            a = new Node(i - 1); // left node
            n->add(a);
            b = new Node(i + twoDLength); // node under
            n->add(b);
        } else if (i == twoToOneD(twoDLength - 1, 0)) { //bottem-left corner case
            a = new Node(twoToOneD(twoDLength - 2 , 0)); // node above
            n->add(a);
            b = new Node(i + 1); // right node
            n->add(b);
        } else if (i == twoToOneD(twoDLength - 1, twoDLength - 1)) { // bottem-right corner case
            a = new Node(i - 1); // left node
            n->add(a);
            b = new Node(i - twoDLength); // node above
            n->add(b);
        } else if (i > 0 && i < twoDLength) { //top row (excluding corners)
            a = new Node (i - 1); //node to its left
            n->add(a);
            b = new Node(i + 1); // node to its right
            n->add(b);
            c = new Node(i + twoDLength); // node under it
            n->add(c);
        } else if (i > twoToOneD(twoDLength - 1, 0) && i < twoToOneD(twoDLength - 1, twoDLength - 1)) { // bottem row (excluding corners)
            a = new Node (i - 1); //node to its left
            n->add(a);
            b = new Node(i + 1); // node to its right
            n->add(b);
            c = new Node(i - twoDLength); // node on top
            n->add(c);
        } else if (i % twoDLength == 0) { // leftmost collum (but corners since corners will be caught first)
            a = new Node(i - twoDLength); // node above
            n->add(a);
            b = new Node(i + twoDLength); // node under
            n->add(b);
            c = new Node(i + 1); // right node
            n->add(c);
        } else if (i % twoDLength == (twoDLength - 1)) { // rightmost collum
            a = new Node(i - twoDLength);
            n->add(a);
            b = new Node(i + twoDLength);
            n->add(b);
            c = new Node(i - 1);
            n->add(c);
        } else { //all the rest(middle bunch)
            a = new Node(i -twoDLength); // top node
            n->add(a);
            b = new Node(i + twoDLength); // bottom node
            n->add(b);
            c = new Node(i - 1); // left node
            n->add(c);
            d = new Node(i + 1); // right node
            n->add(d);
        }
    }
}

/////////////////////
/* PUBLIC FUNCTION */
/////////////////////

Map::Map(int oLength, int tLength) {
    oneDLength = oLength;
    twoDLength = tLength;
    vector<mapObject> vec;
    initialize(vec);
    emptyLink();
}

void Map::updateMap(int occupancyGrid[]) {
    
    for (int i = 0; i < oneDLength; i++) {
        if (occupancyGrid[i] == -1)
            map[i]->headPtr->item = unknown;
        else if (occupancyGrid[i] < 50)
             map[i]->headPtr->item = space;
        else if (occupancyGrid[i] >= 50)
             map[i]->headPtr->item = wall;
        else
            map[i]->headPtr->item = error;
    }
}

vector<int> Map::getAdjPaths(int index) {
    vector<int> vec;
    Node* node = map[index]->headPtr;
    
    if (node == nullptr){
        return vec;
    }
    
    node = node->next;
    
    while (node!= nullptr) {
        vec.push_back(node->index);
        node = node -> next;
    }
    
    return vec;
}

// erase & set adj path
void Map::eraseAdjPaths(int index, vector<int> vec) {
    map[index]->clear();
    
//    Node* n = map[index]->headPtr;
//    std::cout << "Test" << std::endl;
//    while (n != nullptr){
//        std::cout << "1" << std::endl;
//    }
    
    Node* temp;
    for (int i = 0; i < vec.size(); i++) {
        temp = new Node(vec[i]);
        temp->next = nullptr;
        map[index]->add(temp);
    }
}

void Map::setCurrentIndex(int current) {
    currentIndex = current;
    map[currentIndex]->headPtr->item = currentPosition;
}

int Map::getCurrentIndex() {
    return currentPosition;
}

void Map::setFinishIndex(int finish) {
    endIndex = finish;
    map[endIndex]->headPtr->item = endPosition;
}

int Map::getFinishIndex() {
    return endIndex;
}

int Map::getOneDLength() {
    return oneDLength;
}

void Map::setOneDLength(int one){
    oneDLength = one;
}

int Map::getTwoDLength() {
    return twoDLength;
}

void Map::setTwoDLength(int two) {
    twoDLength = two;
}

mapObject Map::getMapObject(int index) {
    return (map[index]->headPtr->item);
}


/////////////////////
/* Test Functions */
/////////////////////



void Map::printLinkedList() {
    Node* n;
    for (int i = 0; i < oneDLength; i++) {
        n = map[i]->headPtr;
        cout << "Index " << i << ": ";
        while (n != nullptr) {
            cout << " " << n->index  << "(" << n->item << ")" << " "; // prints out index and and mapObject
            n = n->next;
        }
        cout << endl;
    }
}
