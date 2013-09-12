//
//  Financial_Instrument_list.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Financial_Instrument_list.h"
#include "Servant.h"
#include "Servant2.h"
#include "Servant3.h"

using namespace std;

Financial_Instrument_list::Financial_Instrument_list()
{
    //creating and stock financial instruments
    
    stockList.emplace_back(new stock::Stock("APPL", 505.9));
    stockList.emplace_back(new stock::Stock("GOOG", 879.2));
    stockList.emplace_back(new stock::Stock("MSFT", 35.6));
    stockList.emplace_back(new stock::Stock("YHOO", 25));
    stockList.emplace_back(new stock::Stock("DIS", 65));
    stockList.emplace_back(new stock::Stock("MT", 13.2));
    stockList.emplace_back(new stock::Stock("BP", 43.5));
    stockList.emplace_back(new stock::Stock("EOM", 91.2));
    stockList.emplace_back(new stock::Stock("Nokia", 3.5));
    stockList.emplace_back(new stock::Stock("XEROX", 9.1));
    stockList.emplace_back(new stock::Stock("INTEL", 25.4));
    stockList.emplace_back(new stock::Stock("ELN", 13.3));
    stockList.emplace_back(new stock::Stock("PG", 77.7));
    stockList.emplace_back(new stock::Stock("X", 17.3));
    stockList.emplace_back(new stock::Stock("AKS", 3.34));
    stockList.emplace_back(new stock::Stock("JNJ", 84.9));
    stockList.emplace_back(new stock::Stock("CRM", 39.6));
    stockList.emplace_back(new stock::Stock("AMZN", 276.8));
    stockList.emplace_back(new stock::Stock("CMG", 365.8));

    
    bondList.emplace_back(new bond::Bond("bond1", 30));
    bondList.emplace_back(new bond::Bond("bond2", 40));
    bondList.emplace_back(new bond::Bond("bond3", 50));
    bondList.emplace_back(new bond::Bond("bond4", 10));
    bondList.emplace_back(new bond::Bond("bond5", 200));
    bondList.emplace_back(new bond::Bond("bond6", 156));
    bondList.emplace_back(new bond::Bond("bond7", 350));
    bondList.emplace_back(new bond::Bond("bond8", 88));
    bondList.emplace_back(new bond::Bond("bond9", 73));
    bondList.emplace_back(new bond::Bond("bond10", 91));
    bondList.emplace_back(new bond::Bond("bond11", 61));
    bondList.emplace_back(new bond::Bond("bond12", 84));
    
    moneymarketList.emplace_back(new mm::MoneyMarket("mm1", 100));
    moneymarketList.emplace_back(new mm::MoneyMarket("mm2", 150));
    moneymarketList.emplace_back(new mm::MoneyMarket("mm3", 300));
    moneymarketList.emplace_back(new mm::MoneyMarket("mm4", 350));
    moneymarketList.emplace_back(new mm::MoneyMarket("mm5", 90));
    moneymarketList.emplace_back(new mm::MoneyMarket("mm6", 50));
    moneymarketList.emplace_back(new mm::MoneyMarket("mm7", 80));
    moneymarketList.emplace_back(new mm::MoneyMarket("mm8", 94));
    moneymarketList.emplace_back(new mm::MoneyMarket("mm9", 47));
    moneymarketList.emplace_back(new mm::MoneyMarket("mm10", 34));
    moneymarketList.emplace_back(new mm::MoneyMarket("mm11", 646));
    moneymarketList.emplace_back(new mm::MoneyMarket("mm12", 432));
    moneymarketList.emplace_back(new mm::MoneyMarket("mm13", 53));
    moneymarketList.emplace_back(new mm::MoneyMarket("mm14", 74));
    moneymarketList.emplace_back(new mm::MoneyMarket("mm15", 43));
    moneymarketList.emplace_back(new mm::MoneyMarket("mm16", 63));
    

}
Financial_Instrument_list::~Financial_Instrument_list()
{
    //delete all the financial list objects
    //iterate each list objects and call delete
    for (int i = 0; i < stockList.size(); ++i)
    {
        delete stockList[i];
    }
    stockList.clear();
    for (int i = 0; i < bondList.size(); ++i)
    {
        delete bondList[i];
    }
    bondList.clear();
    for (int i = 0; i < moneymarketList.size(); ++i)
    {
        delete moneymarketList[i];
    }
    moneymarketList.clear();
}

void Financial_Instrument_list::attachToStockServer(Servant *stock)
{
    stock->attachToFinancialList(this);
}

void Financial_Instrument_list::attachToBondServer(Servant2 *bond)
{
    bond->attachToFinancialList(this);
}

void Financial_Instrument_list::attachToMoneyMarketServer(Servant3 *mm)
{
    mm->attachToFinancialList(this);
}
void Financial_Instrument_list::printAllVectorElement()
{
    //delete all the financial list objects
    //iterate each list objects and call delete
    cout << endl << "Printing stock Vector" << endl;
    for (int i = 0; i < stockList.size(); ++i)
    {
        cout << stockList[i] << "  " << stockList[i]->getName() << "   "  << stockList[i]->getCurrentValue() << endl;
    }
    cout << "Printing bond Vector" << endl;
    for (int i = 0; i < bondList.size(); ++i)
    {
        cout << bondList[i] << "   " << bondList[i]->getName() << "  " << bondList[i]->getCurrentValue() << endl;
    }
    cout << "Printing MM Vector" << endl;
    for (int i = 0; i < moneymarketList.size(); ++i)
    {
        cout << moneymarketList[i] << "   " << moneymarketList[i]->getName() << "   " << moneymarketList[i]->getCurrentValue() << endl;
    }
}

