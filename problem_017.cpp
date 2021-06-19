/*
Number letter counts

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) 
contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

#include <iostream>
using namespace std;

int main() {

	long long int* count_1_9;
	count_1_9 = new long long int[10];
	count_1_9[0] = 0;
	count_1_9[1] = 3;
	count_1_9[2] = 3;
	count_1_9[3] = 5;
	count_1_9[4] = 4;
	count_1_9[5] = 4;
	count_1_9[6] = 3;
	count_1_9[7] = 5;
	count_1_9[8] = 5;
	count_1_9[9] = 4;
	long long int* count_10_90;
	count_10_90 = new long long int[10];
	count_10_90[0] = 0;
	count_10_90[1] = 3;
	count_10_90[2] = 6;
	count_10_90[3] = 6;
	count_10_90[4] = 5;
	count_10_90[5] = 5;
	count_10_90[6] = 5;
	count_10_90[7] = 7;
	count_10_90[8] = 6;
	count_10_90[9] = 6;
	long long int count_11_19 = 6 + 6 + 8 + 8 + 7 + 7 + 9 + 8 + 8;
	long long int count_100 = 7;
	long long int count_1000 = 8;
	long long int count_and = 3;

	long long int count_1_99 = 0;
	for (int i = 1; i <= 9; i++) {
		count_1_99 += count_1_9[i];
	}
	count_1_99 += count_10_90[1];
	count_1_99 += count_11_19;
	for (int i = 2; i <= 9; i++) {
		count_1_99 += count_10_90[i];
		for (int j = 1; j <= 9; j++) {
			count_1_99 += count_10_90[i] + count_1_9[j];
		}
	}

	long long int result = 0;
	result += count_1_99;
	for (int i = 1; i <= 9; i++) {
		result += count_1_9[i] + count_100;
		result += 99 * (count_1_9[i] + count_100 + count_and);
		result += count_1_99;
	}
	result += count_1_9[1] + count_1000;

	cout << result << endl;

	delete[] count_1_9, count_10_90;
}