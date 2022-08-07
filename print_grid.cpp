#include "sudoku.h"
#include <iostream>

void sudoku::print_grid() {
	for (int i = 0; i < SUDO_DIM; i++) {
		for (int j = 0; j < SUDO_DIM; j++) {
			cout << grid[i][j].number<< " ";
		}
		cout << endl;
	}
	/*
	cout << endl << endl;
	for (int i = 0; i < SUDO_DIM; i++) {
		for (int j = 0; j < SUDO_DIM; j++) {
			cout << grid[i][j].given << " ";
		}
		cout << endl;
	}
	*/
}