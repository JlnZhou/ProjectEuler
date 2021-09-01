/*
Problem 28 - Number spiral diagonals
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

#include <iostream>
#include <Eigen/Dense>
using namespace std;

long long int table_size = 1001;
long long int current_step = 1;


int main() {

	Eigen::Matrix<long long int, Eigen::Dynamic, Eigen::Dynamic> table(table_size, table_size);
	for (int i = 0; i < table_size; i++) {
		for (int j = 0; j < table_size; j++) {
			table(i, j) = 0;
		}
	}
	Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> is_visited(table_size, table_size);
	for (int i = 0; i < table_size; i++) {
		for (int j = 0; j < table_size; j++) {
			is_visited(i, j) = false;
		}
	}
	
	
	// We populate the matrix
	long long int last_i = table_size / 2, last_j = table_size / 2;
	table(last_i, last_j) = current_step;
	is_visited(last_i, last_j) = true;
	long long int current_i = last_i, current_j = last_j + 1;
	while ((current_j < table_size - 1) || (current_i >0)) { // The last number is in the upper right corner
		current_step += 1;
		table(current_i, current_j) = current_step;
		is_visited(current_i, current_j) = true;
		// std::cout << current_step << " i: " << current_i << " j: " << current_j << endl;
		if ((current_j - last_j) == 1) {
			if (is_visited(current_i + 1, current_j)) {
				last_i = current_i;
				last_j = current_j;
				current_j += 1;
				// std::cout << "Right" << endl;
			}
			else {
				last_i = current_i;
				last_j = current_j;
				current_i += 1;
				// std::cout << "Down" << endl;
			}
			continue;
		}
		if ((current_i - last_i) == 1) {
			if (is_visited(current_i, current_j - 1)) {
				last_i = current_i;
				last_j = current_j;
				current_i += 1;
				// std::cout << "Down" << endl;
			}
			else {
				last_i = current_i;
				last_j = current_j;
				current_j -= 1;
				// std::cout << "Left" << endl;
			}
			continue;
		}
		if ((current_j - last_j) == -1) {
			if (is_visited(current_i - 1, current_j)) {
				last_i = current_i;
				last_j = current_j;
				current_j -= 1;
				// std::cout << "Left" << endl;
			}
			else {
				last_i = current_i;
				last_j = current_j;
				current_i -= 1;
				// std::cout << "Up" << endl;
			}
			continue;
		}
		if ((current_i - last_i) == -1) {
			if (is_visited(current_i, current_j + 1)) {
				last_i = current_i;
				last_j = current_j;
				current_i -= 1;
				// std::cout << "Up" << endl;
			}
			else {
				last_i = current_i;
				last_j = current_j;
				current_j += 1;
				// std::cout << "Right" << endl;
			}
			continue;
		}
	}
	current_step += 1;
	table(current_i, current_j) = current_step;
	is_visited(current_i, current_j) = true;
	// std::cout << current_step << " i: " << current_i << " j: " << current_j << endl;


	//Summation
	long long int result = 0;
	for (int i = 0; i < table_size; i++) {
		result += table(i, i);
	}
	// std::cout << "OK" << endl;
	for (int i = 0; i < table_size; i++) {
		result += table(table_size - i - 1, i);
	}
	// std::cout << "OK" << endl;
	result -= 1;

	std::cout << result << endl;

}