#include<iostream>
#include<cctype>
#include<filesystem>
#include<algorithm>
#include"organizer.h"
#include<string>
#include<unordered_map>
#include<unordered_set>
namespace fs=std::filesystem;

//Map basic extensions
std::string getCat(const std::string extension){
    static std::unordered_map<std::string, std::string> mapping={
        //Images
        {".jpg","image"},{".jpeg","image"},{".png","image"},
        {".gif","image"},{".bmp","image"},{".webp","image"},
        {".tiff","image"},{".svg","image"},{".ico","image"},
        //Documents
        {".pdf","document"},{".doc","document"},{".docx","document"},
        {".txt","document"},{".rtf","document"},{".odt","document"},
        {".ppt","document"},{".pptx","document"},
        {".xls","document"},{".xlsx","document"},
        //Videos
        {".mp4","video"},{".mkv","video"},{".avi","video"},
        {".mov","video"},{".wmv","video"},{".flv","video"},
        {".webm","video"},{".mpeg","video"},
        //Audio
        {".mp3","audio"},{".wav","audio"},{".aac","audio"},
        {".flac","audio"},{".ogg","audio"},{".m4a","audio"},
        //Archives
        {".zip","archive"},{".rar","archive"},{".7z","archive"},
        {".tar","archive"},{".gz","archive"},{".bz2","archive"},
        //Code
        {".cpp","code"},{".c","code"},{".h","code"},{".hpp","code"},
        {".py","code"},{".java","code"},{".js","code"},
        {".ts","code"},{".html","code"},{".css","code"},
        {".json","code"},{".xml","code"},{".sh","code"},
        //Executables/Binaries
        {".exe","binary"},{".out","binary"},{".bin","binary"},
        {".apk","binary"},{".msi","binary"},
        //Fonts
        {".ttf","font"},{".otf","font"},{".woff","font"},{".woff2","font"},
        //Disk Images
        {".iso","disk"},{".img","disk"}
    };
    if(mapping.count(extension)){
        return mapping[extension];
    }
    return "others";
}
//set unique file name for same files
fs::path getUniquePath(const fs::path& targetPath){
    if(!fs::exists(targetPath)){
        return targetPath;
    }
    fs::path parentPath=targetPath.parent_path();
    std::string stem=targetPath.stem().string();
    std::string ext=targetPath.extension().string();
    int fileCount=1;
    while(true){
        fs::path newPath=parentPath/(stem+"_"+std::to_string(fileCount)+ext);
        if(!fs::exists(newPath)){
            return newPath;
        }
        fileCount++;
    }
}

void organize(const fs::path& sourcePath){
    int count=0;
    static std::unordered_set<std::string> categories = {
        "image", "video", "document", "others",
        "audio", "archive", "code", "binary", "font", "disk"};
    try{
        for(const auto& entry :fs::recursive_directory_iterator(sourcePath)){
            std::string parent=entry.path().parent_path().filename().string();
            if(categories.count(parent) ){
                continue;
               }
            if(!fs::is_regular_file(entry.path())){
                continue;
            }
            //Get extension
            std::string ext=entry.path().extension().string();
            std::transform(ext.begin(), ext.end(), ext.begin(),
               [](unsigned char c){ return static_cast<char>(std::tolower(c)); });

            //get file type
            std::string type=getCat(ext);
            //create parth
            fs::path targetPath=sourcePath/type;
            //create dir if does not exist
            if(!fs::exists(targetPath)){
                fs::create_directory(targetPath);
            }
            //create valid path
            fs::path targetFile = targetPath / entry.path().filename();
            fs::path finalPath = getUniquePath(targetFile);
            //move file
            fs::rename(entry.path(),finalPath);
            //display organized files
            std::cout<<"Moved: "<<entry.path().filename()<<"->"<<type<<"\n";
            count++;
        }
    }catch(const fs::filesystem_error& e){
        std::cerr<<"Error occured during organizing: "<<e.what()<<"\n";
    }
    std::cout<<"Moved a total of: "<<count<<" files\n";
}