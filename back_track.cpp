#include "sudoku.h"
#include <iostream>

cell_position sudoku::move_cell(bool forward,cell_position cell_pos) {
	if (forward) {
		if (cell_pos.column < SUDO_DIM-1) {
			cell_pos.column++;
		}
		else  {
			cell_pos.row++;
			cell_pos.column = 0;
		}
		//else {
		//	cerr << "cell cant be incremented\n";
		//}
	}
	else {
		if (cell_pos.column > 0) {
			cell_pos.column--;
		}
		else if (cell_pos.row > 0) {
			cell_pos.row--;
			cell_pos.column = SUDO_DIM-1;
		}
		else {
			cerr << "cell cant be decremented\n";
		}
	}
	return cell_pos;
}

void sudoku::back_track() {
	cell_position current_pos;
	current_pos.row = 0;
	current_pos.column = 0;
	
	while (current_pos.row < SUDO_DIM ) {
		if (grid[current_pos.row][current_pos.column].given == false) {
			if (grid[current_pos.row][current_pos.column].number == 0) { 
				grid[current_pos.row][current_pos.column].number++; 
			}
			
						
			

			if (grid[current_pos.row][current_pos.column].number > SUDO_DIM) {
				grid[current_pos.row][current_pos.column].number = 0;
				current_pos = move_cell(BACKWARDS, current_pos);
				while (grid[current_pos.row][current_pos.column].given) {
					current_pos = move_cell(BACKWARDS, current_pos);
				}
				grid[current_pos.row][current_pos.column].number++;
				

			}
				

			else if (check_cell(current_pos)) {
				current_pos = move_cell(FORWARDS, current_pos);
			}
			else {
				grid[current_pos.row][current_pos.column].number++;
			}
		
			
			
		}
		else {
			current_pos = move_cell(FORWARDS, current_pos);
		}

	}
	cout << "Result is:\n";
	print_grid();
}