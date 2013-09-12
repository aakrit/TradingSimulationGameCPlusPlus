//
//  Robot8.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/3/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Robot8__
#define __OODesignFinalProject__Robot8__

#include <iostream>
#include <vector>
#include "Robot.h"

class SortFinancialObjectVectorASC;
class FinancialObject;
class UserFacade;
namespace bond{
    class Bond;
}
namespace stock {
    class Stock;
}
namespace mm {
    class MoneyMarket;
}

//Robot8 invest 100% in stocks
class Robot8: public Robot
{
    std::vector<stock::Stock*>* v;
    std::vector<stock::Stock*> oldList;
    UserFacade *uf;
    
public:
    Robot8(UserFacade*);
    virtual ~Robot8();
    
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
#endif /* defined(__OODesignFinalProject__Robot8__) */
