//
//  Path.cpp
//  Navigation
//
//  Created by Danny  on 4/14/17.
//  Copyright © 2017 Danny . All rights reserved.
//

#include "Path.hpp"
#include <iostream>

using std::cout;
using std::endl;

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
    return path[itemCount];
}

void Path::resetPath() {
    itemCount = 0;
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
