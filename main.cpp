#include <iostream>
#include "Renderer.h"
#include "argh.h"

int main(int argc, char* argv[]) {
    int wd = 30, ht = 16;
    Renderer r(wd, ht);
    r.render_init();
    r.draw_bomb(0, 0);
    r.draw_flag(1, 0);
    r.draw_number(wd - 1, ht - 1, 3);
    r.end_on_click();
    return 0;
}
