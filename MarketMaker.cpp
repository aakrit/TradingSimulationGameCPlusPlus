//
//  MarketMaker.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/9/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include <ctime>
#include <cstdlib>

#include "MarketMaker.h"
#include "Financial_Instrument_list.h"

using namespace std;

MarketMaker::MarketMaker(Financial_Instrument_list *fi)
{
    fil = fi;
//    srand(time(NULL));
}

MarketMaker::~MarketMaker()
{
    
}

void MarketMaker::updateFinancialObjects()
{
    //randomly update the Financial Objects
    srand(time(NULL));
    
    for (int i = 0; i < fil->stockList.size(); ++i)
    {
        //stock values and move up or down from 0.5 to 1.5%
        double financialObjectChange = PercentPriceChange(stockLow, stockHigh);
//        cout << fil->stockList[i]->getName() << "in this period is " << financialObjectChange << "% higher/lower than the previous peroid" << endl;
        fil->stockList[i]->setBalance((fil->stockList[i]->getCurrentValue())*financialObjectChange);
//        cout << fil->stockList[i]->getCurrentValue() << "  " << fil->stockList[i] << "  " << endl;
    }
    for (int i = 0; i < fil->bondList.size(); ++i)
    {
        double financialObjectChange = PercentPriceChange(bondLow, bondHigh);
//        cout <<  fil->bondList[i]->getName() << " in this period is " << financialObjectChange << "% higher/lower than the previous peroid" << endl;
        fil->bondList[i]->setBalance((fil->bondList[i]->getCurrentValue())*financialObjectChange);
//        cout << fil->bondList[i]->getCurrentValue() << "  " << fil->bondList[i] << "  " << endl;
    }
    for (int i = 0; i < fil->moneymarketList.size(); ++i)
    {
        double financialObjectChange = PercentPriceChange(mmLow, mmHigh);
//        cout << fil->moneymarketList[i]->getName() << " in this period is " << financialObjectChange << "% higher/lower than the previous peroid" << endl;
        fil->moneymarketList[i]->setBalance((fil->moneymarketList[i]->getCurrentValue())*financialObjectChange);
//        cout << fil->moneymarketList[i]->getCurrentValue() << "  " << fil->moneymarketList[i] << "  " << endl;
    }
}

void MarketMaker::initializeMarket()
{
    srand(time(NULL));
    int marketmovement = rand() % 3;
    if (marketmovement == 0)
    {
        marketCondition = "Normal Volatility";
        
        bondLow = 0.8;
        bondHigh = 1.2;
        mmLow = 0.6;
        mmHigh = 1.4;
        stockLow = 0.4;
        stockHigh = 1.6;
    }
    else if (marketmovement == 1)
    {
        marketCondition = "Low Volatility";
        bondLow = 0.9;
        bondHigh = 1.1;
        mmLow = 0.8;
        mmHigh = 1.2;
        stockLow = 0.7;
        stockHigh = 1.3;
    }
    else if (marketmovement == 2)
    {
        marketCondition = "Highly Volatility";
        bondLow = 0.6;
        bondHigh = 1.4;
        mmLow = 0.4;
        mmHigh = 1.6;
        stockLow = 0.2;
        stockHigh = 1.8;
    }
}
string MarketMaker::getMarketCondition()
{
    return marketCondition;
}

double MarketMaker::PercentPriceChange(double lowVal, double highVal)
{
    double difference = highVal - lowVal;
    return (((double) rand() / RAND_MAX) * difference) + lowVal;
}
