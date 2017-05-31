#include <iostream>
#include "brute.hpp"
#include <string>

/* From wikipedia:
] Briefly, a program would solve a puzzle by placing the digit "1" in the first
 cell and checking if it is allowed to be there. If there are no violations
 (checking row, column, and box constraints) then the algorithm advances to the
 next cell, and places a "1" in that cell. When checking for violations, if it
 is discovered that the "1" is not allowed, the value is advanced to "2". If a
 cell is discovered where none of the 9 digits is allowed, then the algorithm
 leaves that cell blank and moves back to the previous cell. The value in that
 cell is then incremented by one. This is repeated until the allowed value in
  the last (81st) cell is discovered. */


brute::brute(std::string str)
: solver(str)
{}

int brute::simplify(int val) {
	if (val == 0) return 1;
	while ( val > 9) val -= 9;
	return val;
}

// working on the logic for this
void brute::brute_solve(void) {
	int i = 0;
	int j, k;
	int val;

	// loop over every zero
	// set value to 1		   <<
	// check if valid			|
	// if valid, go to next zero|
	// else check

	while ( i < empty_cell_row.size()) {
		j = any_solution(empty_cell_row[i], empty_cell_col[i]);
		if (j) i++;
		else i--;
	}
}

int brute::any_solution(int row, int col) {

	int tmp = puzzle[get_val(row, col)];

	for ( int i=tmp  ; i < 10 ; i++) {
		if (is_valid(row, col, i)) {
			set_val(row, col, i);
			return 1;
		}
	}
	set_val(row, col, 0);
	return 0;
}
