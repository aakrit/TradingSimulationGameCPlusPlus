//
//  SortFinancialObjectVectorASC.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/9/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "SortFinancialObjectVectorASC.h"
#include "FinancialObject.h"

bool SortFinancialObjectVectorASC::operator()(FinancialObject *lhs, FinancialObject *rhs)
{
    return (*lhs).getCurrentValue() < (*rhs).getCurrentValue();
}