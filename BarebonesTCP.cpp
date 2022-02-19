//
//  BarebonesTCP.cpp
//  TCP-Server
//
//  Created by Daniel Mai Fisher on 2/3/22.
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
#include "BarebonesTCP.hpp"
#include "caeserCipher.hpp"

BareBonesTCP::BareBonesTCP(){
    sock = 0;
}

// Create the Socket
int BareBonesTCP::createSocket(){
    int my_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (my_sock == -1){
        std::cerr<<"Unable to create socket"<<std::endl;
        my_sock = 1;
    }
    return my_sock;
}


// Structure for server and connect to Socket
int BareBonesTCP::createServer(int sock1,int port, std::string ipAddress){
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);
    
    //    Connect to the server to the socket
    int connected = connect(sock1, (sockaddr*)&hint, sizeof(hint));
    if (connected == -1)
    {
        std::cerr<<"Unable to connect Socket to Server"<<std::endl;
        return 1;
    }
    
    return connected;
}

// Loop through standard sending/recieving messages
void BareBonesTCP::interfaceStandard(int sock1){
    //    While loop:
    char buf[4096];
    std::string userInput;
    
    
    do {
        //        Enter lines of text
        std::cout << "> ";
        getline(std::cin, userInput);
        
        //        Send to server
        int sendRes = send(sock1, userInput.c_str(), userInput.size() + 1, 0);
        if (sendRes == -1)
        {
            std::cout << "Could not send to server! Whoops!\r\n";
            continue;
        }
        
        //        Wait for response
        memset(buf, 0, 4096);
        int bytesReceived = recv(sock1, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            std::cout << "Error getting response from server\r\n";
        }
        else
        {
            //        Display response
            std::cout << "SERVER> " << std::string(buf, bytesReceived) << "\r\n";
        }
    } while(true);
}


// Loop through standard sending/recieving messages
void BareBonesTCP::interfaceEncrypted(int sock1){
    //    While loop:
    std::string userInput;
    char buf[4096];
    
    
    
        //        Enter lines of text
        std::cout << "> ";
        getline(std::cin, userInput);
        
        //        Send to server
        int sendRes = send(sock1, userInput.c_str(), userInput.size() + 1, 0);
        if (sendRes == -1)
        {
            std::cout << "Could not send to server! Whoops!\r\n";
            
        }
        
        //        Wait for response
        memset(buf, 0, 4096);
        int bytesReceived = recv(sock1, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            std::cout << "Error getting response from server\r\n";
        }
        else
        {
            //        Display response
            std::cout << "SERVER> " << std::string(buf, bytesReceived) << "\r\n";
        }
    
}

