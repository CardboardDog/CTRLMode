#include<stdlib.h>
#include<fstream>
#include<map>
#include<string>
using namespace std;
namespace CTRL{
    string getPath(){
        return getenv("HOME");
    }
}