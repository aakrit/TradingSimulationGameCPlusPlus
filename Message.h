//
//  Message.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/9/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Message__
#define __OODesignFinalProject__Message__

#include <iostream>

class Message
{
    
    std::string message = NULL;
public:
    Message(std::string);
    std::string getMessage();
    void setMessage (std::string);
    
};

#endif /* defined(__OODesignFinalProject__Message__) */
