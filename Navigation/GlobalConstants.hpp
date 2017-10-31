//
//  GlobalConstants.hpp
//  Navigation
//
//  Created by Danny  on 4/11/17.


/*
    Contains the global constants needed anywhere throuht the navigation package
*/

#ifndef globalConstants_hpp
#define globalConstants_hpp

// mapObjects are the possible representation of each square on the map
enum mapObject {unknown = -1, space = 0, wall = 1, currentPosition = 2, endPosition = 3, pathObj = 4, error = 9};

const int wallCutoff = 60; // (100 - wallCutoff)% of indicies being walls. Used for determining what is a wall and what isn't from an occupancy grid
#endif /* globalConstants_hpp */
