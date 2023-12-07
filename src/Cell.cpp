#include "Cell.h"

Cell::Cell() : visible(false), flagged(false), val(-20) { }

bool Cell::is_visible() {
    return visible;
}

bool Cell::is_flagged() {
    return flagged;
}

int Cell::get_val() {
    return val;
}

void Cell::set_val(int n) {
    val = n;
}

bool Cell::flag() {
    flagged = !flagged;
    return flagged;
}

void Cell::make_visible() {
    visible = true;
}
