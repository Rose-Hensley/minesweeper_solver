#ifndef MINESWEEPER_CELL_H
#define MINESWEEPER_CELL_H

// Represents a cell on the given board of minesweeper
class Cell {
private:
    // is this cell revealed
    bool visible;

    // is this cell flagged
    bool flagged;

    // -1 for bomb
    // 0-9 for other value
    int val;

public:
    // Generates a cell object that contains all information about itself
    Cell();

    // Whether the cell's value is visible to the player or not
    bool is_visible();

    // Whether the cell is flagged or not
    bool is_flagged();

    // Gets the value hidden under this cell
    //  -1 for bomb
    int get_val();

    // Sets the value for the cell to be used in initialization
    void set_val(int n);

    // Flips whether this cell is flagged or not
    bool flag();

    // Makes this cell visible to the player
    void make_visible();
};

#endif //MINESWEEPER_CELL_H
