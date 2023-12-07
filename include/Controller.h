#ifndef MINESWEEPER_CONTROLLER_H
#define MINESWEEPER_CONTROLLER_H

using std::tuple, std::get;

#include "Board.h"
#include "Renderer.h"

// Represents the solver controller that renders and solves
class Controller {
private:
    // The given board that the solver will solve
    Board b;

    // The renderer object that will show the game being solved
    Renderer r;

    // Simulates clicking a cell by revealing it and handling anything that happens
    int click_cell(int x, int y);

    // Clicks an adjacent non-flag to the position x,y and renders it
    void click_adjacent_non_flag(int x, int y);

    // Flags the cell at x,y and renders it
    bool flag_cell(int x, int y);

    // Returns the next click for the dumb solver
    std::tuple<int, int> next_click_dumb();

    // Returns the next click for the smart solver
    std::tuple<int, int> next_click_smart();

    // Runs a calc to see if it can flag the position of a bomb, and does so
    //  Returns whether it was successful in flagging or not
    bool flag_smart();

    // A helper function that flags all adjacent cells to a given cell at x,y
    bool flag_all_adj(int x, int y);

public:
    // Generates a controller object
    //  wd is the width of the board
    //  ht is the height of the board
    //  bs is the number of bombs hidden on the board
    Controller(int wd, int ht, int bs);

    // Runs the solver with a poor win rate
    void solve_dumb();

    // Runs the solver with a much higher win rate
    void solve_smart();
};

#endif //MINESWEEPER_CONTROLLER_H
