//
//  a1-2-C.hpp
//  testMachine
//
//  Created by Sora Sugiyama on 9/20/25.
//

#ifndef a1_2_C_h
#define a1_2_C_h

#include <iostream>
using namespace std;

#include <sstream>
#include <string>
#include <memory>
#include <utility>

using Alloc=std::allocator<char>;
using Traits=std::allocator_traits<Alloc>;

Alloc alloc;

void judge(string in){
    in.pop_back();
    
    const int n=(int)in.size();
    char *str=Traits::allocate(alloc,n+1);
    memcpy(str,in.c_str(),n);
    
    
    funcC(str,0,n-1);
    
    Traits::deallocate(alloc,str,n);
}

#endif /* a1_2_C_h */
