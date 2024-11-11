// q6 Frequency sort

/*
Problem Statement: Frequency Sort (Heap Problem)
You are given an array of integers, and your task is to sort the array based on the frequency of each number.
The numbers with a higher frequency should come first. If two numbers have the same frequency, the number with the higher value
should come first. The goal is to return the array sorted according to these rules.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> answer(vector<int> arr)
{
    vector<int> result;
    // max heap
    priority_queue<pair<int, int>, vector<pair<int, int>>> max;
    unordered_map<int, int> map;
    for (auto i : arr)
    {
        map[i]++;
    }
    int n = arr.size();

    for (auto pair : map)
    {
        max.push({pair.first, pair.second});
    }
    int j;
    while (!max.empty())
    {
        j = max.top().second;
        while (j != 0)
        {
            result.push_back(max.top().first);
        }
        max.pop();
    }

    return result;
}

// mistakes
//  since priority_queue by default orders pairs by the first element in descending order,
// pushing {frequency, number} will ensure that the element with the highest frequency is on top.

vector<int> answer(vector<int> arr)
{
    vector<int> result;
    // max heap
    priority_queue<pair<int, int>, vector<pair<int, int>>> max;
    unordered_map<int, int> map;
    for (auto i : arr)
    {
        map[i]++;
    }
    int n = arr.size();

    for (auto pair : map)
    {
        max.push({pair.second, pair.first});
    }
    int j;
    while (!max.empty())
    {
        j = max.top().first;
        while (j != 0)
        {
            result.push_back(max.top().second);
            j--;
        }
        max.pop();
    }

    return result;
}