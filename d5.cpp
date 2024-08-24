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