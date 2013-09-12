//
//  Robot1.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/3/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Robot1__
#define __OODesignFinalProject__Robot1__

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
//Robot invests 100% in bonds
class Robot1: public Robot
{
    std::vector<bond::Bond*>* v;
    std::vector<bond::Bond*> oldList;
    UserFacade *uf = NULL;
    
public:
    Robot1(UserFacade*);
    virtual ~Robot1();
    
    virtual void getVector();
    virtual void rearrangeVector();
    virtual void updateAccount();
    
    virtual void printAllNewandOldVectorElements();
    
};

//class SortList {
//    
//public:
//    
//    bool operator() (FinancialObject *lhs, FinancialObject *rhs);
//    
//};



#endif /* defined(__OODesignFinalProject__Robot1__) */
