//
//  Stock.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesign_Lab1Deliverable__Stock__
#define __OODesign_Lab1Deliverable__Stock__

#include <iostream>
#include <string>
#include <vector>
#include "FinancialObject.h"

namespace stock
{
    //The stock class is a LEAF component of the composite pattern
    class Stock: public FinancialObject
    {
//        std::string name;
//        double value;
        
    public:
        Stock(std::string, double);
        virtual ~Stock();

        virtual double getCurrentValue();
        virtual void setBalance(double);
        virtual std::string getName();
        
    };
    
}

#endif /* defined(__OODesignFinalProject__Stock__) */
