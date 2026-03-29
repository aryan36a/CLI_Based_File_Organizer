#include<iostream>
#include<cctype>
#include<filesystem>
#include<string>
namespace fs=std::filesystem;

int main(){
/*
{
    fs::path p="D:/projects/CLI Based File Organizer/src/include/test.txt";

    if(fs::exists(p)){
        std::cout<<p.filename()<<"\n";
        std::cout<<p.extension()<<"\n";
        std::cout<<p.parent_path()<<"\n";
        std::cout<<p.stem()<<"\n";
        std::cout<<fs::exists(p);
        return 0;

    }
    else{
    std::cout<<"The file Does Not Exist"<<"\n";
    return 0;
    }

    for (const auto& entry :fs::recursive_directory_iterator("D:/projects/CLI Based File Organizer/src/include/testing")){
        std::cout<<entry.path()<<"\n";
    }
    std::string file_path;
    std::cout<<"Enter File Path"<<"\n";
    std::getline(std::cin, file_path);
    std::cout<<file_path;
    fs::path p=file_path;
    std::string main_directory=p.parent_path().string();
    if(fs::exists(p)==1 && p.extension()==".txt"){
        std::string text_path=main_directory+R"(\text files)";
        fs::create_directory(text_path);
        std::cout<<"Folder Created";
        for (const auto& entry :fs::recursive_directory_iterator(main_directory)){
            if (entry.stem()==".txt"){
                fs::copy(entry,"")
            }
        }
    }
}
*/
    std::string source;
    std::string target;
    std::cout<<"Enter source path: ";
    std::getline(std::cin, source);
    fs::path src=source;
    std::cout<<"\n"<<"Enter Target path: ";
    std::getline(std::cin,target);
    if (fs::exists(src)&&src.extension()==".txt"){
        fs::path out_dir = fs::path(target) / "text files";
        fs::create_directory(out_dir);
        std::string main_directory=src.parent_path().string();
        fs::path scan_root=main_directory;
        int i=0;
        for(const auto& entry :fs::recursive_directory_iterator(scan_root)){
            if(entry.path().extension()==".txt"){
                fs::path tgt = out_dir / entry.path().filename();
                fs::copy_file(entry.path(), tgt);   
                i++;
            }
        std::cout<<i<<"Files have been moved in total"<<"/n";
        }
    }
}