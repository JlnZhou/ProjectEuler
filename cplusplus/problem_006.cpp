/*
The sum of the squares of the first ten natural numbers is, 385
The square of the sum of the first ten natural numbers is, 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 2640.
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/
#include <iostream>
#include <math.h>

long long int n_max = 100;

long long int sum_of_squares(long long int n) {
    long long int result = n * (n + 1) * (2 * n + 1) / 6;
    return result;
}

long long int square_of_sum(long long int n) {
    long long int result = n * (n + 1) / 2;
    result = result * result;
    return result;
}

int main()
{
    long long int result = square_of_sum(n_max) - sum_of_squares(n_max);

    std::cout << square_of_sum(n_max) << std::endl;
    std::cout << sum_of_squares(n_max) << std::endl;
    std::cout << result << std::endl;
}

