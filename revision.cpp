// day 1- 5
// qs
/*
// Q1- Maximum sum subarray of size K
// First negative number in window of size K
// count occurences of anagrams
// maximum of all subarrays of size K
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <climits>
#include <deque>
using namespace std;

// perfect on first try
int answer1(const vector<int> arr, int k)
{
    int n = arr.size();
    int maxSum = INT_MIN;
    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    for (int j = k; j < n; j++)
    {
        maxSum = max(sum, maxSum);
        sum -= arr[j - k];
        sum += arr[j];
    }
    return maxSum;
}

// had to see .begin() and .front() function usuage
vector<int> answer2(const vector<int> arr, int k)
{
    vector<int> answer;
    vector<int> negatives;
    int n = arr.size();

    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            negatives.push_back(arr[i]);
        }
    }
    for (int i = k; i < n; i++)
    {
        if (negatives.size() == 0)
        {
            answer.push_back(0);
        }
        else
        {
            answer.push_back(negatives.front());
        }
        if (arr[i] < 0)
        {
            negatives.push_back(arr[i]);
        }
        if (arr[i - k] < 0)
        {
            negatives.erase(negatives.begin());
        }
    }
    return answer;
} // perfect answer on first try

// q4 in leetcode
/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s.
You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.
*/
// had to realize that it is not variable size sliding window
vector<int> answer3(string s, string p)
{
    int n = s.length();
    int k = p.length();
    unordered_map<char, int> map;
    vector<int> result;

    for (auto c : p)
    {
        map[c]++;
    }

    int formed = 0;
    int required = map.size();
    for (int i = 0; i < k; i++)
    {
        if (map.find(s[i]) != map.end())
        {
            map[s[i]]--;
            if (map[s[i]] == 0)
            {
                formed++;
            }
        }
    }

    for (int i = k; i < n; i++)
    {
        if (formed == required)
        {
            result.push_back(i - k);
        }
        if (map.find(s[i]) != map.end())
        {
            map[s[i]]--;
            if (map[s[i]] == 0)
            {
                formed++;
            }
        }
        if (map.find(s[i - k]) != map.end())
        {
            map[s[i - k]]++;
            if (map[s[i - k]] == 1)
            {
                formed--;
            }
        }
    }
    return result;
}
// had to make some changes to this solution and cleared the leetcode q // handling of formed and result is a bit wrong rest all good

// maximum of all subarrays of size k