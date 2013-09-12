//
//  CallObject.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "CallObject.h"
#include "Stock.h"

using namespace std;

CallObject::CallObject(int const& i, int const& j)
{
    val1 = i;
    val2 = j;
}

CallObject::CallObject(int const& z)
{
    stringret =z;
    //std::cout << "Creating Call Object" << std::endl;
}

CallObject::CallObject(string const& s)
{
    conv = s;
    //std::cout << "Creating Call Object" << std::endl;
}

CallObject::CallObject(vector<Stock*>* vss)
{
    vs = vss;
}


CallObject::CallObject(stringstream st)
{
    conv = st.str();
}