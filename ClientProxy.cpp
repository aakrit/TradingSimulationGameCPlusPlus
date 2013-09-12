//
//  ClientProxy.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "ClientProxy.h"
#include "Broker.h"
#include "CallObject.h"
#include "Stock.h"
#include "Bond.h"
#include "MoneyMarket.h"

using namespace std;

void ClientProxy::register_b(Broker* b)
{
    clientBroker = b;
}



vector<stock::Stock*>* ClientProxy::getStockVector() const
{
    CallObject *z = clientBroker->getStockVector();
    //need to convert the string stored in Call object back to a pointer
    //convert the string back to a pointer
    void *result;
    stringstream st(z->conv);
    //store in the stringstream in a void *
    st >> result;
    //static cast from void* to vector of stock pointers
    vector<stock::Stock*>* aaa = static_cast<vector<stock::Stock*>*>(result);
//    cout << "Client Proxy       " << aaa << endl;
    return aaa;
}
vector<bond::Bond*>* ClientProxy::getBondVector() const
{
    CallObject *z = clientBroker->getBondVector();
    //need to convert the string stored in Call object back to a pointer
    //convert the string back to a pointer
    void *result;
    stringstream st(z->conv);
    //store in the stringstream in a void *
    st >> result;
    //static cast from void* to vector of stock pointers
    vector<bond::Bond*>* aaa = static_cast<vector<bond::Bond*>*>(result);
//    cout << "Client Proxy       " << aaa << endl;
    return aaa;
}
vector<mm::MoneyMarket*>* ClientProxy::getMMVector() const
{
    CallObject *z = clientBroker->getMMVector();
    //need to convert the string stored in Call object back to a pointer
    //convert the string back to a pointer
    void *result;
    stringstream st(z->conv);
    //store in the stringstream in a void *
    st >> result;
    //static cast from void* to vector of stock pointers
    vector<mm::MoneyMarket*>* aaa = static_cast<vector<mm::MoneyMarket*>*>(result);
//    cout << "Client Proxy       " << aaa << endl;
    return aaa;
}





