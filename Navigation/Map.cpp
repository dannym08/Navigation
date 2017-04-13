//
//  Map.cpp
//  Navigation
//
//  Created by Danny  on 4/11/17.
//  Copyright © 2017 Danny . All rights reserved.
//

#include "Map.hpp"
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
void Map::emptyInitialize() {
    Node* n;
    LinkedList* linked;
    for (int i = 0; i < oneDLength; i++) {
        n = new Node();
        linked = new LinkedList();
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
    emptyInitialize();
    emptyLink();
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
            cout << " " << n->index  << " ";
            n = n->next;
        }
        cout << endl;
    }
}