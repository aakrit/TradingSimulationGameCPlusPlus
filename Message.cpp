//
//  Message.cpp
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/9/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Message.h"

Message::Message(std::string s)
{
    message = s;
}

void Message::setMessage(std::string s)
{
    this->message = s;
}

std::string Message::getMessage()
{
    return this->message;
}