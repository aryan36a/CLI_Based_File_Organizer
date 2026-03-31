#include<iostream>
#include<cctype>
#include<string>
#include<filesystem>
#include"organizer.h"

namespace fs=std::filesystem;

int main(int argc, char *argv[])
{
    //Checks argument count
    if(argc!=2){
        std::cerr<<"Usage: "<<argv[0]<<" <folder_path>";
        return 1;
    }
    fs::path sourcePath=argv[1];
    
    //check if path exists
    if (!fs::exists(sourcePath)){
        std::cout<<"The folder doesnt exist\n";
        return 1;
    }

    //checks if path is to a folder or not
    if(fs::is_regular_file(sourcePath)){
        std::cout<<"The path points to a file not a folder\n";
        return 1;
    }

    //checks accessibility
    try{
        fs::directory_iterator(sourcePath);
    }catch (const fs::filesystem_error& e){
        std::cerr<<"Error: Cannot access the directory\n";
        return 1;
    }
     
    //normalize path
    sourcePath=fs::canonical(sourcePath);

    //organizer call
    organize(sourcePath);
return 1;
}