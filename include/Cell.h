#ifndef MINESWEEPER_CELL_H
#define MINESWEEPER_CELL_H

class Cell {
private:
    // is this cell revealed
    bool visible;

    // is this cell flagged
    bool flagged;

    // -1 for bomb
    int val;

public:
    Cell();

    bool is_visible();

    bool is_flagged();

    int get_val();

    void set_val(int n);

    bool flag();

    void make_visible();
};

#endif //MINESWEEPER_CELL_H
