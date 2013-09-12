//
//  Client_ClientProxy_Interface.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/5/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Client_ClientProxy_Interface__
#define __OODesignFinalProject__Client_ClientProxy_Interface__

#include <iostream>
#include <vector>
#include "Stock.h"
#include "Bond.h"
#include "MoneyMarket.h"


class Client_ClientProxy_Interface
{
    
public:
    
    virtual std::vector<stock::Stock*>* getStockVector() const = 0;
    virtual std::vector<bond::Bond*>* getBondVector() const = 0;
    virtual std::vector<mm::MoneyMarket*>* getMMVector() const = 0;
    
};



#endif /* defined(__OODesignFinalProject__Client_ClientProxy_Interface__) */
