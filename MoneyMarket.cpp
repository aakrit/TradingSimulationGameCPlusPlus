//
//  MoneyMarket.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/5/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "MoneyMarket.h"
using namespace std;

mm::MoneyMarket::MoneyMarket(std::string name, double deposit)
{
    //type = MM;
    this->name = name;
    this->value = deposit;
   
}
mm::MoneyMarket::~MoneyMarket()
{
//    cout << "Destroying MoneyMarket Account: " << this->name << endl;
}
void mm::MoneyMarket::setBalance(double p)
{
    value = p;
}


double mm::MoneyMarket::getCurrentValue()
{
    return value;
}
string mm::MoneyMarket::getName()
{
    return name;
}