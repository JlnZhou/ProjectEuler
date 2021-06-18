/*
Power digit sum

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/

#include <iostream>
using namespace std;

int exponent = 1000;

void doubling(int* table) {
	int to_add = 0;
	for (int i = 0; i < exponent - 1; i++) {
		table[i] *= 2;
		table[i] += to_add;
		to_add = 0;
		if (table[i] > 9) {
			to_add = table[i] / 10;
			table[i] = table[i] % 10;
		}
	}
}

int main() {

	int* table;
	table = new int[exponent];
	table[0] = 1;
	for (int i = 1; i < exponent; i++) {
		table[i] = 0;
		cout << table[i];
	}
	cout << endl;

	int current_exponent = 0;
	for (int k = 0; k < exponent; k++) {
		doubling(table);
		for (int i = 0; i < 10; i++) {
			cout << table[i];
		}
		cout << endl;
	}

	long long int result = 0;
	for (int i = 0; i < exponent; i++) {
		result += long long int(table[i]);
	}

	cout << result << endl;

	delete[] table;
}