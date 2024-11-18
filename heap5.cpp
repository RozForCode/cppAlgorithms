// q5- Top K frequent numbers
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// first answer without watching idea video or gpt
vector<int> q5(vector<int> arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> map;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;

    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
    }
    for (auto c : map)
    { // insertion mistake, queue check first value of pair which is key, so interchange it with frequency
        queue.push({c.first, c.second});
        if (queue.size() > k)
        {
            queue.pop();
        }
    }
    vector<int> result;
    while (!queue.empty())
    {
        result.push_back((queue.top()).first);
        queue.pop();
    }
    return result;
}

// time complexity O(n logK)