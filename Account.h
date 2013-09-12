//
//  Account.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/6/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Account__
#define __OODesignFinalProject__Account__

#include <iostream>
#include <vector>
#include "Component.h"

class PricingVisitor;
namespace bond{
    class Bond;
}
namespace stock {
    class Stock;
}
namespace mm {
    class MoneyMarket;
}
class Account: public Component
{
    int period = 0;
    std::vector<bond::Bond*> bondAccountList;
    std::vector<stock::Stock*> stockAccountList;
    std::vector<mm::MoneyMarket*> mmAccountList;

    double totalAccountValue = 0;
    double investedAmount = 0;
    
    double updatedTotalAccountValue = 0;
    double updatedInvestedAmount = 0;
    
    std::string moneyLostOrGained;

public:
    Account();
    virtual ~Account();
    void addValue(bond::Bond *);
    void addValue(stock::Stock *);
    void addValue(mm::MoneyMarket *);

    virtual double getCurrentValue();
    virtual double getInvestedValue();
    double acceptVisitor(PricingVisitor* );
    void printList();
    std::vector<bond::Bond *>* getList();
    void setSum(double);
    double moneyNotInvested();
    
    void updateValues();
    virtual double getUpdatedCurrentValue();
    virtual double getUpdatedInvestedValue();
    virtual double getMoneyLostOrGained();
    virtual std::string getMoney();
    virtual void zeroAccount();

};


#endif /* defined(__OODesignFinalProject__Account__) */
