//
//  Robot.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/3/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Robot.h"
#include "Client.h"
#include "UserFacade.h"

using namespace std;

//Robot::Robot(UserFacade *f)
//{
//    uf = f;
//    makeAccount();
//}

Robot::Robot()
{
    
}
Robot::~Robot()
{
    
}

void Robot::makeAccount()
{
    a = new Account();
}

Account* Robot::getAccount()
{
    return a;
}

double Robot::getAccountValue()
{
    return a->getCurrentValue();
}
double Robot::getInvestmentValue()
{
    return a->getInvestedValue();
}
double Robot::getMoneyNotInvested()
{
    return a->moneyNotInvested();
}
double Robot::getUpdatedCurrentValue()
{
    return a->getUpdatedCurrentValue();
}
double Robot::getUpdatedInvestedValue()
{
    return a->getUpdatedInvestedValue();
}
double Robot::getMoneyLostOrGained()
{
    return a->getMoneyLostOrGained();
}
string Robot::getMoneyPosition()
{
    return a->getMoney();
}
void Robot::zeroAccount()
{
    a->zeroAccount();
}

