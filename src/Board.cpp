#include "Board.h"
#include <random>

Board::Board(int wd, int ht, int bs) : width(wd), height(ht), bombs(bs) {
    for (int row = 0; row < height; row++) {
        vector<unique_ptr<Cell>> curr_row;
        for (int col = 0; col < width; col++) {
            curr_row.push_back(std::make_unique<Cell>());
        }
        cells.push_back(std::move(curr_row));
    }
    init_bombs();
    set_vals();
}

void Board::init_bombs() {
    std::vector<int> v(width * height);
    for (int i = 0; i < v.size(); i++) { v[i] = i; }

    for (int i = 0; i < bombs; i++) {
        int idx = rand() % v.size();
        int x_pos = v[idx] % width;
        int y_pos = v[idx] / width;
        v.erase(v.begin() + idx);
        cells[y_pos][x_pos]->set_val(-1);
    }
}

void Board::set_vals() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cells[y][x]->set_val(calc_val(x, y));
        }
    }
}

int Board::calc_val(int x, int y) {
    if (cells[y][x]->get_val() == -1) {
        return -1;
    }
    int ret = 0;
    for (int x_offset = -1; x_offset <= 1; x_offset++) {
        for (int y_offset = -1; y_offset <= 1; y_offset++) {
            if (!oob(x + x_offset, y + y_offset) && (x_offset != 0 || y_offset != 0)) {
                if (cells[y + y_offset][x + x_offset]->get_val() == -1) { ret++; }
            }
        }
    }
    return ret;
}

bool Board::oob(int x, int y) {
    return x < 0 || x >= width || y < 0 || y >= height;
}

int Board::click_cell(int x, int y) {
    if (cells[y][x]->is_flagged()) {
        return -2;
    }
    if (cells[y][x]->is_visible()) {
        return -2;
    }
    cells[y][x]->make_visible();
    return cells[y][x]->get_val();
}

bool Board::flag_cell(int x, int y) {
    return cells[y][x]->flag();
}

bool Board::has_won() {
    return width * height - bombs == get_num_visible();
}

int Board::get_num_visible() {
    int ret = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (cells[y][x]->is_visible()) { ret++; }
        }
    }
    return ret;
}

int Board::get_width() {
    return width;
}

int Board::get_height() {
    return height;
}

int Board::get_value(int x, int y) {
    return cells[y][x]->get_val();
}

int Board::is_flagged(int x, int y) {
    return cells[y][x]->is_flagged();
}

int Board::is_visible(int x, int y) {
    return cells[y][x]->is_visible();
}

int Board::get_num_adj_flags(int x, int y) {

}
