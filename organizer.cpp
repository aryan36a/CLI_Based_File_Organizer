#include<iostream>
#include<cctype>
#include<string>
#include<filesystem>

namespace fs=std::filesystem;

int main(int argc, char *argv[])
{
    if(argc!=2){
        std::cerr<<"Usage: "<<argv[0]<<" <folder_path>\n";
        return 1;
    }
    fs::path sourcePath=argv[1];
    if (!fs::exists(sourcePath)){
        std::cout<<"The folder doesn't exist\n";
        return 1;
    }
    if(!fs::is_directory(sourcePath)){
        std::cout<<"The path points to a file, not a folder\n";
        return 1;
    }

    try {
        int count=0;
        for(const auto& entry : fs::recursive_directory_iterator(sourcePath)){
            if(fs::is_regular_file(entry.path())){
                std::cout<<entry.path().filename().string()<<"\n";
                count++;
            }
        }
        std::cout<<"Total files: "<<count<<"\n";
    } catch (const fs::filesystem_error& e) {
        std::cerr<<"Directory exists but is not accessible: "<<e.what()<<"\n";
        return 1;
    }

    std::cout<<"The path is valid\n";
    std::cout<<"Path: "<<sourcePath<<"\n";
    return 0;
}