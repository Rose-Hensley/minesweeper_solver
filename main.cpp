#include <iostream>
#include "Renderer.h"

int main(int argc, char* argv[]) {
    int wd = 30, ht = 16;
    Renderer r(wd, ht);
    r.render_init();
    //r.test();
    r.end_on_click();
    return 0;
}
