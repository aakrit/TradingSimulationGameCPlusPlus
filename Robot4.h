//
//  Robot4.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/3/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Robot4__
#define __OODesignFinalProject__Robot4__

#include <iostream>
#include <vector>
#include <algorithm>
#include "Robot.h"
#include "UserFacade.h"

class SortFinancialObjectVectorASC;
class SortFinancialObjectVectorDSC;
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
//RL4Robot:20% bonds, 60% mm, 20%stock
class Robot4: public Robot
{
    
    std::vector<stock::Stock*>* v;
    std::vector<mm::MoneyMarket*>* m;
    std::vector<bond::Bond*>* b;
    
    std::vector<mm::MoneyMarket*> mmList;
    std::vector<stock::Stock*> stockList;
    std::vector<bond::Bond*> bondList;
    
    UserFacade *uf = NULL;
    
public:
    Robot4(UserFacade*);
    virtual ~Robot4();
    
    virtual void getVector();
    virtual void rearrangeVector();
    virtual void updateAccount();
    
    virtual void printAllNewandOldVectorElements();

};
#endif /* defined(__OODesignFinalProject__Robot4__) */
