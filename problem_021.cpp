/*
Amicable numbers

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. 
The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

#include <iostream>
#include <math.h>
using namespace std;

int n_max = 10000;

long long int calc_sum_divisors(int n) {
	int division_limit = sqrt(n);
	long long result = 0;
	for (long long int i = 1; i <= division_limit; i++) {
		if (n % i == 0) {
			result += i;
			result += n / i;
		}
	}
	result -= n;
	if (n % division_limit == 0) {
		result -= division_limit;
	}
	return result;
}

int main() {

	bool* is_amicable = new bool[n_max + 1];
	for (int i = 0; i <= n_max; i++) {
		is_amicable[i] = false;
	}
	long long int* sum_divisors = new long long int[n_max + 1];
	for (int i = 0; i <= n_max; i++) {
		sum_divisors[i] = 0;
	}
	for (int i = 1; i <= n_max; i++) {
		sum_divisors[i] = calc_sum_divisors(i);
	}

	for (int i = 1; i <= n_max; i++) {
		if (sum_divisors[i] <= n_max) {
			if ((sum_divisors[sum_divisors[i]] == i)&(sum_divisors[i] != i)) {
				is_amicable[i] = true;
			}
		}
	}

	long long int result = 0;
	for (int i = 1; i <= n_max; i++) {
		if (is_amicable[i]) {
			result += i;
			cout << i << endl;
		}
	}
	
	cout << result << endl;

	delete[] is_amicable, sum_divisors;
	
}