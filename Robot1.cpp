//
//  Robot1.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/3/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Robot1.h"
#include "Bond.h"
#include "Stock.h"
#include "MoneyMarket.h"
#include "Client.h"
#include "FinancialObject.h"
#include "SortFinancialObjectVectorASC.h"
using namespace std;

Robot1::Robot1(UserFacade* u)
{
    this->uf = u;
    makeAccount();
    getVector();
//    printAllNewandOldVectorElements();
}

Robot1::~Robot1()
{
    
}

void Robot1::getVector()
{
    //get the vector
    v = uf->getClient()->getBondVector();
//    cout << endl << "Robot 1 Getting Bond List from Server: " << v << endl;
    //save vector elements(pointers) to a new list call it oldlist
    oldList.assign(v->begin(), v->end());
    //rearange this list based on some investment algorithm
    rearrangeVector();
}

void Robot1::rearrangeVector()
{
    //rearrange vb from highest to lowest by price and then save output to newlist
    //using a Functor for sorting
    sort(oldList.begin(), oldList.end(), SortFinancialObjectVectorASC());
    updateAccount();
}

void Robot1::updateAccount()
{
    double money = uf->getMoneyInvested();
    if (money < oldList.front()->getCurrentValue())
    {
        cout << "Not enough money Provided! " << endl;
        
    }
    //create an account and fill values from the newList to that account until money is out
    else
    {
        for (int i = 0; i < oldList.size(); ++i)
        {
            if (money >= oldList[i]->getCurrentValue())
            {
                a->addValue(oldList[i]); //add bond at account
                money = money - oldList[i]->getCurrentValue();
                uf->setMoneyInvested(money);
            }
            else
            {
                cout << endl;
            }
        }
//        cout << "Money not Invested: $" << money << endl;
        a->setSum(money);
    }
    
}
void Robot1::printAllNewandOldVectorElements()
{
    //delete all the financial list objects
    //iterate each list objects and call delete
    cout << endl << "Printing Bond Vector" << endl;
    for (int i = 0; i < oldList.size(); ++i)
    {
        cout << oldList[i] << "   " << oldList[i]->getName() << "  " << oldList[i]->getCurrentValue() << endl;
    }
}