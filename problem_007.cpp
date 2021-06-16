/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
*/
#include <iostream>
#include <math.h>
#include <list>
using namespace std;

long long int n_max = 10001;

int main()
{
    list<long long int> list_prime = {2};
    int n_found = 1;
    long long int current_number = 2;
    while (n_found < n_max) {
        current_number += 1;
        bool is_prime = true;
        for (long long int prime : list_prime) {
            is_prime &= (current_number%prime != 0);
        }
        if (is_prime) {
            n_found += 1;
            list_prime.push_back(current_number);
        }

    }
    /*
    for (long long int prime : list_prime) {
        cout << prime << endl;
    }
    */
    cout << list_prime.back() << endl;
}

