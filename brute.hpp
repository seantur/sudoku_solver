#ifndef BRUTE
#define BRUTE

#include "solver_class.hpp"

class brute: public solver {
	public:
		brute(std::string);
		int simplify(int);
		void brute_solve(void);
		int any_solution(int row, int col);
	private:

};

#endif
