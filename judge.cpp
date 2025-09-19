//
//  judge.cpp
//  testMachine
//
//  Created by Sora Sugiyama on 9/18/25.
//

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <cstdio>
#include "target.hpp"

int main(int argc,const char * argv[]){
    std::string dir{argv[1]};
    dir="data/"+dir+"/";
    
    int n;
    {
        std::ifstream fin(dir+"num");
        if(!fin){
            cerr<<"Cannot excute judger. (Wrong dataset)"<<endl;
        }
        fin>>n;
        fin.close();
    }
    
    int numAc=0;
    for(int i=1;i<=n;i++){
        std::string s=std::to_string(i);
        s=std::string(2-s.size(),'0')+s;
        
        std::string in;
        {
            std::ifstream fin(dir+s+".in");
            std::string tmp;
            while(getline(fin,tmp))in+=tmp+"\n";
            
            fin.close();
        }
        
        {
            ofstream fout("tmpout");
            auto backup=std::cout.rdbuf();
            std::cout.rdbuf(fout.rdbuf());
            judge(in);
            
            std::cout.rdbuf(backup);
        }
        
        {
            std::ifstream fin("tmpout"),ans(dir+s+".ans");
            std::string tmp,cor;
            while(getline(fin,tmp)){
                if(!getline(ans,cor)){
                    if(getline(fin,tmp)){
                        std::cout<<"Output exceed at "<<s<<std::endl;
                        goto skip;
                    }
                }
                if(tmp.back()==' ')tmp.pop_back();
                if(cor.back()==' ')cor.pop_back();
                
                if(cor!=tmp){
                    std::cout<<"Wrong answer at "<<s<<std::endl;
                    goto skip;
                }
            }
            if(getline(ans,cor)){
                if(cor!=""||getline(ans,cor)){
                    std::cout<<"Wrong answer at "<<s<<std::endl;
                    goto skip;
                }
            }
            
            numAc++;
            skip:;
        }
    }
    
    if(numAc==n)std::cout<<"* Accepted *"<<std::endl;
    std::cout<<"- End of judge -"<<std::endl;
    
    return 0;
}
