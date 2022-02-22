//
//  main.cpp
//  MySimpleTCP
//
//  Created by Daniel Mai Fisher on 2/21/22.
//  Copyright © 2022 Daniel Mai Fisher. All rights reserved.
//

#include <iostream>
#include "TCPServer.hpp"


int main(int argc, const char * argv[]) {
    BareBonesTCP myTCP;
    int mySock = myTCP.createSocket();
    myTCP.createServer(mySock, 8080, "127.0.0.1");
    myTCP.interfaceStandard(mySock);
    return 0;
}
