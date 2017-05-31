#ifndef SOLVER_CLASS
#define SOLVER_CLASS

#include <vector>

class solver {
	public:
		solver(std::string);
		void print(void);
		int get_val(int, int);
		void set_val(int, int, int);
		void set_val(int, int);

	protected:
		std::vector<int> puzzle;
		std::vector<int> empty_cell_row;
		std::vector<int> empty_cell_col;
		bool is_valid(int, int, int);
		bool valid_num(int);

	private:

		bool check_row(int);
		bool check_col(int);
		bool check_box(int);
		int check_row_val(int, int);
		int check_col_val(int, int);
		int check_box_val(int, int);
		int find_box(int, int);


};

#endif
