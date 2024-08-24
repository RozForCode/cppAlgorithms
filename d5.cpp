// maximum of all subarrays of size K
#include <vector>
#include <iostream>
#include <deque>
using namespace std;

vector<int> maxOfSubArrays(const vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> result;
    deque<int> maximums;
    for (int i = 0; i < n; i++)
    {
        if (!maximums.empty() && maximums.front() == i - k)
        {
            maximums.pop_front();
        }
        if (!maximums.empty() && arr[maximums.back()] <= arr[i])
        {
            maximums.pop_back();
        }
        maximums.push_back(i);
        if (i >= k - 1)
        {
            result.push_back(arr[maximums.front()]);
        }
    }
    return result;
}
// this sliding window solution implements a deque and simple if statements for the deque to maintain index of the maximum value in the array
// why stores indexes instead of maximum values in the dq? -> 1. deals with duplicates 2. indow Boundaries: When you store indices, you can easily check if the front of the deque is out of the current window using maximums.front() == i - k.