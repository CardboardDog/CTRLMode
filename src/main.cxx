#include<stdio.h>
#include<ncurses.h>
#include<files.hxx>
#include<vector>
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
    WINDOW* window = initscr();
    if(window == 0x0)return -1;
    noecho();
    raw();
    start_color();
    nodelay(window,TRUE);
    getmaxyx(window,height,width);
    init_pair(1,COLOR_BLACK,COLOR_WHITE);
    while(running){
        attron(COLOR_PAIR(0));
        mvprintw(0,0,"%s",get<2>(openFiles[0]).c_str());
        wrefresh(window);
        char input = getch();
        running = !(input == ('e'&0x1F));
    }
    endwin();
}