#include<stdio.h>
#include<ncurses.h>
#include<files.hxx>
#include<vector>
#include<border.hxx>
#include<output.hxx>
int main(){
    bool running,editing,folder=false;
    running=editing=true;
    std::string openFolder = "";
    std::vector<std::tuple<bool,std::string,std::string>> openFiles;
    int width, height;
    openFiles.push_back(
        std::tuple<bool,std::string,std::string>(
            false,
            CTRL::getPath(),
            "Welcome to CTRLMode!\nPress CTRL+O to open a file or directory.\nPress CTRL+E to exit.\nEnjoy :)"
        )
    );
    initscr();
    noecho();
    raw();
    start_color();
    nodelay(stdscr,TRUE);
    getmaxyx(stdscr,height,width);
    curs_set(0);
    WINDOW* textWindow = newwin(height-3,width-25,0,25);
    WINDOW* commandWindow = newwin(3,width,height-3,0);
    WINDOW* folderWindow = newwin(height-3,25,0,0);
    while(running){
        CTRL::aprintw(commandWindow,1,1,">");
        CTRL::aprintw(textWindow,1,1,get<2>(openFiles[0]));
        if(folder){
        }else{
            CTRL::aprintw(folderWindow,1,1,"No folder open.\nPress CTRL+O to open!");
        }
        CTRL::aborder(textWindow);
        CTRL::aborder(commandWindow);
        CTRL::aborder(folderWindow);
        wrefresh(textWindow);
        wrefresh(commandWindow);
        wrefresh(folderWindow);
        char input = getch();
        running = !(input == ('e'&0x1F));
    }
    endwin();
}