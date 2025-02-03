// variable size sliding window- largest subarray of sum K
// return the size of the largest subarray that has sum k
#include <vector>
#include <iostream>
using namespace std;

// first solution without explanation or reference
int variable(vector<int> arr, int k)
{
    int n = arr.size();
    int sum = INT_MIN;
    int currentWindow;
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxLength = max(maxLength, currentWindow);
        }

        if (sum > k)
        {
            sum = arr[i];
        }
        if (sum < k)
        {
            sum += arr[i];
            currentWindow++;
        }
    }
    return maxLength;
}

// gpt reviewed
// currentWindow is not the size of the window but the starting index of the window
// sum>k is not handled properly
// self modified code
int variable1(vector<int> arr, int k)
{
    int n = arr.size();
    int sum = INT_MIN;
    int currentWindow = -1;
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        currentWindow++;

        if (sum == k)
        {
            maxLength = max(maxLength, i + 1 - currentWindow);
        }

        if (sum > k)
        {
            sum -= arr[currentWindow];
            currentWindow--;
        }
    }
    return maxLength;
}

// gpt review 2
int variable2(vector<int> arr, int k)
{
    int n = arr.size();
    int sum = 0; // previous value would cause loop
    int currentWindowIndex = -1;
    int maxLength = 0;

    // currentWindowIndex should be the variable name incrementing it would mean decrementing the window size
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == k)
        {
            maxLength = max(maxLength, i + 1 - currentWindowIndex);
        }

        if (sum > k and currentWindowIndex <= i)
        {
            sum -= arr[currentWindowIndex];
            currentWindowIndex;
        }
    }
    return maxLength;
}
// second review code is now perfect

// revision
int revision1(const vector<int> arr, int k)
{
    int n = arr.size();
    int sum = 0;
    int currentWindowIndex = 0;
    int maxWindow = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > k && currentWindowIndex <= i)
        {
            sum -= arr[currentWindowIndex];
            currentWindowIndex++;
        }
        if (sum == k)
        {
            maxWindow = max(maxWindow, i - currentWindowIndex + 1);
        }
    }
    return maxWindow;
}
// all edge cases control statements before the perfect match case