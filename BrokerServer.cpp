//
//  BrokerServer.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "CallObject.h"
#include "ClientProxy.h"
#include "ServerProxy.h"
#include "BrokerServer.h"
#include "Broker.h"
#include "Server.h"
#include <string>
#include <sstream>

using namespace std;

//Server broker takes the string from client broker, converts it to the call object and passes the call object to the server proxy
BrokerServer::BrokerServer(string const& s)
{
    name = s;
    cout << endl << "Launching \"" << name << "\"" << endl << endl;
}
void BrokerServer::registerServer(Server *s)
{
    sv = s;
}
void BrokerServer::un_registerServer(Server *s)
{
    sv = NULL;
}
string BrokerServer::getStockVector()
{
    CallObject *z = ServerProxy::getStockVector(sv);
    string ss = z->conv;
//    cout << "Broker Server      " << ss << endl;
    return ss;
}
string BrokerServer::getBondVector()
{
    CallObject *z = ServerProxy::getBondVector(sv);
    string ss = z->conv;
//    cout << "Broker Server      " << ss << endl;
    return ss;
}
string BrokerServer::getMMVector()
{
    CallObject *z = ServerProxy::getMMVector(sv);
    string ss = z->conv;
//    cout << "Broker Server      " << ss << endl;
    return ss;
}
