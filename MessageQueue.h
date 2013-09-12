//
//  MessageQueue.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/3/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__MessageQueue__
#define __OODesignFinalProject__MessageQueue__

#include <iostream>
#include <vector>

class Message;


class MessageQueue
{
    std::string name;
    std::vector<Message> inbox;
public:
    
    bool isEmpty();
    void addMsg(Message);
    void popMsg();
    void list();
    void getListsize();
    void clearList();
};

#endif /* defined(__OODesignFinalProject__MessageQueue__) */
