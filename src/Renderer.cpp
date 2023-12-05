#include <tuple>
#include <algorithm>
#include "CTurtle.hpp"
#include "Renderer.h"

using std::get;
namespace ct = cturtle;
ct::TurtleScreen scr(600, 600);
ct::Turtle rt(scr);

Renderer::Renderer(int grid_wd, int grid_ht) {
    block_size = std::min(scr.window_width() / grid_wd,
                          scr.window_height() / grid_ht);
}

void Renderer::render_init(int wd, int ht) {
    //rt.hideturtle();
    draw_horz();
    draw_vert();
    write_number(1, 1, 9);
    scr.exitonclick();
}

void Renderer::write_number(int x, int y, int n) {
    auto pixel_pos = get_pixel_pos(x, y);
    rt.penup();
    rt.goTo(get<0>(pixel_pos), get<1>(pixel_pos));
    rt.pendown();
    rt.write(std::to_string(n), "default", {"black"}, 1.5f, cturtle::TEXT_ALIGN_CENTER);
}

void Renderer::draw_horz() {
    for (int i = 1; i*block_size < scr.window_height(); i++) {
        int y = -scr.window_height()/2 + i * block_size;
        rt.penup();
        rt.goTo(-scr.window_width()/2, y);
        rt.pendown();
        rt.goTo(scr.window_width(), y);
    }
}

void Renderer::draw_vert() {
    for (int i = 1; i*block_size < scr.window_height(); i++) {
        int x = -scr.window_width()/2 + i * block_size;
        rt.penup();
        rt.goTo(x, -scr.window_height()/2);
        rt.pendown();
        rt.goTo(x, scr.window_height()/2);
    }
}

std::tuple<int, int> Renderer::get_pixel_pos(int x, int y) {
    return {-scr.window_width()/2 + x * block_size,
            scr.window_height()/2 - (y + 1) * block_size };

}
