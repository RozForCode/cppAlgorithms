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

// gpt reviewed
// size after auto loop will be equal to t.length()-1

int answer1(string s, string t)
{
    unordered_map<char, int> map;
    int n = s.length();
    int currentWindowIndex = 0;
    int minLength = INT_MAX;

    // Initialize the map with frequencies of characters in t
    for (char c : t)
    {
        map[c]++;
    }
    int required = map.size();
    int formed = 0;

    // Two pointer approach with sliding window
    for (int r = 0; r < n; r++)
    {
        char c = s[r];

        if (map.find(c) != map.end())
        {
            map[c]--;
            if (map[c] == 0)
            {
                formed++;
            }
        }
        // when formed == required means found a valid window

        // if(formed==required){
        //     minLength= min(minLength,r-currentWindowIndex+1);

        // }
        // okay told gpt that it was wrong here and it should be a while loop till we find a relevant letter
        // also in case when the substring is in the latter section of the string this approach won't work with a while loop inside
    }
}