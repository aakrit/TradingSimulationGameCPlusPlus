//
//  ServerProxy.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__ServerProxy__
#define __OODesignFinalProject__ServerProxy__

#include <iostream>
#include <vector>
class Server;
class Broker;
class CallObject;

class ServerProxy
{
    
    
public:

    static CallObject* getStockVector(Server* );
    static CallObject* getBondVector(Server* );
    static CallObject* getMMVector(Server* );

    
    
};

#endif /* defined(__OODesignFinalProject__ServerProxy__) */
