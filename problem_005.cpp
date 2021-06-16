/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/
#include <iostream>
#include <math.h>
#include <Eigen/Dense>

long long int n_max = 20;

long long int calc_gcd(long long int a, long long int b) {
    while (b != 0) {
        long long int remainder = b;
        b = a % b;
        a = remainder;
    }
    return a;
}

long long int calc_lcm(long long int a, long long int b) {
    return a*b/calc_gcd(a, b);
}

int main()
{
    long long int result = 1;
    for (long long int i = 1; i <= n_max; i++) {
        result = calc_lcm(result, i);
        std::cout << "i: " << i << " gcd: " << calc_gcd(result, i) << std::endl;
        std::cout << "i: " << i << " lcm: " << result << std::endl;
    }

    std::cout << result << std::endl;
}

