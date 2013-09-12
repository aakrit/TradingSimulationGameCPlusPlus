//
//  Client.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Client__
#define __OODesignFinalProject__Client__

#include <iostream>
#include <vector>

#include "Client_ClientProxy_Interface.h"

namespace bond{
    class Bond;
}
namespace stock {
    class Stock;
}
namespace mm {
    class MoneyMarket;
}
class ClientProxy;

class Client: public Client_ClientProxy_Interface
{
    //std::string name = NULL;
    //I would ideally store the object reference information in a container, like hash map but it wasn't specified in the scope of the assignemnt, it would be to hard to implement but for the sake of simplicity i left it out here
    ClientProxy* cpused;
    
public:
    Client(ClientProxy*);
    ~Client();
    
    //the client gets a pointer to any list via the broker pattern
    virtual std::vector<stock::Stock*>* getStockVector() const;
    virtual std::vector<bond::Bond*>* getBondVector() const;
    virtual std::vector<mm::MoneyMarket*>* getMMVector() const;

    
    
};
#endif /* defined(__OODesignFinalProject__Client__) */
