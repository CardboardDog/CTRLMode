#include<ncurses.h>
namespace CTRL{
    void aborder(WINDOW* window){
        wborder(window,
            ACS_VLINE,
            ACS_VLINE,
            ACS_HLINE,
            ACS_HLINE,
            ACS_ULCORNER,
            ACS_URCORNER,
            ACS_LLCORNER,
            ACS_LRCORNER
        );
    }
}