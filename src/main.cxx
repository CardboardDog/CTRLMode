#include<stdio.h>
#include<ncurses.h>
#include<files.hxx>
#include<vector>
#include<border.hxx>
#include<output.hxx>
#include<cursor.hxx>
int main(){
    bool running,editing,folder=false;
    running=editing=true;
    int currentTab = 0;
    std::string openFolder = "";
    std::vector<std::tuple<bool,std::string,std::string,std::string,bool>> openFiles;
    int width, height;
    openFiles.push_back(
        std::tuple<bool,std::string,std::string,std::string,bool>(
            false,
            CTRL::getPath(),
            "Welcome to CTRLMode!\nPress CTRL+O to open a file or directory.\nPress CTRL+E to exit.\nEnjoy :)",\
            "Unnamed",
            true
        )
    );
    initscr();
    noecho();
    raw();
    start_color();
    nodelay(stdscr,TRUE);
    getmaxyx(stdscr,height,width);
    curs_set(0);    
    WINDOW* tabsWindow = newwin(3,width,0,0);
    WINDOW* textWindow = newwin(height-6,width-25,3,25);
    WINDOW* commandWindow = newwin(3,width,height-6,0);
    WINDOW* folderWindow = newwin(height-6,25,3,0);
    while(running){
        getmaxyx(stdscr,height,width);
        wresize(textWindow,height-6,width-25);
        wresize(commandWindow,3,width);
        wresize(folderWindow,height-6,25);
        wresize(tabsWindow,3,width);
        mvwin(commandWindow,height-3,0);
        werase(textWindow);
        werase(commandWindow);
        werase(folderWindow);
        werase(tabsWindow);
        CTRL::aprintw(commandWindow,1,1,">");
        CTRL::acursor(commandWindow);
        CTRL::aprintw(textWindow,1,1,get<2>(openFiles[currentTab]));
        for(int tab=0;tab<openFiles.size();tab++){
            if(currentTab == tab)wattron(tabsWindow,A_REVERSE);
            CTRL::aprintw(tabsWindow,1,1+((tab)*10),"\t ");
            CTRL::aprintw(tabsWindow,1,1+(tab*10),get<3>(openFiles[tab]));
            CTRL::aprintw(tabsWindow,1,(tab+1)*10,"|");
            if(get<4>(openFiles[tab]))CTRL::aprintw(tabsWindow,1,((tab+1)*10)-1,"*");
            wattroff(tabsWindow,A_REVERSE);
        }
        if(folder){
        }else{
            CTRL::aprintw(folderWindow,1,1,"No folder open.\nPress CTRL+O to open!");
        }
        CTRL::aborder(textWindow);
        CTRL::aborder(commandWindow);
        CTRL::aborder(folderWindow);
        CTRL::aborder(tabsWindow);
        CTRL::mvwcursor(textWindow,4,8);
        wrefresh(textWindow);
        wrefresh(commandWindow);
        wrefresh(folderWindow);
        wrefresh(tabsWindow);
        char input = getch();
        running = !(input == ('e'&0x1F));
    }
    endwin();
}