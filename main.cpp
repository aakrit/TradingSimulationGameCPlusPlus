//
//  main.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//
#include <vector>
#include <sstream>
#include <iostream>
#include <memory>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

#include "UserFacade.h"
#include "Client.h"
#include "ClientProxy.h"
#include "Server.h"
#include "BrokerServer.h"
#include "Broker.h"
#include "Servant.h"
#include "Stock.h"
#include "Servant.h"
#include "Servant2.h"
#include "Servant3.h"
#include "Financial_Instrument_list.h"
#include "MarketMaker.h"

using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...
    //before user input, we need to do the registration process
    //1st create client proxy
    ClientProxy *cp = new ClientProxy();
    //we will create(startup) and register a server broker (named lab2 server broker) to our client broker (called class Broker). This way the client broker will know which server broker to call for executing the requested commands
    BrokerServer *bs = new BrokerServer("Financial Trading Game Server Broker");
    Broker *cb = new Broker();
    //register the client broker to the client proxy so its knows where to send the call object
    cp->register_b(cb);
    //register the server broker named "lab 2 server broker" to the client broker so it knows to send the addint and getlen fucntions to this server broker
    cb->registerServerBroker(bs);
    
    //Next we will register our server with the server broker so the server broker knows which server to call for the function execution passes that to the server proxy to call that server
    Server *server = new Server();
    bs->registerServer(server);
    //adding Servants to Server
    Servant *stockservant = Servant::makeInstance();
    Servant2 *bondservant = Servant2::makeInstance();
    Servant3 *mmservant = Servant3::makeInstance();
    server->addServants(stockservant, bondservant, mmservant);
    
    //now we create a User Facade class and a client for the user to use
    unique_ptr<UserFacade> uf(new UserFacade());
    Client *c = new Client(cp);
    uf->acceptClient(c);
    
    
    //UI CODE
    cout << "Welcome to the Trading Simulation Game!" << endl << "This Game is 30 seconds long with 6 Periods where each period can be thought of as a fiscal quarter in the markets" << endl;
    while (1)
    {
        //create the financial instruments and pass the Servants to it
        Financial_Instrument_list *fil = new Financial_Instrument_list();
        fil->attachToStockServer(stockservant);
        fil->attachToBondServer(bondservant);
        fil->attachToMoneyMarketServer(mmservant);
        //add fil to userfacade for unit testing, make sure robots get correct lists
        uf->acceptFinancialObjectList(fil);
        //create the market maker to update the market financial objects
        MarketMaker *marketmaker = new MarketMaker(fil);
        uf->acceptMarketMaker(marketmaker);
        
        cout << endl << "Press 1 to play or 2 to exit " << endl;
        int Input = 0;
        cout << "Input: ";
        if (!(cin >> Input))
        {
            cout << "ERROR: Input must be a number! Exiting..." << endl;
            break;
        }
        if (Input == 2)
        {
            cout << "Thanks for Playing! " << endl;
            break;
        }
        if (Input != 1)
        {
            cout << "ERROR: INCORRECT INPUT, Try again" << endl;
            continue;
        }
        string marketVolatility = uf->getMaretMaker()->getMarketCondition();
        cout << "The Volatility in the market this period is: " << marketVolatility << endl;
        cout << "Please Enter your Risk Level (1 - 8 where 8 is more risky) and investment amount (between $100 and $1000)" << endl << endl;
        int RiskLevel = 0, Investment = 0;
        cout << "Risk Level: ";
        if (!(cin >> RiskLevel))
        {
            cout << "ERROR: Input must be a number! Exiting..." << endl;
            break;
        }
        if (RiskLevel > 8 || RiskLevel < 1)
        {
            cout << "ERROR: Must pick a Risk level between 1 and 8, Try again" << endl;
            continue;
        }
        cout << endl << "Investment Amount: ";
        if (!(cin >> Investment))
        {
            cout << "ERROR: Input must be a number! Exiting..." << endl;
            break;
        }
        if (Investment > 1000 || Investment < 100)
        {
            cout << "ERROR: The Investment amount must be between $100-$1000, Try again " << endl;
            continue;
        }
        cout << endl;
        
        uf->userInput(RiskLevel, Investment);
        //we can run virtual robots to see how each robot did and compare
//        uf->runVirtualRobots();
        int period = 0;
        while (period < 6)
        {
            sleep(5);
            period++;
            marketmaker->updateFinancialObjects();
            uf->printMoney();
            cout << "************************************" << endl << endl << endl;
            
        }
        double MoneyLostOrGained = uf->getRobot()->getAccount()->getMoneyLostOrGained();
        if (MoneyLostOrGained > 0)
        {
            cout << "CONGRATS!!, looks like you made $" << MoneyLostOrGained << endl;
        }
        else if (MoneyLostOrGained < 0)
        {
            cout << "SORRY, looks like you lost $" << MoneyLostOrGained << endl;
        }
        //zero out all account value
//        uf->virtualRobotsProfitLoss();
        uf->zeroAccount();
        uf->setPreoidToZero();
        delete marketmaker;
        delete fil;
        cout << endl << "You can see the details of your account value per Period here: /Users/aakritprasad/OODesignClass/HWs_Labs/OODesignFinalProject/OODesignFinalProject/ProgramResult.DAS.csv" << endl;
    }
    cout << endl << "Thank you for playing the game!" << endl;
    
    bs->un_registerServer(server);
    
    //free memory
    delete c;
    delete server;
    delete stockservant;
    delete bondservant;
    delete mmservant;
    delete cp;
    delete bs;
    delete cb;
    
    return 0;
}


