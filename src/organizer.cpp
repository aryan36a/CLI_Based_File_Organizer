#include<iostream>
#include<cctype>
#include<filesystem>
#include"organizer.h"
#include<string>
#include<unordered_map>
namespace fs=std::filesystem;

//Map basic extensions
std::string getCat(const std::string extension) {
    static std::unordered_map<std::string, std::string> mapping={
        {".jpg","images"},{".png","image"},{".jpeg","image"},
        {".pdf","document"},{".doc","document"},{".docx","document"},
        {".mp4","video"},{".mkv","video"}
    };
    if(mapping.count(extension)){
        return mapping[extension];
    }
    return "others";
}

void organize(const fs::path& sourcePath){
    int count=0;
    try{
        for(const auto& entry :fs::directory_iterator(sourcePath)){
            if(!fs::is_regular_file(entry.path())){
                continue;
            }
            //Get extension
            std::string ext=entry.path().extension().string();
            //get file type
            std::string type=getCat(ext);
            //create parth
            fs::path targetPath=sourcePath/type;
            //create dir if does not exist
            if(!fs::exists(targetPath)){
                fs::create_directory(targetPath);
            }
            //move file
            fs::rename(entry.path(),targetPath/entry.path().filename());
        }
    }catch(const fs::filesystem_error& e){
        std::cerr<<"Error occured during organizing: "<<e.what()<<"\n";
    }
}