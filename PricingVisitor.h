//
//  PricingVisitor.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/8/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__PricingVisitor__
#define __OODesignFinalProject__PricingVisitor__

#include <iostream>

class Account;


class PricingVisitor
{
    
public:

    double visitComponent(Account* );
};
#endif /* defined(__OODesignFinalProject__PricingVisitor__) */
