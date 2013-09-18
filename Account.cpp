//
//  Account.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/6/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//
#include <fstream>
#include "Account.h"
#include "Bond.h"
#include "Stock.h"
#include "MoneyMarket.h"
#include "PricingVisitor.h"

using namespace std;

Account::Account()
{

}
Account::~Account()
{

}
void Account::addValue(bond::Bond* p)
{
//    cout << "Adding " << p->getName() << " to your Account" << endl;
    bondAccountList.push_back(p);
    //add up account values
    totalAccountValue += p->getCurrentValue();
    investedAmount += p->getCurrentValue();
}
void Account::addValue(stock::Stock* p)
{
//    cout << "Adding " << p->getName() << " to your Account" << endl;
    stockAccountList.push_back(p);
    totalAccountValue += p->getCurrentValue();
    investedAmount += p->getCurrentValue();
}
void Account::addValue(mm::MoneyMarket* p)
{
//    cout << "Adding " << p->getName() << " to your Account" << endl;
    mmAccountList.push_back(p);
    totalAccountValue += p->getCurrentValue();
    investedAmount += p->getCurrentValue();
}
void Account::printList()
{
    cout << "Your Account has following Components: " << endl;
    for (auto& x : bondAccountList)
    {
        cout << (*x).getName() << " with price value $" << (*x).getCurrentValue();
        cout << endl;
    }
    for (auto& x : stockAccountList)
    {
        cout << (*x).getName() << " with price value $" << (*x).getCurrentValue();
        cout << endl;
    }
    for (auto& x : mmAccountList)
    {
        cout << (*x).getName() << " with price value $" << (*x).getCurrentValue();
        cout << endl;
    }
}

double Account::getCurrentValue()
{
    return totalAccountValue;
}
double Account::getInvestedValue()
{
    return investedAmount;
}
double Account::acceptVisitor(PricingVisitor *pv)
{
    return pv->visitComponent(this);
}
void Account::setSum(double d)
{
    totalAccountValue += d;
}
double Account::moneyNotInvested()
{
    return (totalAccountValue - investedAmount);
}
void Account::updateValues()
{
    //resum up the values in the bond, stock, and mm vectors
    //first re-zero the updated values
    std::ofstream cp;
    cp.open("/Users/aakritprasad/OODesignClass/HWs_Labs/OODesignFinalProject/OODesignFinalProject/ProgramResult.DAS.csv", ofstream::out | ofstream::app);
    if (period == 0)
    {
        cp << "Trading Simulation Game Results" << endl;
        cp << "Your Account Financial Object Values per Period" << endl;
        cp << "Period" << ", " << "Financial_Object" << ", " << "Object_Name" << ", " << "Value" << endl;
    }
    updatedInvestedAmount = 0;
    period++;
    for (auto& x : bondAccountList)
    {
        if (cp.is_open())
        {
            cp << period << ", " << "BOND" << ", " << (*x).getName() << ", " << (*x).getCurrentValue() << endl;
        }
//        cout << endl << "The Value of " << (*x).getName() << " is now " << (*x).getCurrentValue() << endl;
        updatedInvestedAmount += (*x).getCurrentValue();
    }
    for (auto& x : stockAccountList)
    {
        if (cp.is_open())
        {
            cp << period << ", " << "STOCK" << ", " << (*x).getName() << ", " << (*x).getCurrentValue() << endl;
        }
//        cout << "The Value of " << (*x).getName() << " is now " << (*x).getCurrentValue() << endl;
        updatedInvestedAmount += (*x).getCurrentValue();
    }
    for (auto& x : mmAccountList)
    {
        if (cp.is_open())
        {
            cp << period << ", " << "MONEYMARKET" << ", " << (*x).getName() << ", " << (*x).getCurrentValue() << endl;
        }
//        cout << "The Value of " << (*x).getName() << " is now " << (*x).getCurrentValue() << endl;
        updatedInvestedAmount += (*x).getCurrentValue();
    }
    cp.close();
    
}

double Account::getUpdatedCurrentValue()
{
    updatedTotalAccountValue = (totalAccountValue + (updatedInvestedAmount - investedAmount));
    return updatedTotalAccountValue;
}
double Account::getUpdatedInvestedValue()
{
    updateValues();
    return updatedInvestedAmount;
}
double Account::getMoneyLostOrGained()
{
    double moneyLossGain = (updatedInvestedAmount - investedAmount);
    return moneyLossGain;
}
string Account::getMoney()
{
    return moneyLostOrGained;
}
void Account::zeroAccount()
{
    totalAccountValue = 0;
    investedAmount = 0;
    updatedInvestedAmount = 0;
    updatedTotalAccountValue = 0;
    
}

