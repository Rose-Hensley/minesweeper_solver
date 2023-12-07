#include <tuple>
#include <algorithm>
#include "CTurtle.hpp"
#include "Renderer.h"

using std::get;
namespace ct = cturtle;
ct::TurtleScreen scr(1150, 800);
ct::Turtle rt(scr);

Renderer::Renderer(int grid_wd, int grid_ht) : wd(grid_wd), ht(grid_ht) {
    block_size = std::min(scr.window_width() / grid_wd,
                          scr.window_height() / grid_ht);
}

void Renderer::render_init() {
    rt.hideturtle();
    draw_horz();
    draw_vert();
}

void Renderer::draw_number(int x, int y, int n) {
    auto pixel_pos = get_draw_pos(x, y);
    auto color = get_number_color(n);
    rt.penup();
    rt.goTo(get<0>(pixel_pos), get<1>(pixel_pos));
    rt.pendown();
    rt.write(std::to_string(n), "default", {color}, 1.75f, cturtle::TEXT_ALIGN_CENTER);
}

void Renderer::draw_bomb(int x, int y) {
    auto pos = get_draw_pos(x, y);
    rt.penup();
    rt.goTo(get<0>(pos), get<1>(pos));
    rt.pendown();
    rt.write("B", "default", {"dark orange"}, 1.75f, cturtle::TEXT_ALIGN_CENTER);
}

void Renderer::draw_flag(int x, int y) {
    auto pos = get_draw_pos(x, y);
    rt.penup();
    rt.goTo(get<0>(pos), get<1>(pos));
    rt.pendown();
    rt.write("F", "default", {"dark violet"}, 1.75f, cturtle::TEXT_ALIGN_CENTER);
}

void Renderer::draw_undo_flag(int x, int y) {
    auto pos = get_draw_pos(x, y);
    rt.penup();
    rt.goTo(get<0>(pos), get<1>(pos));
    rt.pendown();
    rt.write("F", "default", {"white"}, 1.75f, cturtle::TEXT_ALIGN_CENTER);
}

void Renderer::draw_win() {
    rt.penup();
    rt.goTo(0, 0);
    rt.pendown();
    rt.write("WIN", "default", {"VioletRed4"}, 3.5f, cturtle::TEXT_ALIGN_CENTER);
}

void Renderer::end_on_click() {
    scr.exitonclick();
}

void Renderer::draw_horz() {
    for (int i = 0; i <= ht; i++) {
        rt.penup();
        auto left = get_pixel_pos(0, i);
        auto right = get_pixel_pos(wd, i);
        rt.goTo(get<0>(left), get<1>(left));
        rt.pendown();
        rt.goTo(get<0>(right), get<1>(right));
    }
}

void Renderer::draw_vert() {
    for (int i = 0; i <= wd; i++) {
        rt.penup();
        auto up = get_pixel_pos(i, 0);
        auto down = get_pixel_pos(i, ht);
        rt.goTo(get<0>(up), get<1>(up));
        rt.pendown();
        rt.goTo(get<0>(down), get<1>(down));
    }
}

std::tuple<int, int> Renderer::get_pixel_pos(int x, int y) {
    std::tuple<int, int> top_left = {
            -scr.window_width()/2 + x * block_size,
            scr.window_height()/2 - y * block_size
    };
    return {
        get<0>(top_left) + (scr.window_width() - block_size * wd) / 2,
        get<1>(top_left) - (scr.window_height() - block_size * ht) / 2
    };
}

std::tuple<int, int> Renderer::get_draw_pos(int x, int y) {
    auto upper_left = get_pixel_pos(x, y);
    return {
        get<0>(upper_left) + (block_size * 1) / 4,
        get<1>(upper_left) - block_size
    };
}

std::string Renderer::get_number_color(int n) {
    std::string ret;
    switch(n) {
        case 0: ret = "dark slate gray";
            break;
        case 1: ret = "blue";
            break;
        case 2: ret = "dark sea green";
            break;
        case 3: ret = "red";
            break;
        case 4: ret = "blue violet";
            break;
        case 5: ret = "dark red";
            break;
        case 6: ret = "cyan3";
            break;
        case 7: ret = "black";
            break;
        case 8: ret = "dark gray";
            break;
        default: ret = "black";
    }
    return ret;
}
