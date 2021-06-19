/*
Counting Sundays

You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.

A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <iostream>
using namespace std;

int n_year = 100;
int n_month = 12;
int year_0 = 1900;

int next_month_day(int current_year, int current_month, int current_day) {
	if ((current_month == 1) | (current_month == 3) | (current_month == 5) | (current_month == 7) | (current_month == 8) | (current_month == 10) | (current_month == 12)) {
		return (current_day + 31) % 7;
	}
	else {
		if ((current_month == 4) | (current_month == 6) | (current_month == 9) | (current_month == 11)) {
			return (current_day + 30) % 7;
		}
		else {
			// february
			bool is_leap = (current_year % 4 == 0);
			if (current_year % 100 == 0) {
				is_leap = (current_year % 400 == 0);
			}
			if (is_leap) {
				return (current_day + 29) % 7;
				cout << current_year << endl;
			}
			else {
				return (current_day + 28) % 7;
			}
		}
	}
	
}

int main() {

	int* table;
	table = new int[(n_year + 1) * n_month];
	int string_index = 0;
	for (int i = 0; i < n_year + 1; i++) {
		for (int j = 0; j < n_month; j++) {
			table[i * n_month + j] = 0;
		}
	}

	table[0 * n_month + 0] = 0; // monday
	for (int j = 1; j < n_month; j++) {
		table[0 * n_month + j] = next_month_day(year_0, j, table[0 * n_month + j - 1]);
	}
	for (int i = 1; i <= n_year; i++) {
		table[i * n_month + 0] = next_month_day(year_0 + i, n_month, table[(i - 1) *n_month + n_month-1]);
		for (int j = 1; j < n_month; j++) {
			table[i * n_month + j] = next_month_day(year_0 + i, j, table[i * n_month + j - 1]);
		}
	}

	int long long result = 0;
	for (int i = 1; i <= n_year; i++) {
		for (int j = 0; j < n_month; j++) {
			if (table[i * n_month + j] == 6) {
				result += 1;
			}
		}
	}
	cout << result << endl;

	delete[] table;
}