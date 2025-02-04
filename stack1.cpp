// Intro to stack and identification
/*

all question can be solved with brute force O(n^2)
DSA rounds need you to identify which D.S or algorithm  to use
to solve the question in O(best)

So identification is the most important thing

Identification
usually on array or heap (heap usually related to sorting)
if brute force solution is of O(n^2) and the inner loop has following patterns:
-> j= 0 to i j++
-> j= i to 0 j--
-> j=i to n j++
-> j=n to i j--
then it's likely it can be solved with stack




after identifying solve the variation
*/
#include <iostream>
#include <vector>
using namespace std;
int fibonacci(int n)
{
    if (n == 0)
    {
        return n;
    }
    if (n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// memoization - dp
int fibonacci_dp(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = fibonacci_dp(n - 1, dp) + fibonacci_dp(n - 2, dp);
}

// bottom-up iterative
int fibonacci_it(int n)
{
    vector<int> dp;
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// q1 - NGR | Nearest Greater to right | Next Largest Element
