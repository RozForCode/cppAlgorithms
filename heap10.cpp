// Sum of Elements between k1 smallest and k2 smallest numbers
/*
Given an array of integers and two integers k1 and k2, the task is to find
the sum of the elements between the k1-th smallest and the k2-th smallest numbers in the array.
*/
// O(k log n)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// my answer
int answer(const vector<int> arr, int k1, int k2)
{
    int result = 0;
    int n = arr.size();
    priority_queue<int> max;

    for (int i = 0; i < n; i++)
    {
        max.push(arr[i]);
        if (max.size() > k1)
        {
            max.pop();
        }
    }
    int i = 0;
    while (i < (k1 - k2))
    {
        result += max.top();
        max.pop();
        i++;
    }

    return result;
}

// gpt reviewed
// my answer
// turns out my answer is perfect!!!!!!
int answer(const vector<int> arr, int k1, int k2)
{
    int result = 0;
    int n = arr.size();
    priority_queue<int> max;

    for (int i = 0; i < n; i++)
    {
        max.push(arr[i]);
        if (max.size() > k1)
        {
            max.pop();
        }
    }
    int i = 0;
    while (i < (k1 - k2))
    {
        result += max.top();
        max.pop();
        i++;
    }

    return result;
}
