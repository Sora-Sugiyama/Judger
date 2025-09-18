#ifndef target_hpp
#define target_hpp
void mySort(int arr[], int n){
    if(n<=1)return;
    while(--n){
        for(int* it=arr; it<arr+n; it++){
            if(*it > *(it+1)){
                *it ^= *(it+1);
                *(it+1) ^= *it;
                *it ^= *(it+1);
            }
        }
    }
}

void printArray(int arr[],int size){
    for(int* it=arr; it<arr+size; it++){
        std::cout << *it << " ";
    }
    std::cout<<std::endl;
}
#include "judger/a1-1.hpp"
#endif /* target_hpp */
