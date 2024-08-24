// maximum of all subarrays of size K
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

vector<int> maxOfSubArrays(const vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> maximums;
    int subArraymax = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        subArraymax = max(subArraymax, arr[i]);
    }
    maximums.push_back(subArraymax);

    for (int i = k; i < n; i++)
    {
    }
    return maximums;
}