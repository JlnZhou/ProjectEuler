/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/
#include <iostream>
using namespace std;

int sum_abc = 1000;

int main() {

	long long int result = 0;
	bool stop = false;
	bool condition = true;
	long long int a = 0;
	while (condition) {
		for (long long int b = a; sum_abc - a - b > b; b++) {
			long long int c = sum_abc - a - b;
			if (a * a + b * b == c * c) {
				result = a * b * c;
				stop = true;
			}
		}
		a++;
		condition = (a <= sum_abc) & (!stop);
	}

	cout << result << endl;

}

