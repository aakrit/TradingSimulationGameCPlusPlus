//
//  Client.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Client.h"
#include "ClientProxy.h"
#include "Bond.h"
#include "Stock.h"
#include "MoneyMarket.h"

using namespace std;

Client::~Client()
{
    //std::cout << "Destroying Client Ending Program" << std::endl;
}

Client::Client(ClientProxy* cp)
{
    //std::cout << "Creating Client" << std::endl;
    cpused = cp;
}


vector<stock::Stock*>* Client::getStockVector() const
{
    vector<stock::Stock*>* vs = cpused->getStockVector();
//    cout << "Stock Client             " << vs << endl;
    return vs;
}

vector<bond::Bond*>* Client::getBondVector() const
{
    vector<bond::Bond*>* vs = cpused->getBondVector();
//    cout << "Bond Client             " << vs << endl;
    return vs;
}

vector<mm::MoneyMarket*>* Client::getMMVector() const
{
    vector<mm::MoneyMarket*>* vs = cpused->getMMVector();
//    cout << "MM Client             " << vs << endl;
    return vs;
}