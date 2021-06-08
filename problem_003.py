# The prime factors of 13195 are 5, 7, 13 and 29.
# What is the largest prime factor of the number 600851475143 ?

import numpy as np

def solve():
    
    number = 600851475143
    
    max_factor = int(np.sqrt(number))
    print("Max_factor", max_factor)
    
    # Looking for prime numbers
    
    numbers = [i for i in range(1, max_factor+1)]
    is_prime = [True for i in range(max_factor)]
#    print(numbers)
#    print(is_prime)
    
    current_prime_index = 1
    prime_index_condition = current_prime_index < len(is_prime)
    while prime_index_condition:
        print("Current prime number:", current_prime_index+1)
        # We bar the multiples
        is_prime_traversal = 2 * current_prime_index + 1
        condition = is_prime_traversal < len(is_prime)
        while condition:
            is_prime[is_prime_traversal] = False
            is_prime_traversal += current_prime_index + 1
            condition = is_prime_traversal < len(is_prime)
#        print(numbers)
#        print(is_prime)
        # Next prime
        next_prime_index = current_prime_index + 1
        condition = next_prime_index < len(is_prime)
        condition = condition and (is_prime[next_prime_index] == False)
        while condition:
            next_prime_index = next_prime_index + 1
            condition = (next_prime_index < len(is_prime))
            
            condition = condition and (is_prime[next_prime_index] == False)
        current_prime_index = next_prime_index
        prime_index_condition = current_prime_index < len(is_prime)
    
    prime_numbers = [n for n, p in zip(numbers, is_prime) if p]

    for factor in reversed(prime_numbers):
        if number%factor == 0:
            return factor
        
    return
    
print(solve())