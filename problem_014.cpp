/*
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <iostream>
#include <math.h>
using namespace std;

long long int max_number = 1000000;

long long int sequence_size(long long int n, long long int* table, bool* visit_table) {
	if (n == 1) {
		return 1;
	}
	else {
		long long int next_index = 0;
		if (n % 2 == 0) {
			next_index = n / 2;
		}
		else {
			next_index = 3 * n + 1;
		}
		if (n < max_number) {
			if (visit_table[n]) {
				return table[n];
			}
			else {
				long long int next_size = sequence_size(next_index, table, visit_table);
				long long int result = next_size + 1;
				table[n] = result;
				visit_table[n] = true;
				return result;
			}
		}
		else {
			long long int next_size = sequence_size(next_index, table, visit_table);
			return next_size + 1;
		}
	}
}

int main() {

	long long int* table;
	bool* visit_table;
	table = new long long int[max_number];
	visit_table = new bool[max_number];

	for (long long int i = 0; i < max_number; i++) {
		table[i] = 0;
		visit_table[i] = false;
	}
	table[0] = 1;
	table[1] = 1;
	visit_table[0] = true;
	visit_table[1] = true;

	long long int max_index = 0;
	long long int max_chain = 0;
	for (long long int i = 1; i < max_number; i++) {
		long long int current_size = sequence_size(i, table, visit_table);
		if (current_size > max_chain) {
			max_chain = current_size;
			max_index = i;
			cout << "i = " << i << " size = " << table[i] << endl;
		}
	}

	delete[] table, visit_table;

}