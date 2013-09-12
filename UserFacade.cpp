//
//  UserFacade.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/6/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//
#include "MarketMaker.h"
#include "UserFacade.h"
#include "Client.h"
#include "Robot1.h"
#include "Robot2.h"
#include "Robot3.h"
#include "Robot4.h"
#include "Robot5.h"
#include "Robot6.h"
#include "Robot7.h"
#include "Robot8.h"
#include "Financial_Instrument_list.h"
#include <map>
#include <unordered_map>
using namespace std;

Client* UserFacade::getClient()
{
    return c;
}
double UserFacade::getMoneyInvested()
{
    return PrincipleProvided;
}
void UserFacade::setMoneyInvested(double d)
{
    PrincipleInvested = d;
}
void UserFacade::acceptClient(Client *client)
{
    c = client;
}
MarketMaker* UserFacade::getMaretMaker()
{
    return mm;
}
void UserFacade::acceptMarketMaker(MarketMaker *m)
{
    mm = m;
    mm->initializeMarket();
}
Robot* UserFacade::getRobot()
{
    return r;
}
void UserFacade::userInput(int riskLevel, double investment)
{
    this->RiskLevel = riskLevel;
    this->PrincipleProvided = investment;
    
    launchRobotbyRisk(RiskLevel);
    
//    r->printAllNewandOldVectorElements();
    r->getAccount()->printList();
    cout << endl << "Total value of Investments in Period 0 is: $" << r->getInvestmentValue() << endl;
    cout << "Total Value in the Account is: $" << r->getAccountValue() << endl;
//    cout << "Money not Invested is: $" << r->getMoneyNotInvested() << endl;
    cout << "************************************" << endl;
    
}
void UserFacade::printMoney()
{
    financialPeriod++;
    cout << "Total value of Investments in Period " << financialPeriod << " is: $" << r->getUpdatedInvestedValue() << endl;
    cout << "Total Value in the Account is: $" << r->getUpdatedCurrentValue() << endl << endl;
//    cout << "Money not Invested is: $" << r->getMoneyNotInvested() << endl << endl;
    cout << "Money Lost/Gained in Period " << financialPeriod << " compared to Principle Investment is  $" << r->getMoneyLostOrGained() << endl;
}
void UserFacade::zeroAccount()
{
    r->zeroAccount();
}
void UserFacade::setPreoidToZero()
{
    financialPeriod = 0;
}
void UserFacade::launchRobotbyRisk(int rl)
{
    //select Robot to Run using Strategy Design Pattern
    if(rl == 1)
    {
        cout << "Your money will only be invested in Bonds" << endl;
        r = new Robot1(this);
    }
    else if (rl == 2)
    {
        cout << "Your money will only be invested in Bonds (70%) and MoneyMarkets (30%)" << endl;
        r = new Robot2(this);
    }
    else if (rl == 3)
    {
        cout << "Your money will only be invested in Bonds (50%) and MoneyMarkets (50%)" << endl;
        r = new Robot3(this);
    }
    else if (rl == 4)
    {
        cout << "Your money will only be invested in Bonds (20%), MoneyMarkets (60%), and Stocks (20%)" << endl;
        r = new Robot4(this);
    }
    else if (rl == 5)
    {
        cout << "Your money will only be invested in stock (20%), MoneyMarkets (60%), and bonds (20%)" << endl;
        r = new Robot5(this);
    }
    else if (rl == 6)
    {
        cout << "Your money will only be invested in Stocks (50%) and MoneyMarkets (50%)" << endl;
        r = new Robot6(this);
    }
    else if (rl == 7)
    {
        cout << "Your money will only be invested in Stocks (70%) and MoneyMarkets (30%)" << endl;
        r = new Robot7(this);
    }
    else if (rl == 8)
    {
        cout << "Your money will only be invested in Stocks" << endl;
        r = new Robot8(this);
    }
    else
    {
        cout << "ERROR" << endl;
    }
}

void UserFacade::acceptFinancialObjectList(Financial_Instrument_list *f)
{
    fil = f;
    unitTestCheckOnFinancialObjectList();
}
void UserFacade::unitTestCheckOnFinancialObjectList()
{
    //check to make sure we get correct stock list
    if (*c->getStockVector() != fil->stockList)
    {
        cout << "Incorrect Server returning wrong stockList" << endl;
    }
    //check to make sure we get correct bond list
    if (*c->getBondVector() != fil->bondList)
    {
        cout << "Incorrect Server returning wrong bondlist" << endl;
    }    //check to make sure we get correct mm list
    if (*c->getMMVector() != fil->moneymarketList)
    {
        cout << "Incorrect Server returning wrong moneymarketlist" << endl;
    }
}
void UserFacade::runVirtualRobots()
{
    //check to see which robots did best in the market during the course of the period
    //ideally not run the robot that is already working for the user
    //spawn all robots

    wr.emplace("Robot 1", new Robot1(this));
    wr.emplace("Robot 2", new Robot2(this));
    wr.emplace("Robot 3", new Robot3(this));
    wr.emplace("Robot 4", new Robot4(this));
    wr.emplace("Robot 5", new Robot5(this));
    wr.emplace("Robot 6", new Robot6(this));
    wr.emplace("Robot 7", new Robot7(this));
    wr.emplace("Robot 8", new Robot8(this));
    
}
int UserFacade::virtualRobotsProfitLoss()
{
    std::unordered_map<string, double> wval;
    for (auto& x : wr)
    {
        wval.emplace(x.first, x.second->getMoneyLostOrGained());
    }
    cout << "Here's how the other robots performed" << endl << endl;
    for (auto& x: wval)
    {
        std::cout << x.first << ": " << x.second << std::endl;
    }
    
    //sort by decending and return the robot that made the most profit (if any)
    return 0;
}


