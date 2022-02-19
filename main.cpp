//
//  main.cpp
//  TCP-Server
//
//  Created by Daniel Mai Fisher on 2/1/22.
//  Copyright © 2022 Daniel Mai Fisher. All rights reserved.
//

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "caeserCipher.hpp"
#include "BarebonesTCP.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    cout<<"lol";
    BareBonesTCP mtTCP;
    //mtTCP BareBonesTCP();
    int sock = mtTCP.createSocket();
    mtTCP.createServer(sock,3080, "127.0.0.1");
    mtTCP.interfaceStandard(sock);
    
    
    string string1 = "mooses have taken over! @%";
    CaeserCipher myobj;
    int my_key = myobj.generateKey();
    string sent_msg = myobj.encrypt(my_key, string1);
    cout<<sent_msg<<endl;
    string recv_msg = myobj.decrypt(sent_msg);
    cout<<recv_msg<<endl;
    
    
   
    return 0;
}


