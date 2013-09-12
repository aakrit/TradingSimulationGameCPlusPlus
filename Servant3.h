//
//  Servant3.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/5/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Servant3__
#define __OODesignFinalProject__Servant3__


#include <iostream>
#include <vector>
#include "MoneyMarket.h"
#include "Financial_Instrument_list.h"

class Servant3
{
    //std::string name = NULL;
    std::vector<mm::MoneyMarket*>* vs;
    //    std::vector<mm::MoneyMarket*> vst;
    static Servant3* instance;
    Servant3();
    
public:
    static Servant3* makeInstance();
    int getLength(std::string const&);
    std::vector<mm::MoneyMarket*>* getMMVector();
    
    void attachToFinancialList(Financial_Instrument_list*);
    
};
#endif /* defined(__OODesignFinalProject__Servant3__) */
