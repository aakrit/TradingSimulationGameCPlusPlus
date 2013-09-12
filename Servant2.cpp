//
//  Servant2.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Servant2.h"

using namespace std;

Servant2* Servant2::instance = NULL;

Servant2::Servant2(){}

Servant2* Servant2::makeInstance()
{
    if(instance == NULL)
    {
        instance = new Servant2();
    }
    else
    {
        std::cout << "Error: cannot create more than one instrance of this class";
    }
    return instance;
}

vector<bond::Bond*>* Servant2::getBondVector()
{
//    cout << "Bond Servant           " << vs << endl;
    return vs;
}
void Servant2::attachToFinancialList(Financial_Instrument_list *fil)
{
    vs = &fil->bondList;
}