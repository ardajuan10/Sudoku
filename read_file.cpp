#include "sudoku.h"
#include <iostream>
#include <fstream>


void sudoku::read_data() {
	ifstream infile("arda.txt");
	
	//int a, count = 0;
	if (!infile) {
		cerr << "Couldnt open file\n";
	}
	else {
		//int column = 0, row = 0;
		int count = 0;
		


		//infile >> grid[row][column].number; 

		for (int i = 0; i < SUDO_DIM; i++) {
			for (int j = 0; j < SUDO_DIM; j++) {
				/*
				if (infile.eof()) {
					cerr << "Not enough parameters in the file" << endl;

				}
				*/

				infile >> grid[i][j].number;
				if (grid[i][j].number == 0) {
					grid[i][j].given = false;
				}
				else {
					grid[i][j].given = true;
				}
				count++;

				/*
				if (infile.eof()) {
					cerr << "Not enough parameters in the file" << endl;

				}
				*/
				
				
				
			}
			
		}
		int temp;
		infile >> temp;
		
		if (!infile.eof()) {
			cerr << "Too much parameters in the file" << endl;
		}
		
		cout << "items found: "<<count<<endl;

		cout << "Input sudoku is:\n";
		print_grid();


	}
	infile.close();


}

