//
//  MarketMaker.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/9/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__MarketMaker__
#define __OODesignFinalProject__MarketMaker__

#include <iostream>

class Financial_Instrument_list;

class MarketMaker
{
    Financial_Instrument_list* fil;
    
    std::string marketCondition;
    
    double bondLow = 0.8;
    double bondHigh = 1.2;
    double mmLow = 0.6;
    double mmHigh = 1.4;
    double stockLow = 0.4;
    double stockHigh = 1.6;
    
public:
    MarketMaker(Financial_Instrument_list*);
    virtual ~MarketMaker();
    void updateFinancialObjects();
    double PercentPriceChange(double, double);
    
    void initializeMarket();
    std::string getMarketCondition();

};


#endif /* defined(__OODesignFinalProject__MarketMaker__) */
