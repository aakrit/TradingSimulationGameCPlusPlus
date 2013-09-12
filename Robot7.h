//
//  Robot7.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/3/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Robot7__
#define __OODesignFinalProject__Robot7__

#include <iostream>
#include <vector>
#include <algorithm>
#include "Robot.h"
#include "UserFacade.h"

class SortFinancialObjectVectorASC;
class FinancialObject;

namespace bond{
    class Bond;
}
namespace stock {
    class Stock;
}
namespace mm {
    class MoneyMarket;
}
//RL7Robot:70% stocks, 30% mm
class Robot7: public Robot
{
    
    std::vector<stock::Stock*>* v;
    std::vector<mm::MoneyMarket*>* m;
    
    std::vector<mm::MoneyMarket*> mmList;
    std::vector<stock::Stock*> stockList;
    
    UserFacade *uf = NULL;
    
public:
    Robot7(UserFacade*);
    virtual ~Robot7();
    
    virtual void getVector();
    virtual void rearrangeVector();
    virtual void updateAccount();
    
    virtual void printAllNewandOldVectorElements();
    
};
#endif /* defined(__OODesignFinalProject__Robot7__) */
