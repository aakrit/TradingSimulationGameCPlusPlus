//
//  ServerProxy.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "ServerProxy.h"
#include "Server.h"
#include "Broker.h"
#include "CallObject.h"
#include "Stock.h"

using namespace std;
//The server proxy takes a callobject from the broker server and calls on a server function
//ServerProxy gets an int from the Server and converts it to the call object and passes it back to the Server Broker


CallObject* ServerProxy::getStockVector(Server* sv)
{
    vector<stock::Stock*>* vs = sv->getStockVector();
    //convert pointer to void*
    const void *ad = static_cast<const void*>(vs);
    std::stringstream ss;
    //store pointer in stringstream
    ss << ad;
    string ds = ss.str();
    CallObject *a = new CallObject(ds);
//    cout << "Server Proxy       " << a->conv << endl;
    return a;
}
CallObject* ServerProxy::getBondVector(Server* sv)
{
    vector<bond::Bond*>* vs = sv->getBondVector();
    //convert pointer to void*
    const void *ad = static_cast<const void*>(vs);
    std::stringstream ss;
    //store pointer in stringstream
    ss << ad;
    string ds = ss.str();
    CallObject *a = new CallObject(ds);
//    cout << "Server Proxy       " << a->conv << endl;
    return a;
}
CallObject* ServerProxy::getMMVector(Server* sv)
{
    vector<mm::MoneyMarket*>* vs = sv->getMMVector();
    //convert pointer to void*
    const void *ad = static_cast<const void*>(vs);
    std::stringstream ss;
    //store pointer in stringstream
    ss << ad;
    string ds = ss.str();
    CallObject *a = new CallObject(ds);
//    cout << "Server Proxy       " << a->conv << endl;
    return a;
}