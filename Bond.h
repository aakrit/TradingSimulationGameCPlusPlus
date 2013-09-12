//
//  Bond.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Bond__
#define __OODesignFinalProject__Bond__

#include <iostream>
#include <ctime>
#include <cmath>
#include "FinancialObject.h"


namespace bond
{
    //The MoneyMarket class is a LEAF component of the composite pattern
    class Bond: public FinancialObject
    {

//        std::string name;
//        double value;
        
    public:
        Bond(std::string, double);
        virtual ~Bond();
        
        virtual double getCurrentValue();
        virtual void setBalance(double);
        virtual std::string getName();
    };
    
}
#endif /* defined(__OODesignFinalProject__Bond__) */
