/*
Reciprocal cycles

A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

#include <iostream>
using namespace std;

int max_d = 1000;
int d_init = 2;
int max_cycle = 0;
int d_max_cycle = 0;

int main() {

	int current_d = d_init;
	while (current_d < max_d){

		int* remainders = new int[current_d];
		for (int i = 0; i < current_d; i++) {
			remainders[i] = 0;
		}
		int current_remainder = 1;
		int current_step = 0;

		bool continue_division = true;
		while (continue_division) {
			while (current_remainder < current_d) {
				current_remainder *= 10;
				current_step += 1;
			}
			current_remainder %= current_d;
			if (current_remainder == 0) {
				continue_division = false;
			}
			else {
				if (remainders[current_remainder]>0) {
					continue_division = false;
					int current_cycle = current_step - remainders[current_remainder];
					if (current_cycle > max_cycle) {
						max_cycle = current_cycle;
						d_max_cycle = current_d;
					}
				}
				else {
					remainders[current_remainder] = current_step;
				}
			}
		}

		current_d++;

		delete[] remainders;
	}
	cout << d_max_cycle << endl;

}