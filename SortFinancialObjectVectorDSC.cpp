//
//  SortFinancialObjectVectorDSC.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/9/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "SortFinancialObjectVectorDSC.h"
#include "FinancialObject.h"

bool SortFinancialObjectVectorDSC::operator()(FinancialObject *lhs, FinancialObject *rhs)
{
    return (*lhs).getCurrentValue() < (*rhs).getCurrentValue();
}