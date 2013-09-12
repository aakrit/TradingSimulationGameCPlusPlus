//
//  Robot3.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/3/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Robot3.h"
#include "Bond.h"
#include "Stock.h"
#include "MoneyMarket.h"
#include "Client.h"
#include "FinancialObject.h"
#include "SortFinancialObjectVectorASC.h"

using namespace std;

Robot3::Robot3(UserFacade* u)
{
    this->uf = u;
    makeAccount();
    getVector();
//    printAllNewandOldVectorElements();
}

Robot3::~Robot3()
{
    
}

void Robot3::getVector()
{
    //get the bond and stock vectors
    v = uf->getClient()->getBondVector();
    m = uf->getClient()->getMMVector();
//    cout << endl << "Robot 3 Getting Bond Lists from Server: " << v << endl;
//    cout << endl << "Robot 3 Getting MM Lists from Server: " << m << endl;
    //save vector elements(pointers) to a new list call it bondList
    bondList.assign(v->begin(), v->end());
    mmList.assign(m->begin(), m->end());
    //rearange this list based on some investment algorithm
    rearrangeVector();
}

void Robot3::rearrangeVector()
{
    sort(bondList.begin(), bondList.end(), SortFinancialObjectVectorASC());
    sort(mmList.begin(), mmList.end(), SortFinancialObjectVectorASC());
    
    updateAccount();
}

void Robot3::updateAccount()
{
    double money = uf->getMoneyInvested();
    double bondmoney = (money * 0.5);
    double mmMoney = (money * 0.5);
    if (bondmoney < bondList.front()->getCurrentValue() && mmMoney < mmList.front()->getCurrentValue())
    {
        cout << money << "  " << bondmoney << "  "  << mmMoney << endl;
        cout << "Not enough money Provided! " << endl;
    }
    //create an account and fill values from the newList to that account until money is out
    else
    {
//        cout << money << "  " << bondmoney << "  "  << mmMoney << endl;
        for (int i = 0; i < bondList.size(); ++i)
        {
            if (bondmoney >= bondList[i]->getCurrentValue())
            {
                a->addValue(bondList[i]); //add bond at account
                bondmoney = bondmoney - bondList[i]->getCurrentValue();
                uf->setMoneyInvested(bondmoney);
            }
            else
            {
                cout << endl;
            }
        }
        for (int i = 0; i < mmList.size(); ++i)
        {
            if (mmMoney >= mmList[i]->getCurrentValue())
            {
                a->addValue(mmList[i]); //add bond at account
                mmMoney = mmMoney - mmList[i]->getCurrentValue();
                uf->setMoneyInvested(mmMoney);
            }
            else
            {
                cout << endl;
            }
        }
        double money_not_invested = bondmoney + mmMoney;
//        cout << "Money not Invested: $" << money_not_invested << endl;
        a->setSum(money_not_invested);
    }
    
}
void Robot3::printAllNewandOldVectorElements()
{
    //delete all the financial list objects
    //iterate each list objects and call delete
    cout << endl << "Printing Bond List Items" << endl;
    for (int i = 0; i < bondList.size(); ++i)
    {
        cout << bondList[i] << "   " << bondList[i]->getName() << "  " << bondList[i]->getCurrentValue() << endl;
    }
    cout << endl << "Printing MM List Items" << endl;
    for (int i = 0; i < mmList.size(); ++i)
    {
        cout << mmList[i] << "   " << mmList[i]->getName() << "  " << mmList[i]->getCurrentValue() << endl;
    }
}