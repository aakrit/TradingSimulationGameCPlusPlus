//
//  Servant2.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Servant2__
#define __OODesignFinalProject__Servant2__


#include <iostream>
#include <vector>
#include "Bond.h"
#include "Financial_Instrument_list.h"

class Servant2
{
    //std::string name = NULL;
    std::vector<bond::Bond*>* vs;
//    std::vector<bond::Bond*> vst;
    
    static Servant2* instance;
    Servant2();
    
public:
    static Servant2* makeInstance();
    std::vector<bond::Bond*>* getBondVector();

    void attachToFinancialList(Financial_Instrument_list*);

};
#endif /* defined(__OODesignFinalProject__Servant2__) */
