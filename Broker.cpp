//
//  Broker.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "CallObject.h"
#include "ClientProxy.h"
#include "ServerProxy.h"
#include "Broker.h"
#include "BrokerServer.h"
#include "string.h"
#include <sstream>

using namespace std;

//Client Broker converts callobject pointer to string and passes the information to the server broker

void Broker::registerServerBroker(BrokerServer* bs)
{
    //store memeory of server broker object
    lab2server = bs->name;
    lab2serverbroker = bs;
    pair<string,BrokerServer*> server (bs->name,bs);
    serverBrokers.insert(server);
}


CallObject* Broker::getStockVector()
{
    BrokerServer *b = NULL;
    try
    {
        for (auto& a : serverBrokers)
        {
            if (a.first != lab2server) {
                continue;
            }else
            {
                b = a.second;
            }
        }
    } catch (exception e)
    {
        cout << e.what() << endl;
    }
    if (b == NULL)
    {
        cout << "Unable to locate Server Broker" << endl;
    }
    string s = lab2serverbroker->getStockVector();
    //convert stringstream to string
    CallObject *a = new CallObject(s);
    //store string in call object : a->conv
//    cout << "Client Broker      " << a->conv << endl;
    return a;
}
CallObject* Broker::getBondVector()
{
    BrokerServer *b = NULL;
    try
    {
        for (auto& a : serverBrokers)
        {
            if (a.first != lab2server) {
                continue;
            }else
            {
                b = a.second;
            }
        }
    } catch (exception e)
    {
        cout << e.what() << endl;
    }
    if (b == NULL)
    {
        cout << "Unable to locate Server Broker" << endl;
    }
    string s = lab2serverbroker->getBondVector();
    //convert stringstream to string
    CallObject *a = new CallObject(s);
    //store string in call object : a->conv
//    cout << "Client Broker      " << a->conv << endl;
    return a;
}
CallObject* Broker::getMMVector()
{
    BrokerServer *b = NULL;
    try
    {
        for (auto& a : serverBrokers)
        {
            if (a.first != lab2server) {
                continue;
            }else
            {
                b = a.second;
            }
        }
    } catch (exception e)
    {
        cout << e.what() << endl;
    }
    if (b == NULL)
    {
        cout << "Unable to locate Server Broker" << endl;
    }
    string s = lab2serverbroker->getMMVector();
    //convert stringstream to string
    CallObject *a = new CallObject(s);
    //store string in call object : a->conv
//    cout << "Client Broker      " << a->conv << endl;
    return a;
}
