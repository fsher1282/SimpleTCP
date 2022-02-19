//
//  caeserCipher.cpp
//  TCP-Server
//
//  Created by Daniel Mai Fisher on 2/2/22.
//  Copyright © 2022 Daniel Mai Fisher. All rights reserved.
//

#include "caeserCipher.hpp"

// Constructor
CaeserCipher::CaeserCipher(){
    key = 1;
}


int CaeserCipher::generateKey(){
    // Generate a random key for each message which will be embeded later
    key = 1 + rand() % 12;
    return key;
}

std::string CaeserCipher::encrypt(int key, std::string message){
    std::string encrypted_message = "";
    encrypted_message += char(key);
    
    for (int i = 0; i<message.length(); i++) {
        char ch = message[i];
        //encrypt for lowercase letter
        if (ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            
        }
        //encrypt for uppercase letter
        else if (ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if (ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            
        }
   
        encrypted_message += ch;
    }
    return encrypted_message;
}


std::string CaeserCipher::decrypt(std::string message){
    std::string decrypted_message = "";
    char ch;
    //extract hidden key
    int hkey=int(message[0]);
    
    for(int i = 1; i<=message.length(); i++) {
        ch = message[i];
        
        //decrypt for lowercase letter
        if(ch >= 'a' && ch <= 'z') {
            ch = ch - hkey;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            
        }
        //decrypt for uppercase letter
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - hkey;
            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
           
        }
        
        decrypted_message += ch;
    }

    return decrypted_message;
}
