//
//  Robot2.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/3/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Robot2__
#define __OODesignFinalProject__Robot2__

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

//robot2 invest 70% in bonds and 30% in moneymarket
class Robot2: public Robot
{
    
    std::vector<bond::Bond*>* v;
    std::vector<mm::MoneyMarket*>* m;
    
    std::vector<mm::MoneyMarket*> mmList;
    std::vector<bond::Bond*> bondList;
    
    UserFacade *uf = NULL;
    
public:
    Robot2(UserFacade*);
    virtual ~Robot2();
    
    virtual void getVector();
    virtual void rearrangeVector();
    virtual void updateAccount();
    
    virtual void printAllNewandOldVectorElements();

};
#endif /* defined(__OODesignFinalProject__Robot2__) */
