/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/

#include <iostream>
using namespace std;

int grid_size = 20;
int path_size = grid_size * 2;

int main() {

	long long int* table;
	table = new long long int[(path_size + 1) * (path_size + 1)];
	// binomial (40 20)
	for (int i = 0; i < path_size + 1; i++) {
		for (int j = 0; j < path_size + 1; j++) {
			table[(path_size + 1) * i + j] = 0;
		}
	}
	table[(path_size + 1) * 0 + 0] = 1;

	for (int n = 1; n < path_size + 1; n++) {
		table[(path_size + 1) * n + 0] = 1;
		table[(path_size + 1) * n + n] = 1;
		for (int k = 1; k < n; k++) {
			table[(path_size + 1) * n + k] = table[(path_size + 1) * (n - 1) + k] + table[(path_size + 1) * (n - 1) + k - 1];
		}
	}

	cout << table[(path_size + 1) * path_size + grid_size];

	delete[] table;
}