//
//  Component.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/9/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Component__
#define __OODesignFinalProject__Component__

#include <iostream>


class Component
{
    
protected:

    
public:
    Component();
    virtual ~Component();
    
    virtual double getCurrentValue() = 0;

};


#endif /* defined(__OODesignFinalProject__Component__) */
