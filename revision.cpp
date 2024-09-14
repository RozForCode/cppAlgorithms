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

// day 6-9 - variable sliding window
// q6 - // variable size sliding window- largest subarray of sum K,return the size of the largest subarray that has sum k

// q7 -  Longest substring with non-repeating characters
// q8 start
// pick toys
// john goes to mall with his mother and sees a rack of toys
// mom gives him conditions - 1.toys picked should be continous in the rack
// 2. He can pick 2 type of toys - toys should belong to maximum 2 types
// john wants maximum no.of toys from the given rack
// so variable size sliding window
// IP - string where a letter represents a type of toy
// q8 end
// q9 - minimum window substring - shortest window that has all the character in second parameter string

int q6(const vector<int> arr, int k)
{
    int n = arr.size();
    int currentWindowIndex = 0;
    int sum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxLength = max(maxLength, i - currentWindowIndex + 1);
        }
        while (sum > k)
        {
            sum -= arr[currentWindowIndex];
            currentWindowIndex++;
        }
    }
    return maxLength;
}

int q7(string s)
{
    int n = s.length();
    int maxLength = 0;
    int currentWindowIndex = 0;
    unordered_map<char, int> map;

    for (int i = 0; i < n; i++)
    {
        if (map.find(s[i]) != map.end())
        {
            maxLength = max(maxLength, i - currentWindowIndex + 1);
            currentWindowIndex = map[s[i]] + 1;
            map[s[i]] = i;
        }
        map[s[i]] = i;
    }
    return maxLength;
}

int q8(string s)
{
    int n = s.length();
    int currentWindowIndex = 0;
    int maxToys = 0;
    unordered_map<char, int> map;

    for (int i = 0; i < n; i++)
    {
        map[s[i]] = i;
        if (map.size() > 2)
        {
            char toyToRemove;
            for (auto &p : map)
            {
                int minIndex = n;
                if (p.second < minIndex)
                {
                    minIndex = p.second;
                    toyToRemove = p.first;
                }
            }
            currentWindowIndex = map[toyToRemove] + 1;
            map.erase(toyToRemove);
        }
        maxToys = max(maxToys, i - currentWindowIndex + 1);
    }
    return maxToys;
}

// lets fo it later.
int q9(string s, string p)
{
    int n = s.length();
    int k = p.length();
    int maxLength = 0;
    unordered_map<char, int> map;
    int currentWindowIndex = 0;

    for (int i = 0; i < n; i++)
    {
        map[s[i]] = i;
        if (map.size() == k)
        {
            maxLength = max(maxLength, i - currentWindowIndex + 1);
            int minIndex = n;
            char tobeErased;
            for (auto &p : map)
            {
                if (p.second < minIndex)
                {
                    minIndex = p.second;
                    tobeErased = p.first;
                }
            }
            currentWindowIndex = minIndex + 1;
            map.erase(tobeErased);
        }
    }
    return maxLength;
}