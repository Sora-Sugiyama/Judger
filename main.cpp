//
//  main.cpp
//  testMachine
//
//  Created by Sora Sugiyama on 9/18/25.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

int main(int argc, const char * argv[]) {
    if(argc!=3){
        std::cout<<"Wrong arguments.\nUseage: "<<argv[0]<<" <filename> <assingment_ID>"<<std::endl;
        return 1;
    }
    
    std::string target = argv[1];
    {
        std::ifstream fin(target);
        std::ofstream fout("target.hpp");
        
        if(!fin){
            std::cerr<<"Invalid filename"<<std::endl;
            return 2;
        }
        fout<<"#ifndef target_hpp\n#define target_hpp\n";
        
        std::string s;
        while(getline(fin,s)){
            fout<<s<<"\n";
        }
        
        fout<<"#include \"judger/"<<argv[2]<<".hpp\"\n";
        fout<<"#endif /* target_hpp */"<<std::endl;
    }
    
    if(std::system("g++ -std=gnu++17 judge.cpp -o tmp 2> compile.log")!=0){
        std::cerr<<"Failed to compile"<<std::endl;
        return 3;
    }
    
    if(std::system((std::string("./tmp ")+argv[2]).c_str())){
        std::cerr<<"Failed to excute judger (Runtime Error)"<<std::endl;
        return 4;
    }
    
    std::system("rm tmp");
    
    return 0;
}
