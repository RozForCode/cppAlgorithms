// minimum window substring | variable size sliding window
#include <iostream>
#include <climits>
#include <string.h>
#include <unordered_map>
using namespace std;
// map[s[i]] = i;
int answer1(string s, string t)
{
    unordered_map<char, int> map;
    int n = s.length();
    int currentWindowIndex = 0;
    int size = 0;
    int minLength = INT_MAX;

    for (auto c : t)
    {
        map[c]++;
        size++;
    }
    for (int i = 0; i < n; i++)
    {
        if (map.find(s[i]) != map.end())
        {
            map[s[i]]--;
            size--;
        }
        if (size == 0)
        {
            minLength = min(minLength, i - currentWindowIndex + 1);
            currentWindowIndex++;
            if (map.find(s[currentWindowIndex]) != map.end())
            {
                map[s[currentWindowIndex]]++;
                size++;
            }
        }
    }
    return minLength;
}