//
//  a1-2-A.hpp
//  testMachine
//
//  Created by Sora Sugiyama on 9/19/25.
//

#ifndef a1_2_A_h
#define a1_2_A_h

#include <iostream>
using namespace std;

#include <sstream>
#include <string>

void judge(string in){
    stringstream ss(in);
    int n;ss>>n;
    
    cout<<funcA(n)<<endl;
}

#endif /* a1_2_A_h */
