/*
Non-abundant sums

A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. 
For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. 
By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. 
However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include <iostream>
#include <math.h>
#include <list>
using namespace std;

int n_max = 28123;

bool calc_is_abundant(int n) {
	int div_max = sqrt(n);
	int sum_div = 0;
	for (int i = 1; i <= div_max; i++) {
		if (n % i == 0) {
			sum_div += i;
			sum_div += n / i;
		}
	}
	sum_div -= n;
	if (div_max * div_max == n) {
		sum_div -= div_max;
	}
	bool result = sum_div > n;
	return result;
}

int main() {
	
	list<int> list_abundant;
	for (int i = 1; i <= n_max; i++) {
		if (calc_is_abundant(i)) {
			list_abundant.push_back(i);
		}
	}

	bool* table = new bool[n_max + 1];
	for (int i = 0; i <= n_max; i++) {
		table[i] = false;
	}

	for (int a : list_abundant) {
		for (int b : list_abundant) {
			if (a + b <= n_max) {
				table[a + b] = true;
			}
		}
	}

	long long int result = 0;
	for (int i = 0; i <= n_max; i++) {
		if (!table[i]) {
			result += i;
		}
	}

	cout << result << endl;
}