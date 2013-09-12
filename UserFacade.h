//
//  UserFacade.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/6/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__UserFacade__
#define __OODesignFinalProject__UserFacade__

//this class takes input from main
#include <iostream>
#include "Robot.h"
#include <unordered_map>

class Client;
class MarketMaker;
class Financial_Instrument_list;

class UserFacade
{
    int RiskLevel;
    double PrincipleInvested;
    double PrincipleProvided;
    
    Client *c = NULL;
    Robot *r = NULL;
    MarketMaker *mm = NULL;
    Financial_Instrument_list *fil = NULL;
    
    void launchRobotbyRisk(int);
    
    std::unordered_map<std::string, Robot *> wr;
    
    int financialPeriod = 0;

public:
    void acceptClient(Client *);
    void acceptMarketMaker(MarketMaker *);
    void acceptFinancialObjectList(Financial_Instrument_list *);
    
    void userInput(int, double);
    Client* getClient();
    MarketMaker* getMaretMaker();
    
    
    double getMoneyInvested();
    void setMoneyInvested(double);
    Robot* getRobot();
    void printMoney();
    void zeroAccount();
    void setPreoidToZero();
    
    void unitTestCheckOnFinancialObjectList();
    
    void runVirtualRobots();
    int virtualRobotsProfitLoss();
    
};


#endif /* defined(__OODesignFinalProject__UserFacade__) */
