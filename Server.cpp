//
//  Server.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//
#include "Stock.h"
#include "Bond.h"
#include "MoneyMarket.h"
#include "Server.h"
#include "Servant.h"
#include "Servant2.h"
#include "Servant3.h"

using namespace std;
//The Server gets an int from the Servant and returns it to the ServerProxy


void Server::addServants(Servant* s1, Servant2* s2, Servant3* s3)
{
    stockServant = s1;
    bondServant = s2;
    mmServant = s3;
}

vector<stock::Stock*>* Server::getStockVector()
{
    //a is a pointer to a vector of stock pointers
    vector<stock::Stock*>* a = stockServant->getStockVector();
//    cout << "Stock Server             " << a << endl;
    return a;
}
vector<bond::Bond*>* Server::getBondVector()
{
    //a is a pointer to a vector of stock pointers
    vector<bond::Bond*>* a = bondServant->getBondVector();
//    cout << "Bond Server             " << a << endl;
    return a;
}
vector<mm::MoneyMarket*>* Server::getMMVector()
{
    //a is a pointer to a vector of stock pointers
    vector<mm::MoneyMarket*>* a = mmServant->getMMVector();
//    cout << "MM Server             " << a << endl;
    return a;
}