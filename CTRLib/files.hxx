#include<stdlib.h>
#include<fstream>
#include<filesystem>
#include<map>
#include<string>
using namespace std;
namespace CTRL{
    string getPath(){
        return getenv("HOME");
    }
    string readFile(string filePath){
        std::ifstream fileStream(filePath);
        std::string fileData((std::istreambuf_iterator<char>(fileStream)),(std::istreambuf_iterator<char>())); 
        return fileData;
    }
    string getName(string filePath){
        return filesystem::path(filePath).filename();
    }
    string chopName(string fileName, size_t maxLength){
        if(fileName.size()>maxLength){
            return fileName.substr(0,maxLength-2)+ "..";
        }
        return fileName;
    }
}