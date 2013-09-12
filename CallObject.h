//
//  CallObject.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__CallObject__
#define __OODesignFinalProject__CallObject__

#include <iostream>
#include <vector>
#include <sstream>

class Stock;

struct CallObject
{
    int val1 = 0;
    int val2 = 0;
    std::string conv;
    int stringret = 0;
    
    std::vector<Stock*>* vs;
    //std::stringstream sst;
    
    CallObject(int const&);
    CallObject(int const&, int const&);
    CallObject(std::string const&);
    CallObject(std::vector<Stock*>*);
    CallObject(std::stringstream);
};


//I was orginally going to implements the call objects as a template since that woud be more practical here and only require 2 overloaded constructors but since it was mentioned in the assignment that we should have data passed at runtime and templates are compiled at staticlink time i'm not using this here for the Call object
template<class T>
struct CallObjectTemplate
{
    T val1 = 0;
    T val2 = 0;
    T conv;
    T stringret = 0;
    
    CallObjectTemplate(T value)
    {
        conv = value;
        stringret = value;
    }
    CallObjectTemplate(T value1, T value2)
    {
        val1 = value1;
        val2 = value2;
    }
};

#endif /* defined(__OODesignFinalProject__CallObject__) */
