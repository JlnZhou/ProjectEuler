/* 
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3 - digit numbers.
*/

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <Eigen/Dense>
using namespace std;

int is_palindrome(int n) {
    string digits = to_string(n);
    int n_size = digits.length();
    bool result = true;
    for (int i = 0; i < n_size/2; i++) {
        result = result && (digits[i] == digits[n_size - i - 1]);
    }
    if (result){
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{

    int min_number = 100;
    int max_number = 999;
    int size = max_number - min_number + 1;

    Eigen::VectorXi vec(size);
    for (int i = 0; i < size; i++) {
        vec(i) = min_number + i;
    }
    Eigen::MatrixXi tab(size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            tab(i, j) = vec(i) * vec(j);
        }
    }
    Eigen::MatrixXi tab_palindrome(size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            tab_palindrome(i, j) = is_palindrome(tab(i, j));
        }
    }

    int k = 2 * (size - 1);
    bool condition = (k >= 0);
    int result = 0;
    while (condition) {
        // std::cout << k << std::endl;
        for (int i = 0; i <= k; i++) {
            int j = k - i;
            if (i < size && j < size) {
                if (tab_palindrome(i, j) && tab(i, j) > result) {
                    result = tab(i, j);
                    condition = false;
                }
            }
        }
        k--;
        condition = condition && k >= 0;
    }
        
    // std::cout << vec << std::endl;
    // std::cout << tab << std::endl;
    // std::cout << tab_palindrome << std::endl;
    std::cout << result << std::endl;

    return 0;
}
