//
//  FinancialObject.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/9/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__FinancialObject__
#define __OODesignFinalProject__FinancialObject__

#include <iostream>
#include "Component.h"

class FinancialObject: public Component
{
    
protected:
    std::string name;
    double value = 0;
    
public:
    FinancialObject();
    virtual ~FinancialObject();
    
    virtual double getCurrentValue() = 0;
    virtual void setBalance(double) = 0;
    virtual std::string getName() = 0;
};

#endif /* defined(__OODesignFinalProject__FinancialObject__) */
