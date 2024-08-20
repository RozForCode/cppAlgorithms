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
int answer(const vector<int> arr, int K)
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