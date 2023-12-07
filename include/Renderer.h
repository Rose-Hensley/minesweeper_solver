#ifndef MINESWEEPER_RENDERER_H
#define MINESWEEPER_RENDERER_H

// A renderer object that draws each event in minesweeper
class Renderer {
private:
    // The size of each block
    int block_size;

    // Grid width, or how many blocks across
    int wd;

    // Grid height, or how many blocks tall
    int ht;

    // Draws horizontal lines to make the grid center in the screen
    void draw_horz();

    // Draws vertical lines to make the grid center in the screen
    void draw_vert();

    // Gets the pixel position of intersection on the grid with 0,0 being top left
    std::tuple<int, int> get_pixel_pos(int x, int y);

    // Gets the pixel position to actually draw a number, cell, or bomb
    std::tuple<int, int> get_draw_pos(int x, int y);

    // Gets the various different colors for each different type of number
    std::string get_number_color(int n);

public:
    // Generates a renderer object that draws the board as it is being played
    //  grid_wd is the width of the grid in number of cells
    //  grid_ht is the height of the grid in number of cells
    Renderer(int grid_wd, int grid_ht);

    // Renders the initial board setup
    void render_init();

    // Draws a number at x,y and selects the correct color to display
    void draw_number(int x, int y, int n);

    // Draws a bomb at x,y
    void draw_bomb(int x, int y);

    // Draws a flag at x,y
    void draw_flag(int x, int y);

    // Unflags the position at x,y
    void draw_undo_flag(int x, int y);

    // Draws the win message at the center of the screen
    void draw_win();

    // Asks the C-Turtle library to wait for a click before closing the screen
    void end_on_click();
};


#endif //MINESWEEPER_RENDERER_H
