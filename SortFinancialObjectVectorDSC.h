//
//  SortFinancialObjectVectorDSC.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/9/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__SortFinancialObjectVectorDSC__
#define __OODesignFinalProject__SortFinancialObjectVectorDSC__

#include <iostream>

class FinancialObject;

class SortFinancialObjectVectorDSC
{
    
public:
    
    bool operator() (FinancialObject *lhs, FinancialObject *rhs);
};

#endif /* defined(__OODesignFinalProject__SortFinancialObjectVectorDSC__) */
