/*
Names score

Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

long long int calc_name_value(string name) {
	long long int result = 0;
	for (char c : name) {
		result += int(c) - int('A') + 1;
	}
	return result;
}

int main() {

	ifstream file("p022_names.txt");
	string line;
	string input_string = "";
	if (file.is_open()) {
		while (getline(file, line)) {
			input_string.append(line);
		}
		file.close();
	}
	
	int string_length = input_string.length();
	int string_index = 0;
	int name_begin = 0;
	int n_names = 0;
	bool in_name = false;
	list<string> list_names;
	for (int i = 0; i < string_length; i++) {
		if (input_string[i] == '\"') {
			if (in_name) {
				n_names += 1;
				list_names.push_back(input_string.substr(name_begin, i - name_begin));
				in_name = !in_name;
			}
			else {
				name_begin = i + 1;
				in_name = !in_name;
			}
		}
	}
	list_names.sort();
	long long int i = 0;
	long long int result = 0;
	for (string name : list_names) {
		i++;
		result += calc_name_value(name) * i;
	}

	cout << result << endl;
	cout << "OK" << endl;

}