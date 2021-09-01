/*
Problem 27 - Quadratic primes

Euler discovered the remarkable quadratic formula: n^2+n+41
It turns out that the formula will produce 40 primes for the consecutive integer values 0<=n<=39. 
However, when n = 40, 40^2+40+41 = 40(40+1)+41 is divisible by 41, and certainly when n = 41, 41^2+41+41 is clearly divisible by 41.

The incredible formula n^2-79n+1601 was discovered, which produces 80 primes for the consecutive values 0<=n<=79. 
The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

n^2+an+b, where |a|<1000 and |b|<1000

where |n| is the modulus/absolute value of n.

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.
*/


/*
For n = b, b is a divisor, so the number of primes is lower than b.
b has to be a prime number, therefore positive (n=0)
The maximum value of the expression that we have to consider is is b^2 + ab + b <= 1000^2 + 1000^2 + 1000 = 2 000 000 + 1000 = 2 001 000
*/

#include <iostream>
using namespace std;

long long int max_a_b = 1000;
long long int max_val = 2 * max_a_b * max_a_b + max_a_b;


int main() {

	// Looking for the prime numbers below max_val
	bool* isprime_table = new bool[max_val + 1];
	isprime_table[0] = false;
	isprime_table[1] = false;
	for (int i = 2; i < (max_val + 1); i++) {
		isprime_table[i] = true;
	}
	for (int i = 2; i < (max_val + 1); i++) {
		long long int current_number = i+i;
		while (current_number < (max_val + 1)) {
			isprime_table[current_number] = false;
			current_number += i;
		}
	}

	long long int max_number = 0;
	long long int max_product = 0;
	//Looking for the right combination
	for (long long int a = -max_a_b + 1; a < max_a_b; a++) {
		for (long long int b = 2; b < max_a_b; b++) {
			if (isprime_table[b]) {
				long long int current_consecutive = 1;
				bool continue_n = true;
				while (continue_n) {
					long long int current_expression = current_consecutive * current_consecutive + current_consecutive * a + b;
					if (current_expression>0 && isprime_table[current_expression]) {
						current_consecutive += 1;
					}
					else {
						continue_n = false;
					}
				}
				if (current_consecutive >= max_number) {
					max_number = current_consecutive;
					max_product = a * b;
				}
			}
		}
	}
	cout << max_product << endl;

	delete[] isprime_table;

}