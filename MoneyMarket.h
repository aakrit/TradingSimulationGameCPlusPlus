//
//  MoneyMarket.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/5/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__MoneyMarket__
#define __OODesignFinalProject__MoneyMarket__

#include <iostream>
#include <ctime>
#include <cmath>
#include "FinancialObject.h"

namespace mm
{
    //The MoneyMarket class is a LEAF component of the composite pattern
    class MoneyMarket: public FinancialObject
    {

//        std::string name;
//        double value;
    public:
        MoneyMarket(std::string, double);
        virtual ~MoneyMarket();
        
        virtual double getCurrentValue();
        virtual void setBalance(double);
        virtual std::string getName();

    };
    
}
#endif /* defined(__OODesignFinalProject__MoneyMarket__) */
