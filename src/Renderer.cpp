#include <tuple>
#include "CTurtle.hpp"
#include "Renderer.h"

namespace ct = cturtle;
ct::TurtleScreen scr(500, 500);
ct::Turtle rt(scr);

std::tuple<int, int> get_pixel_pos(int x, int y, int block_wd, int block_ht) {
    return std::tuple<int, int>(
            -scr.window_width()/2 + x * block_wd,
            -scr.window_height()/2 + y * block_ht)
}

void draw_horz(int offset) {
    rt.penup();
    rt.goTo(-scr.window_width()/2, -scr.window_height()/2);
    for (int i = 0; i*offset < scr.window_height(); i++) {
        rt.pendown();
        rt.goTo(scr.window_width(), i*);
    }
    rt.pendown();
}

void render_init(int wd, int ht) {
    rt.hideturtle();
    draw_horz(ht);

    scr.exitonclick();
}

void render_two() {
    rt.pendown();
    rt.goTo(-scr.window_width()/2, 200);
    rt.right(90);
    rt.forward(100);
    scr.exitonclick();
}
