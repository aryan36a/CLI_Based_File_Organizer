#include<iostream>
#include<cctype>
#include<filesystem>
#include"organizer.h"
#include<string>

namespace fs=std::filesystem;

void organize(const fs::path& sourcePath){
    int count=0;
    try{
        for(const auto& entry :fs::recursive_directory_iterator(sourcePath)){
            if(entry.is_regular_file()){
                count++;
            }
        }
    }catch (const fs::filesystem_error& e){
        std::cerr<<"Error while processing the directory\n";
        return;
    }
    std::cout<<"Total number of files: "<<count<<"\n";
    return;
}