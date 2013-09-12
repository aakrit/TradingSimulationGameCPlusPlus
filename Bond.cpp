//
//  Bond.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Bond.h"

using namespace std;

bond::Bond::Bond(std::string n, double deposit)
{
    //type = BOND;
    name = n;
    value = deposit;
}
bond::Bond::~Bond()
{
//    cout << "Destroying MoneyMarket Account: " << name << endl;
}

void bond::Bond::setBalance(double p)
{
    value = p;
}
string bond::Bond::getName()
{
    return name;
}
double bond::Bond::getCurrentValue()
{
    return value;
}


