#include<iostream>
#include<cctype>
#include<filesystem>
#include<string>
namespace fs =std::filesystem;

int main()
{
    std::string source;
    std::cout<<"Enter source folder: ";
    std::getline(std::cin, source);
    fs::path src=source;
    int files=0;
    if (!fs::exists(src)) {
        std::cout << "Path does not exist.\n";
        return 1;
    }

    if (!fs::is_directory(src)) {
        std::cout << "Input path is not a folder.\n";
        return 1;
    }

    try {
        for (const auto& file : fs::recursive_directory_iterator(src)) {
            if (fs::is_regular_file(file.path())) {
                std::cout << file.path().filename();
                std::cout << " -> ";
                std::cout << file.path().extension() << "\n";
                files++;
            }
        }
        std::cout << "Total number of files are: " << files << "\n";
    } catch (const fs::filesystem_error& e) {
        std::cout << "Filesystem error: " << e.what() << "\n";
        return 1;
    }

return 0;
}