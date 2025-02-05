// Sliding window problems
// aim is to do 5 fixed size prob and 5 variable
// Q1- Maximum sum subarray of size K

// identification- array/string type, size, subarray/substring/etc

// window size always = endofwindow(j)-startOfWindow(i)+1

// start with i=0,j=0 and check
//  j-i+1 < K -> j++ , also keep incrementing sum so that no number is added twice
//  j-i+1 > K -> i++ , keep decrementing sum
//  j-i+1 = K -> got correct subarray -> maintian and calc code and j++,i++ both incre and decre
// then we update the result variable like max with that subarray and whenever conditions are met we check and update that variable

// sliding window code using only one variable - for start of the window in the second loop use - (K-i) where i is the end of the window

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int answer1(const vector<int> arr, int K)
{
    int n = arr.size();

    // creating first window
    //  if we create window in a separate loop then formula j-i+1 = K changes to j-i = K
    int maxSum = INT_MIN;
    int windowsum = 0;
    // creating first window
    for (int i = 0; i < K; i++)
    {
        windowsum += arr[i];
    }

    // second loop
    for (int i = K; i < n; i++)
    {
        windowsum += arr[i] - arr[K - i];
        maxSum = max(maxSum, windowsum);
    }
    return maxSum;
}

// using two pointers and one loop
int answer2(const vector<int> arr, int K)
{
    int n = arr.size();

    int maxSum = INT_MIN;
    int windowsum = 0;
    for (int i = 0, j = 0; j < n;)
    {
        if ((j - i + 1) < K)
        {
            windowsum += arr[j];
            j++;
        }
        else if ((j - i + 1) == K)
        {
            windowsum += arr[j] - arr[i];
            j++;
            i++;
        }
        else
        {
            i++;
        }
        maxSum = max(maxSum, windowsum);
    }
    return maxSum;
}
// answer 2 revised
int answer3(const vector<int> arr, int K)
{
    int n = arr.size();

    int maxSum = INT_MIN;
    int windowsum = 0;
    for (int i = 0, j = 0; j < n;)
    {
        for (j; j < K; j++)
        {
            windowsum += arr[j];
        }
        maxSum = windowsum;
        if (j < n + 1)
        {
            j++;
            windowsum += arr[j] - arr[i];
            i++;
            maxSum = max(maxSum, windowsum);
        }
    }
    return maxSum;
}
// answer 2 remade
int answer3(const vector<int> arr, int K)
{
    int n = arr.size();

    int windowsum = 0;
    for (int j = 0; j < K; j++)
    {
        windowsum += arr[j];
    }
    int maxSum = windowsum;

    for (int i = 0, j; j < n; j++, i++)
    {

        windowsum += arr[j] - arr[i];

        maxSum = max(maxSum, windowsum);
    }
    return maxSum;
}

// max subarray revision
int answer4(const vector<int> arr, int K)
{
    int n = arr.size();
    int windowSum = 0;
    for (int i = 0; i < K; i++)
    {
        windowSum += arr[i];
    }
    int maxSum = windowSum;
    for (int i = K; i < n; i++)
    {
        windowSum += arr[i] - arr[i - K];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}
// so next day revision I did with my instinct one variable 2 loop solution

int answer5(const vector<int> arr, int K)
{
    int windowSum;
    int n = arr.size();
    for (int i = 0; i < K; i++)
    {
        windowSum += arr[i];
    }
    int maxSum = windowSum;
    for (int i = K; i < n; i++)
    {
        windowSum += arr[i] - arr[i - K];
        maxSum = max(windowSum, maxSum);
    }
    return maxSum;
}

int answer6(const vector<int> arr, int k)
{
    int windowSum;
    int n = arr.size();
    for (int i = 0; i < k; i++)
    {
        windowSum += arr[i];
    }
    int maxSum = windowSum;
    for (int i = k; i < n; i++)
    {
        windowSum = arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}