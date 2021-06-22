/*
Lexicographic permutations

A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include <iostream>
#include <algorithm> 
using namespace std;

int n_max = 9;
int n_perm = 1000000;

int main() {

	int* table = new int[n_max + 1];
	for (int i = 0; i < n_max + 1; i++) {
		table[i] = i;
	}
	sort(table, table + n_max + 1);

	for (int i = 1; i < n_perm; i++) {
		next_permutation(table, table + n_max + 1);
	}

	for (int i = 0; i < n_max + 1; i++) {
		cout << table[i];
	}

	delete[] table;
}