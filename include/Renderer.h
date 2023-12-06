#ifndef MINESWEEPER_RENDERER_H
#define MINESWEEPER_RENDERER_H

class Renderer {
private:
    int block_size;

    // Grid width, or how many blocks across
    int wd;

    // Grid height, or how many blocks tall
    int ht;

    void draw_horz();

    void draw_vert();

    std::tuple<int, int> get_pixel_pos(int x, int y);

    std::tuple<int, int> get_write_pos(int x, int y);

    std::string get_number_color(int n);

public:
    Renderer(int grid_wd, int grid_ht);

    void render_init();

    void draw_number(int x, int y, int n);

    void draw_bomb(int x, int y);

    void draw_flag(int x, int y);

    void end_on_click();

    void test();

};


#endif //MINESWEEPER_RENDERER_H
