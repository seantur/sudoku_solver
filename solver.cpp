#include <iostream>
#include <chrono>
#include "solver_class.hpp"
#include "brute.hpp"

int main ()
{
	brute mySolver("file.txt");

	std::cout << "Puzzle:" << std::endl;
	mySolver.print();

	std::cout << "\n\nSolving..." << std::endl;

	auto t1 = std::chrono::high_resolution_clock::now();
	mySolver.brute_solve();
	auto t2 = std::chrono::high_resolution_clock::now();
	mySolver.print();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";


	return 0;
}
