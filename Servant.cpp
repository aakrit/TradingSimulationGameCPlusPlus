//
//  Servant.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Servant.h"
//#include "Stock.h"

using namespace std;

Servant* Servant::instance = NULL;

Servant::Servant(){}

Servant* Servant::makeInstance()
{
    if(instance == NULL)
    {
        instance = new Servant();
    }
    else
    {
        std::cout << "Error: cannot create more than one instrance of this class";
    }
    return instance;
}

vector<stock::Stock*>* Servant::getStockVector()
{
//    cout << "Stock Servant           " << vs << endl;
    return vs;
}
void Servant::attachToFinancialList(Financial_Instrument_list *fil)
{
    vs = &fil->stockList;
}