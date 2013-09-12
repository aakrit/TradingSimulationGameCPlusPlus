//
//  Server.h
//  OODesignFinalProject
//
//  Created by Aakrit Prasad on 6/4/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesignFinalProject__Server__
#define __OODesignFinalProject__Server__

#include <iostream>
#include <vector>


namespace bond{
    class Bond;
}
namespace stock {
    class Stock;
}
namespace mm {
    class MoneyMarket;
}
class Servant;
class Servant2;
class Servant3;

//The server proxy convert the callobject to its regular language format, java/ or c++ and passes that informaition to the server. The server will then pass the information to one of its servants to do the computation
class Server
{
    //std::string name = NULL;
    Servant* stockServant;
    Servant2* bondServant;
    Servant3* mmServant;
public:
    
    void addServants(Servant*, Servant2*, Servant3*);
    
    std::vector<stock::Stock*>* getStockVector();
    std::vector<bond::Bond*>* getBondVector();
    std::vector<mm::MoneyMarket*>* getMMVector();

};
#endif /* defined(__OODesignFinalProject__Server__) */
