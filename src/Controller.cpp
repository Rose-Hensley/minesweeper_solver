#include <iostream>
#include "Controller.h"
#include "Board.h"
#include "Renderer.h"

using std::get;

Controller::Controller(int wd, int ht, int bs)
    : b(Board(wd,ht,bs)), r(Renderer(wd,ht))
{
    r.render_init();
}

void Controller::test() {
    r.end_on_click();
}

void Controller::solve_dumb() {
    while (!b.has_won()) {
        auto click = next_click_dumb();
        int update = click_cell(get<0>(click), get<1>(click));
        if (update == -1) { break; }
    }
    if (b.has_won()) {
        r.draw_win();
    }
    r.end_on_click();
}

void Controller::solve_smart() {
    while(!b.has_won()) {
        if (!flag_smart()) {
            auto click = next_click_smart();
            int update = click_cell(get<0>(click), get<1>(click));
            if (update == -1) { break; }
        }
    }
    if (b.has_won()) {
        r.draw_win();
    }
    r.end_on_click();
}

int Controller::click_cell(int x, int y) {
    int update = b.click_cell(x, y);
    if (update == -2) {
        return update;
    }
    if (update == -1) {
        r.draw_bomb(x, y);
        return update;
    }
    if (update == 0) {
        r.draw_number(x, y, 0);
        click_adjacent_non_flag(x, y);
        return update;
    }
    r.draw_number(x, y, update);
    return update;
}

std::tuple<int, int> Controller::next_click_dumb() {
    return std::tuple<int, int>(rand() % b.get_width(), rand() % b.get_height());
}

void Controller::click_adjacent_non_flag(int x, int y) {
    for (int x_offset = -1; x_offset <= 1; x_offset++) {
        for (int y_offset = -1; y_offset <= 1; y_offset++) {
            if ((x + x_offset >= 0 && x + x_offset < b.get_width()) && (y_offset + y >= 0 && y_offset + y < b.get_height()) && (x_offset != 0 || y_offset != 0)) {
                if (!b.is_flagged(x + x_offset, y + y_offset) && !b.is_visible(x + x_offset, y + y_offset)) {
                    click_cell(x + x_offset, y + y_offset);
                }
            }
        }
    }
}

bool Controller::flag_cell(int x, int y) {
    bool ret = b.flag_cell(x, y);
    if (ret) {
        r.draw_flag(x, y);
    }
    else {
        r.draw_undo_flag(x, y);
    }
    return ret;
}

std::tuple<int, int> Controller::next_click_smart() {
    for (int y = 0; y < b.get_height(); y++) {
        for (int x = 0; x < b.get_width(); x++) {
            if (b.is_visible(x, y)) {

            }
        }
    }
}

bool Controller::flag_smart() {
    return false;
}
