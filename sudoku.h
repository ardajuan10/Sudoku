#pragma once
#include <iostream>
#define SUDO_DIM 9
#define DIM_BOX 3
#define FORWARDS true
#define BACKWARDS false
using namespace std;

struct sudoku_grid {
	int number;
	bool given;
	
};
struct cell_position {
	int row;
	int column;
};

class sudoku {
public:
	void update();
private:
	
	void read_data();
	cell_position move_cell(bool, cell_position);
	void print_grid();
	bool check_box(cell_position);
	bool check_row(cell_position);
	bool check_column(cell_position);
	bool check_cell(cell_position);
	void back_track();
	
	
	sudoku_grid grid[SUDO_DIM][SUDO_DIM];


};

