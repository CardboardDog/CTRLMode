#include<ncurses.h>
#include<string>
#include<sstream>
using namespace std;
namespace CTRL{
    void aprintw(WINDOW* window, int y, int x, string text){
        stringstream stream(text);
        string line;
        int lineY = 0;
        while(getline(stream,line,'\n')){
            mvwprintw(window,y+lineY,x,"%s",line.c_str());
            lineY++;
        }
        
    }
}