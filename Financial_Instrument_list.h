//
//  Financial_Instrument_list.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Financial_Instrument_list__
#define __OODesignFinalProject__Financial_Instrument_list__

#include <iostream>
#include <vector>
#include "Stock.h"
#include "Bond.h"
#include "MoneyMarket.h"

//class MarketMover;
class Servant;
class Servant2;
class Servant3;

class Financial_Instrument_list
{
    Servant* stockserver;
    Servant2* bondserver;
    Servant3* moneymarketserver;
    
public:
    Financial_Instrument_list();
    ~Financial_Instrument_list();
    
    
    std::vector<stock::Stock*> stockList;
    std::vector<bond::Bond*> bondList;
    std::vector<mm::MoneyMarket*> moneymarketList;
    
    void attachToStockServer(Servant*);
    void attachToBondServer(Servant2*);
    void attachToMoneyMarketServer(Servant3*);
    void printAllVectorElement();
    
};


#endif /* defined(__OODesignFinalProject__Financial_Instrument_list__) */
