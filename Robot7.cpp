//
//  Robot7.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/3/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Robot7.h"
#include "Bond.h"
#include "Stock.h"
#include "MoneyMarket.h"
#include "Client.h"
#include "FinancialObject.h"
#include "SortFinancialObjectVectorASC.h"

using namespace std;

Robot7::Robot7(UserFacade* u)
{
    this->uf = u;
    makeAccount();
    getVector();
//    printAllNewandOldVectorElements();
}

Robot7::~Robot7()
{
    
}

void Robot7::getVector()
{
    //get the bond and stock vectors
    v = uf->getClient()->getStockVector();
    m = uf->getClient()->getMMVector();
//    cout << endl << "Robot 7 Getting Stock Lists from Server: " << v << endl;
//    cout << endl << "Robot 7 Getting MM Lists from Server: " << m << endl;
    //save vector elements(pointers) to a new list call it stockList
    stockList.assign(v->begin(), v->end());
    mmList.assign(m->begin(), m->end());
    //rearange this list based on some investment algorithm
    rearrangeVector();
}

void Robot7::rearrangeVector()
{
    sort(stockList.begin(), stockList.end(), SortFinancialObjectVectorASC());
    sort(mmList.begin(), mmList.end(), SortFinancialObjectVectorASC());
    
    updateAccount();
}

void Robot7::updateAccount()
{
    double money = uf->getMoneyInvested();
    double stockmoney = (money * 0.7);
    double mmMoney = (money * 0.3);
    if (stockmoney < stockList.front()->getCurrentValue() && mmMoney < mmList.front()->getCurrentValue())
    {
        cout << money << "  " << stockmoney << "  "  << mmMoney << endl;
        cout << "Not enough money Provided! " << endl;
    }
    //create an account and fill values from the newList to that account until money is out
    else
    {
//        cout << money << "  " << stockmoney << "  "  << mmMoney << endl;
        for (int i = 0; i < stockList.size(); ++i)
        {
            if (stockmoney >= stockList[i]->getCurrentValue())
            {
                a->addValue(stockList[i]); //add bond at account
                stockmoney = stockmoney - stockList[i]->getCurrentValue();
                uf->setMoneyInvested(stockmoney);
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
        double money_not_invested = stockmoney + mmMoney;
//        cout << "Money not Invested: $" << money_not_invested << endl;
        a->setSum(money_not_invested);
    }
    
}
void Robot7::printAllNewandOldVectorElements()
{
    //delete all the financial list objects
    //iterate each list objects and call delete
    cout << endl << "Printing Bond List Items" << endl;
    for (int i = 0; i < stockList.size(); ++i)
    {
        cout << stockList[i] << "   " << stockList[i]->getName() << "  " << stockList[i]->getCurrentValue() << endl;
    }
    cout << endl << "Printing MM List Items" << endl;
    for (int i = 0; i < mmList.size(); ++i)
    {
        cout << mmList[i] << "   " << mmList[i]->getName() << "  " << mmList[i]->getCurrentValue() << endl;
    }
}