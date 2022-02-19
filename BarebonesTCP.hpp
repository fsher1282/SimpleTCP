//
//  BarebonesTCP.hpp
//  TCP-Server
//
//  Created by Daniel Mai Fisher on 2/3/22.
//  Copyright © 2022 Daniel Mai Fisher. All rights reserved.
//

#ifndef BarebonesTCP_hpp
#define BarebonesTCP_hpp

#include <stdio.h>
#include <functional>
#include "caeserCipher.hpp"
using namespace std::placeholders;

class BareBonesTCP{
private:
    int sock;
    
public:
    BareBonesTCP();
    int createSocket();
    int createServer(int,int,std::string);
    void interfaceStandard(int);
    void interfaceEncrypted(int);
    //~BareBonesTCP();
    
};


#endif /* BarebonesTCP_hpp */
