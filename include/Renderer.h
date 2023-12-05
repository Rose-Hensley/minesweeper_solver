#ifndef MINESWEEPER_RENDERER_H
#define MINESWEEPER_RENDERER_H

class Renderer {
private:
    int block_size;

    void draw_horz();

    void draw_vert();

    std::tuple<int, int> get_pixel_pos(int x, int y);

public:
    Renderer(int grid_wd, int grid_ht);

    void render_init(int wd, int ht);

    void write_number(int x, int y, int n);

};


#endif //MINESWEEPER_RENDERER_H
