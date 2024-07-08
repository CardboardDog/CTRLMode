#include<ncurses.h>
#include<chrono>
using namespace std::chrono;
namespace CTRL{
    unsigned long long lastTime;
    bool blinkMode = true;
    void acursor(WINDOW* window){
        int y,x;
        getyx(window,y,x);
        unsigned long long thisTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        if((thisTime-lastTime)>500){
            blinkMode = !blinkMode;
            lastTime = thisTime;
        }
        if(blinkMode){
            chtype replaceChar = mvwinch(window,y,x);
            mvwaddch(window,y,x,replaceChar+A_REVERSE);
        }
        attron(A_NORMAL);
    }
    void mvwcursor(WINDOW* window, int y, int x){ // not optimal :(
        wmove(window,y,x);
        acursor(window);
    }
}