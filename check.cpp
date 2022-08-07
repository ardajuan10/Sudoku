#include "sudoku.h"
#include <iostream>

bool sudoku::check_box(cell_position cell_pos) {
	cell_position start_pos;
	bool num_ok = true;

	for (int i = 0; i < DIM_BOX;i++) {
		if (cell_pos.row < (SUDO_DIM -(i*DIM_BOX))) {
			start_pos.row = (SUDO_DIM - ((i + 1)*DIM_BOX));

		}
		if (cell_pos.column < (SUDO_DIM - (i*DIM_BOX))) {
			start_pos.column = (SUDO_DIM - ((i + 1)*DIM_BOX));

		}

	}
	//int count = 0;
	for (int i=0; i < DIM_BOX; i++) {
		for (int j=0; j < DIM_BOX; j++){
			//count++;
			if ((i+start_pos.row) != cell_pos.row || (j+start_pos.column) != cell_pos.column) {
				//count++;
				if (grid[i + start_pos.row][j + start_pos.column].number == grid[cell_pos.row][cell_pos.column].number) {
					num_ok = false;
				}
				
			}
			
		}
	}
	//cout << count << endl;
	return num_ok;
}

bool sudoku::check_row(cell_position cell_pos) {
	//cell_position current_row;
	bool num_ok = true;
	//current_row.row = cell_pos.row;
	for (int j = 0; j < SUDO_DIM; j++) {
		if (j != cell_pos.column) {
			if (grid[cell_pos.row][j].number == grid[cell_pos.row][cell_pos.column].number) {
				num_ok = false;
			}
		}
	}
	return num_ok;
}

bool sudoku::check_column(cell_position cell_pos) {
	//cell_position current_row;
	bool num_ok = true;
	//current_row.row = cell_pos.row;
	for (int i = 0; i < SUDO_DIM; i++) {
		if (i != cell_pos.row) {
			if (grid[i][cell_pos.column].number == grid[cell_pos.row][cell_pos.column].number) {
				num_ok = false;
			}
		}
	}
	return num_ok;
}

bool sudoku::check_cell(cell_position cell_pos) {
	return check_box(cell_pos) && check_column(cell_pos) && check_row(cell_pos);
}
