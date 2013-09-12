//
//  MessageQueue.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/3/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Message.h"
#include "MessageQueue.h"

bool MessageQueue::isEmpty()
{
    if(this->inbox.empty())
        return true;
    else return false;
}

void MessageQueue::addMsg(Message s)
{
    inbox.push_back(s);
    std::cout << "The following message was added to the inbox: " << s.getMessage()     << std::endl;
}

void MessageQueue::popMsg()
{
    if(!(isEmpty()))
    {
        inbox.erase(inbox.begin());
        std::cout << "Message removed" << std::endl;
    }
    else
    {
        std::cout << "There are no messages in this inbox!" << std::endl;
    }
}
void MessageQueue::list()
{
    if(!(isEmpty()))
    {
        std::cout << "This inbox has the following messages: " << std::endl;
        for (auto& x : this->inbox)
        {
            std::cout << x.getMessage() << std::endl;
        }
    }
}
void MessageQueue::getListsize()
{
    std::cout << "The size of the list is: " << inbox.size() << std::endl;
}
void MessageQueue::clearList()
{
    inbox.clear();
    std::cout << "This inbox is now clear with " << inbox.size() << " messages!" << std::endl;
}