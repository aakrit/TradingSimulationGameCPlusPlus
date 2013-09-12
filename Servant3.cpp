//
//  Servant3.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/5/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Servant3.h"

using namespace std;

Servant3* Servant3::instance = NULL;

Servant3::Servant3(){}

Servant3* Servant3::makeInstance()
{
    if(instance == NULL)
    {
        instance = new Servant3();
    }
    else
    {
        std::cout << "Error: cannot create more than one instrance of this class";
    }
    return instance;
}

int Servant3::getLength(std::string const& s)
{
    //client object passes the function to the ClientProxy expecting an int returned
    int a = static_cast<int>(s.size());
    return a;
}
vector<mm::MoneyMarket*>* Servant3::getMMVector()
{
//    cout << "MM Servant           " << vs << endl;
    return vs;
}
void Servant3::attachToFinancialList(Financial_Instrument_list *fil)
{
    vs = &fil->moneymarketList;
}

