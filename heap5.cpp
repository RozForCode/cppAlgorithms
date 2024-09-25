// q5- Top K frequent numbers
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// first answer without watching idea video or gpt
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<int>> q5(vector<int> arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> map;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<int>> queue;

    for (int i = 0; i < n; i++)
    {
        map[i]++;
    }
    for (auto c : map)
    {
        queue.push(make_pair(c.first, c.second));
        if (queue.size() > k)
        {
            queue.pop();
        }
    }
    return queue;
}

// after watching video and gpt reviewed