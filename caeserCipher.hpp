//
//  caeserCipher.hpp
//  TCP-Server
//
//  Created by Daniel Mai Fisher on 2/2/22.
//  Copyright © 2022 Daniel Mai Fisher. All rights reserved.
//

#ifndef caeserCipher_hpp
#define caeserCipher_hpp
#include <string>
#include <stdio.h>
class CaeserCipher{
  private:
    int key;
    
public:
    CaeserCipher ();
    int generateKey();
    std::string encrypt(int, std::string);
    std::string decrypt(std::string);
};
#endif /* caeserCipher_hpp */
