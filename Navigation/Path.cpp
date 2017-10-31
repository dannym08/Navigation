//
//  Path.cpp
//  Navigation
//
//  Created by Danny  on 4/14/17.

#include "Path.hpp"
#include <iostream>

using std::cout;
using std::endl;

// The path class is an object that represents the and keeps track of the path the navigation says to take


Path::Path() {
    itemCount = 0;
}

bool Path::isEmpty() {
    return (itemCount == 0);
}

void Path::push(int newEntry) {
    path.push_back(newEntry);
    itemCount++;
}

void Path::pop() {
    path.pop_back();
    itemCount--;
}

int Path::peek() {
    return path[itemCount - 1];
}

void Path::resetPath() {
    itemCount = 0;
}

int Path::getSize() {
    return itemCount;
}

//////////////////
// TEST FUNCTION//
//////////////////

void Path::printPath() {
    cout << "Printing path" << endl;
    cout << "-------------" << endl;
    cout << "Path size is: " << itemCount << endl;
    
    for (int i = 0; i < itemCount; i++){

        cout << path[i];
        
        if (i != itemCount - 1)
            cout << " -> ";
    }
    cout << endl;
}

vector<int> Path::getPath() {
    return path;
}
