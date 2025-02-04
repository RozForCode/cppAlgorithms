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
#include <stack>
vector<int> ngr(vector<int> arr)
{
    stack<int> st;
    vector<int> result;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        result.push_back(st.empty() ? -1 : st.top());
        st.push(arr[i]);
    }
    return result;
}

// Bitwise right shift for division and bitwise left shift for division
/*
Shifting a number n right by k positions is equivalent to dividing n by  2 to the power k
(integer division).

Formula:

n>>k=[ n/2(to the power )K]
*/

/*
Similarly shifting is like multiplying n to 2 to the power k
*/
// You are given an array of integers nums and an integer k.
// Your task is to find the maximum sum of a subarray (contiguous elements) such that the length of the subarray is at most k.

// deepseek answer
/*
it's like a o(n2) sliding window that is efficient
cause of adding prefix window on top of it the inner loops works much better
*/
int maxSubarraySumAtMostK(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxSum = INT_MIN;

    // Compute prefix sums
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    // Use a deque to maintain the minimum prefix sum in the current window
    deque<int> dq;
    dq.push_back(0); // Start with the first prefix sum

    for (int i = 1; i <= n; i++)
    {
        // Remove prefix sums outside the current window
        while (!dq.empty() && dq.front() < i - k)
        {
            dq.pop_front();
        }

        // Update the maximum sum
        if (!dq.empty())
        {
            int currentSum = prefixSum[i] - prefixSum[dq.front()];
            if (currentSum > maxSum)
            {
                maxSum = currentSum;
            }
        }

        // Maintain the deque in increasing order
        while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    return maxSum;
}