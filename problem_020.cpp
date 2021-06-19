/*
Factorial digit sum

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

#include <iostream>
#include <math.h>
using namespace std;

int n = 100;
int table_size = (log(n) / log(10)) * n;

void table_mult(int factor, int* table) {
	int to_add = 0;
	for (int i = 0; i < table_size; i++) {
		int temp = table[i] * factor;
		temp += to_add;
		table[i] = temp % 10;
		to_add = temp / 10;
	}
}

int main() {

	int* table;
	table = new int[table_size];
	for (int i = 0; i < table_size; i++) {
		table[i] = 0;
	}
	table[0] = 1;

	for (int i = 1; i <= n; i++) {
		table_mult(i, table);
	}

	long long int result = 0;
	for (int i = 0; i < table_size; i++) {
		result += table[i];
	}
	cout << result << endl;

	delete[] table;
}