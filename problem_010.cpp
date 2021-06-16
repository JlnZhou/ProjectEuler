/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/
#include <iostream>
using namespace std;

int n_max = 2000000;

int main() {

	// We look for all the prime numbers
	bool* is_prime;
	is_prime = new bool[n_max];

	for (int i = 0; i < n_max; i++) {
		is_prime[i] = true;
	}
	is_prime[0] = false;
	is_prime[1] = false;

	for (int i = 2; i < n_max; i++) {
		if (is_prime[i]) {
			int j = 2;
			while (i*j < n_max) {
				is_prime[i * j] = false;
				j++;
			}
		}
	}

	// Summation
	long long int result = 0;
	for (int i = 0; i < n_max; i++) {
		if (is_prime[i]) {
			result += long long int(i);
		}
	}

	/* For debugging
	for (int i = 0; i < n_max; i++) {
		cout << i << " " << is_prime[i] << endl;
	}
	*/

	cout << result << endl;

	// free memory
	delete[] is_prime;
}