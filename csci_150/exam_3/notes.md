# Exam 3 Notes
## Recursion
##
    sum = summation i = 1 to n (i)
    = n(n+1)/2

    sum (int n) // returns sum of n to 1
    if n <= 1
        return 1
    return n + sum(n - 1)
##
    n! = factorial i = 1 to n (i)
    