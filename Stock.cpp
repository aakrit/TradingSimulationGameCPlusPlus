//
//  Stock.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//
//#include "PricingVisitor.h"
#include "Stock.h"
using namespace std;

stock::Stock::Stock(string name, double price)
{
//    type = STOCK;
    this->name = name;
    this->value = price;
    
}

stock::Stock::~Stock()
{
//    std::cout << "Destroying stock: " << name << std::endl;
}

void stock::Stock::setBalance(double p)
{
    value = p;
}

double stock::Stock::getCurrentValue()
{
    return value;
}
string stock::Stock::getName()
{
    return name;
}
