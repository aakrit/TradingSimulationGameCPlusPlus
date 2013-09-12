//
//  Robot5.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/3/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Robot5__
#define __OODesignFinalProject__Robot5__

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
//RL5Robot:20% stocks, 60% mm, 20%bonds
class Robot5: public Robot
{
    
    std::vector<stock::Stock*>* v;
    std::vector<mm::MoneyMarket*>* m;
    std::vector<bond::Bond*>* b;

    std::vector<mm::MoneyMarket*> mmList;
    std::vector<stock::Stock*> stockList;
    std::vector<bond::Bond*> bondList;

    UserFacade *uf = NULL;
    
public:
    Robot5(UserFacade*);
    virtual ~Robot5();
    
    virtual void getVector();
    virtual void rearrangeVector();
    virtual void updateAccount();
    
    virtual void printAllNewandOldVectorElements();

};
#endif /* defined(__OODesignFinalProject__Robot5__) */
