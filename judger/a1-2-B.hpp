//
//  a1-2-B.hpp
//  testMachine
//
//  Created by Sora Sugiyama on 9/19/25.
//

#ifndef a1_2_B_h
#define a1_2_B_h

#include <iostream>
using namespace std;

#include <sstream>
#include <string>

void judge(string in){
    stringstream ss(in);
    int n;ss>>n;
    
    funcB(n,2);
}

#endif /* a1_2_B_h */
