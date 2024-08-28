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
        if (sum == k)
        {
            maxLength = max(maxLength, currentWindow);
            sum += arr[i] - arr[i - currentWindow];
        }
        else
        {
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
    }
    return maxLength;
}

// gpt reviewed
