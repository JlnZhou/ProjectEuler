/*
1000-digit Fibonacci number

The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/

#include <iostream>
using namespace std;

int n_digits = 1000;

int main() {

	int* fibo_0 = new int[n_digits];
	for (int i = 0; i < n_digits; i++) {
		fibo_0[i] = 0;
	}
	fibo_0[0] = 1;
	int* fibo_1 = new int[n_digits];
	for (int i = 0; i < n_digits; i++) {
		fibo_1[i] = 0;
	}
	fibo_1[0] = 1;
	long long int current_index = 2;

	bool stop = false;
	while (!stop) {
		current_index += 1;
		int to_add = 0;
		for (int i = 0; i < n_digits; i++) {
			int temp_sum = fibo_0[i] + fibo_1[i] + to_add;
			fibo_0[i] = fibo_1[i];
			fibo_1[i] = temp_sum % 10;
			to_add = temp_sum / 10;
		}
		stop = (fibo_1[n_digits - 1] != 0);
	}
	cout << current_index << endl;

	delete[] fibo_0; fibo_1;

}