// q4- K closest numbers to a given value
// which heap to us - how to do the sorting
// to solve we need to put in heap pair - key(absolute difference of given number) and the index of the key in the original
// arr to return the result
// so its max heap as we want the smallest value
// by default heap is max heap
// if we want min heap - (in case we are solving for something largest) then we put greater<int>

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int *answer4(int *arr, int n, int k, int value)
{
    priority_queue<pair<int, int>> max;
    int *result = new int[k];

    for (int i = 0; i < n; i++)
    {
        max.push(make_pair((abs(arr[i] - value)), i));
        if (max.size() > k)
        {
            max.pop();
        }
    }
    int j = 0;
    while (!max.empty())
    {
        result[j] = arr[(max.top()).second];
        j++;
        max.pop();
    }
    return result;
}

// q4 again - K closest numbers to a given value
// min heap - could have used any heap

int *answer4_1(int *arr, int k, int value, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    int *result = new int[k];
    for (int i = 0; i < n; i++)
    {
        minHeap.push(make_pair(abs(arr[i] - value), i));
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }
    int j = 0;
    while (!minHeap.empty())
    {
        result[j] = arr[minHeap.top().second];
        minHeap.pop();
        j++;
    }
}

// Top K Frequent numbers
// this will be solved with the help of hash