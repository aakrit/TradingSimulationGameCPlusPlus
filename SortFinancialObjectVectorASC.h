//
//  SortFinancialObjectVectorASC.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/9/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__SortFinancialObjectVectorASC__
#define __OODesignFinalProject__SortFinancialObjectVectorASC__

#include <iostream>

class FinancialObject;

class SortFinancialObjectVectorASC
{
  
    
public:
    
    bool operator() (FinancialObject *lhs, FinancialObject *rhs);
};

#endif /* defined(__OODesignFinalProject__SortFinancialObjectVectorASC__) */
