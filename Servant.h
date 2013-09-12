//
//  Servant.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Servant__
#define __OODesignFinalProject__Servant__


#include <iostream>
#include <vector>
#include "Stock.h"
#include "Financial_Instrument_list.h"
//class Stock;

class Servant
{
    //std::string name = NULL;
    std::vector<stock::Stock*>* vs;
//    std::vector<stock::Stock*> vst;
    static Servant* instance;
    Servant();
    
public:
    static Servant* makeInstance();
    std::vector<stock::Stock*>* getStockVector();
    
    void attachToFinancialList(Financial_Instrument_list*);
//    void initialize()
    
};
#endif /* defined(__OODesignFinalProject__Servant__) */
