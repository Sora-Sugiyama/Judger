//
//  a1-1.hpp
//  testMachine
//
//  Created by Sora Sugiyama on 9/18/25.
//

#ifndef a1_1_h
#define a1_1_h

#include <iostream>
using namespace std;

#include <sstream>
#include <string>

int arr[5555];
void judge(string in){
    stringstream ss(in);
    int n=0,a;
    
    while(ss>>a){
        arr[n++]=a;
    }
    
    mySort(arr,n);
    printArray(arr,n);
}


#endif /* a1_1_h */
