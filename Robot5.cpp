//
//  Robot5.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/3/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Robot5.h"
#include "Bond.h"
#include "Stock.h"
#include "MoneyMarket.h"
#include "Client.h"
#include "FinancialObject.h"
#include "SortFinancialObjectVectorASC.h"
#include "SortFinancialObjectVectorDSC.h"

using namespace std;

Robot5::Robot5(UserFacade* u)
{
    this->uf = u;
    makeAccount();
    getVector();
//    printAllNewandOldVectorElements();
}

Robot5::~Robot5()
{
    
}

void Robot5::getVector()
{
    //get the bond and stock vectors
    v = uf->getClient()->getStockVector();
    m = uf->getClient()->getMMVector();
    b = uf->getClient()->getBondVector();
//    cout << endl << "Robot 5 Getting Stock Lists from Server: " << v << endl;
//    cout << endl << "Robot 5 Getting MM Lists from Server: " << m << endl;
//    cout << endl << "Robot 5 Getting Bond Lists from Server: " << m << endl;
    //save vector elements(pointers) to a new list call it stockList
    stockList.assign(v->begin(), v->end());
    mmList.assign(m->begin(), m->end());
    bondList.assign(b->begin(), b->end());
    //rearange this list based on some investment algorithm
    rearrangeVector();
}

void Robot5::rearrangeVector()
{
    sort(stockList.begin(), stockList.end(), SortFinancialObjectVectorASC());
    sort(mmList.begin(), mmList.end(), SortFinancialObjectVectorASC());
    sort(bondList.begin(), bondList.end(), SortFinancialObjectVectorDSC());

    updateAccount();
}

void Robot5::updateAccount()
{
    double money = uf->getMoneyInvested();
    double stockmoney = (money * 0.3);
    double mmMoney = (money * 0.6);
    double bondMoney = (money * 0.1);
    if (stockmoney < stockList.front()->getCurrentValue() && mmMoney < mmList.front()->getCurrentValue() && bondMoney < bondList.front()->getCurrentValue())
    {
        cout << money << "  " << stockmoney << "  "  << mmMoney << "  " << bondMoney << endl;
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
//        cout << "Stock Investment Complete" << endl;
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
        for (int i = 0; i < bondList.size(); ++i)
        {
            if (bondMoney >= bondList[i]->getCurrentValue())
            {
                a->addValue(bondList[i]); //add bond at account
                bondMoney = bondMoney - bondList[i]->getCurrentValue();
                uf->setMoneyInvested(bondMoney);
            }
            else
            {
                cout << endl;
            }
        }
        double money_not_invested = (stockmoney + mmMoney + bondMoney);
//        cout << "Money not Invested: $" << money_not_invested << endl;
        a->setSum(money_not_invested);
    }
    
}
void Robot5::printAllNewandOldVectorElements()
{
    //delete all the financial list objects
    //iterate each list objects and call delete
    cout << endl << "Printing Stock List Items" << endl;
    for (int i = 0; i < stockList.size(); ++i)
    {
        cout << stockList[i] << "   " << stockList[i]->getName() << "  " << stockList[i]->getCurrentValue() << endl;
    }
    cout << endl << "Printing MM List Items" << endl;
    for (int i = 0; i < mmList.size(); ++i)
    {
        cout << mmList[i] << "   " << mmList[i]->getName() << "  " << mmList[i]->getCurrentValue() << endl;
    }
    cout << endl << "Printing Bond List Items" << endl;
    for (int i = 0; i < bondList.size(); ++i)
    {
        cout << bondList[i] << "   " << bondList[i]->getName() << "  " << bondList[i]->getCurrentValue() << endl;
    }
}