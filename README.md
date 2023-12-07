# Minesweeper Solver
A C++ program that generates boards of minesweeper, solves it, and renders it as it solves.

# Libraries Used
This project uses the graphic library C-Turtle: https://github.com/walkerje/C-Turtle

and the argument command line argument parser argh: https://github.com/adishavit/argh

#Installation
This solver is very easy to install and run, as the external libraries it interfaces with are header-file only packages. Download the repo and build with cmake.

# Run options
Command line options allow for different runs of the solver
```
  -s or --smart
    sets the solver to smart solving
  -n or --novice
    Beginner board, 9x9 with 8 bombs
  -i or --intermediate
    Intermediate board, 16x16 with 40 bombs
  -e or --expert
    Expert board, 30x16 with 99 bombs
  -w=<int> or --width=<int>
    sets the board width to <int>
  -h=<int> or --height=<int>
    sets the board height to <int>
  -b=<int> or --bombs=<int>
    sets number of bombs to <int>
```
