#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "solver_class.hpp"

/*  Box layout
	 |		|
  0  |   1  |	2
	 |	 	|
 - - - - - - - - - -
     |		|
  3	 |   4  |	5
 	 |	 	|
- - - - - - - - - -
	 |		|
  6	 |	 7	|   8
	 |		|
*/

// Reads the puzzle from a text file
solver::solver(std::string str) {
	int number;

	std::ifstream file(str);
	while (file >> number) puzzle.push_back(number);
	file.close();

	// finds all empty cells and stores their location
	for ( int i = 0; i < 9; i++) {
		for ( int j = 0; j < 9; j++) {
			if (puzzle[get_val(i,j)] == 0) {
				empty_cell_row.push_back(i);
				empty_cell_col.push_back(j);
			}
		}
	}

}

// prints the whole sudoku puzzle
void solver::print(void) {
	for (int i = 0; i < puzzle.size(); i++) {

		if ((i%27 == 0)  && (i!=0)) {
			for (int j = 0; j < 9; j++) {
				if ((j%3 == 0) && (j != 0)) std::cout << "  ";
				std::cout << "- ";
			}
			std::cout << "\n";
		}
		if ((i%3==0) && !(i%9==0) ) std::cout << "| ";
		std::cout << puzzle[i] << " ";
		if ( (i+1) % 9 ==0) std::cout << "\n";
	}
}

int solver::get_val(int row, int col) {
	return (row * 9) + col;
}

// Only set valid values
void solver::set_val(int row, int col, int val) {
	if (valid_num(val) || (val == 0)) puzzle[get_val(row, col)] = val;
}

void solver::set_val(int location, int val) {
	if (valid_num(val)) puzzle[location] = val;
}

bool solver::is_valid(int row, int col, int val) {
	int box = find_box(row, col);

	if (! valid_num(val)) return false;

	if (check_row_val(row, val) ||
		check_col_val(col, val) ||
		check_box_val(box, val)) return false;

	return true;
}

// Check to see if a row is valid
bool solver::check_row(int row) {
	int count = 0;
	for (int i = 0; i < 9; i++) {
		count = check_row_val(row, i+1);
		if(count != 1) return false;
	}
	return true;
}

// Check to see if a col is valid
bool solver::check_col(int col) {
	int count = 0;
	for (int i = 0; i < 9; i++) {
		count = check_col_val(col, i+1);
		if(count != 1) return false;
	}
	return true;
}

// Check to see if box is valid
bool solver::check_box(int box) {
	int count = 0;
	for ( int i = 0; i < 9; i++) {
		count = check_box_val(box, i+1);
		if (count != 1) return false;
	}
	return true;
}

bool solver::valid_num(int val) {
	if (val > 0 && val < 10) return true;
	else return false;
}

// Returns how many values in a specific row
int solver::check_row_val(int row, int val) {
	int count = 0;
	for ( int i = 0; i < 9; i++) {
		if (puzzle[i + row*9] == val) count++;
	}

	return count;
}

// Returns how many values in a specific column
int solver::check_col_val(int col, int val) {
	int count = 0;
	for ( int i = 0; i < 9; i++) {
		if (puzzle[i*9 + col] == val) count++;
	}

	return count;
}

// Returns hoy many values in a specific box
int solver::check_box_val(int box, int val) {
	int count = 0;
	int offset = 0;
	box < 3 ? offset = 0 : box < 6 ? offset = 1 : offset = 2;
	for ( int i = 0; i < 3; i++) {
		for ( int j = 0; j < 3; j++) {
			if (puzzle[j+3*(box%3) + 9*i + 27 * offset] == val) count ++;
		}
	}

	return count;
}

int solver::find_box(int row, int col) {
	int box;
	int position = (row * 9) + col; // find position in vector

	position < 27 ? box = 0 : position < 54 ? box = 3 : box = 6;
	return box += (position%9) / 3;
}
