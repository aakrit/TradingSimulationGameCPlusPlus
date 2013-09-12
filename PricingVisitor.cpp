//
//  PricingVisitor.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/8/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "PricingVisitor.h"
#include "Account.h"

double PricingVisitor::visitComponent(Account* sc)
{
    return sc->getCurrentValue();
}