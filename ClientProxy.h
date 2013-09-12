//
//  ClientProxy.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__ClientProxy__
#define __OODesignFinalProject__ClientProxy__


#include <iostream>
#include <vector>
#include <sstream>
#include "Client_ClientProxy_Interface.h"

class Broker;
class CallObject;
namespace bond{
    class Bond;
}
namespace stock {
    class Stock;
}
namespace mm {
    class MoneyMarket;
}
class ClientProxy: public Client_ClientProxy_Interface
{
    //I would ideally store the object reference information in a container, like hash map but it wasn't specified in the scope of the assignemnt, it would be to hard to implement but for the sake of simplicity i left it out here
    Broker* clientBroker;
    
public:

    void register_b(Broker*);
    
    virtual std::vector<stock::Stock*>* getStockVector() const;
    virtual std::vector<bond::Bond*>* getBondVector() const;
    virtual std::vector<mm::MoneyMarket*>* getMMVector() const;


};

//create a callobject to convert the client function parameters into common IDL type format
#endif /* defined(__OODesignFinalProject__ClientProxy__) */
