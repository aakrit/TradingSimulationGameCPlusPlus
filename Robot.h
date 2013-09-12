//
//  Robot.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/3/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Robot__
#define __OODesignFinalProject__Robot__

#include <iostream>
#include "Account.h"

class Client;
class UserFacade;

//abstract base class
//using Template and Strategy Design Patterns

class Robot
{
//    UserFacade *uf = NULL;
    
protected:
//    explicit Robot(UserFacade*);
    Account *a = NULL;
    void makeAccount();
    
    
public:
    
    Robot();
    virtual ~Robot();
    
    virtual void getVector() = 0;
    virtual void rearrangeVector() = 0;
    virtual void updateAccount() = 0;
    virtual void printAllNewandOldVectorElements() = 0;
    
    virtual double getAccountValue();
    virtual double getInvestmentValue();
    virtual double getMoneyNotInvested();
    virtual double getUpdatedCurrentValue();
    virtual double getUpdatedInvestedValue();
    virtual double getMoneyLostOrGained();
    virtual std::string getMoneyPosition();
    virtual void zeroAccount();
    
    Account* getAccount();
    
};



#endif /* defined(__OODesignFinalProject__Robot__) */
