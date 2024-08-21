#include <vector>
#include <iostream>
#include <climits>
using namespace std;

// First negative number in window of size K
vector<int> answer1(const vector<int> arr, int K)
{
    int n = arr.size();
    vector<int> negatives;
    vector<int> result;
    for (int i = 0; i < K; i++)
    {
        if (arr[i] < 0)
        {
            negatives.push_back(arr[i]);
        }
    }
    for (int i = K; i < n; i++)
    {
        if (negatives.size() == 0)
        {
            result.push_back(0);
        }
        else
        {

            result.push_back(negatives.front());
        }

        if (arr[i] < 0)
        {
            negatives.push_back(arr[i]);
        }
        if (arr[i - K] < 0)
        {
            negatives.erase(negatives.begin());
        }
    }
    return result;
}