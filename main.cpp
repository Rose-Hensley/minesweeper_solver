#include <iostream>
#include "Renderer.h"

int main(int argc, char* argv[]) {
    int wd = 8, ht = 10;
    Renderer r(wd, ht);
    r.render_init(wd, ht);

    return 0;
}
