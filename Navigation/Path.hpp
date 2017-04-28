//
//  Path.hpp
//  Navigation
//
//  Created by Danny  on 4/14/17.
//  Copyright © 2017 Danny . All rights reserved.
//

#ifndef Path_hpp
#define Path_hpp

#include <vector>

using std::vector;

class Path{
    private:
        vector<int> path;
        int itemCount;
public:
        Path();
    
        /*stack functions*/
    
        bool isEmpty();
        void push(int newEntry); // adds to end
        void popTop(); // takes off top
        int peekTop(); // looks at the last item
    
        vector<int> getPath(); // use this to get path once path complete
    
};

#endif /* Path_hpp */