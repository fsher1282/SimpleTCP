//
//  TCPServer.hpp
//  MySimpleTCP
//
//  Created by Daniel Mai Fisher on 2/21/22.
//  Copyright © 2022 Daniel Mai Fisher. All rights reserved.
//

#ifndef TCPServer_hpp
#define TCPServer_hpp

#include <stdio.h>
#include <functional>


class BareBonesTCP{
private:
    int sock;
    
public:
    BareBonesTCP();
    int createSocket();
    int createServer(int,int,std::string);
    void interfaceStandard(int);
    //~BareBonesTCP();
    
};



#endif /* TCPServer_hpp */
