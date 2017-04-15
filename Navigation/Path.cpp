//
//  Path.cpp
//  Navigation
//
//  Created by Danny  on 4/14/17.
//  Copyright © 2017 Danny . All rights reserved.
//

#include "Path.hpp"

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

void Path::popTop() {
    path.pop_back();
    itemCount--;
}

int Path::peekTop() {
    return path[itemCount-1];
}

vector<int> Path::getPath() {
    return path;
}
