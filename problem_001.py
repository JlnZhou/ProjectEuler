# If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
# Find the sum of all the multiples of 3 or 5 below 1000.

def solve():

    limit = 1000
    result = 0

    # for 3
    i = 3
    while i < limit:
        result += i
        i += 3
        
    # for 5
    i = 5
    j = 1
    while i < limit:
        if j == 3:
            j = 0
        else:
            result += i
        i += 5
        j += 1
    return result


print(solve())