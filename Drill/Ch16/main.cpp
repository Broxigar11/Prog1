#include "GUI/Lines_window.h"
#include "GUI/Graph.h"

int main()
{
    Lines_window win {Point{100,100}, 1280, 720, "Lines"};
    
    return gui_main();
}