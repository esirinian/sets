//
//  set.cpp
//  
//
//  Created by Eric Sirinian on 11/1/16.
//
//

#include "set.hpp"
#include <iostream>

using namespace std;

int main()
{
    Set<string> set1(5);
    
    set1.userInput();
    
    cout << "Set 1: ";
    
    set1.display();
}






