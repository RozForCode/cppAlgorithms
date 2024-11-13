// day 1- 5
// qs
/*
// Q1- Maximum sum subarray of size K
// First negative number in window of size K
// q3 count occurences of anagrams
// q4 maximum of all subarrays of size K
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

// wow I actually solved this intuitively - last time with help of gpt and two map variables this time on my own with only one map
// next revision after a week
// and from then on after two weeks

// Q1- Maximum sum subarray of size K
int rev1(const vector<int> arr, int k)
{
    int n = arr.size();
    int maxValue = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (i >= k - 1)
        {
            maxValue = max(maxValue, sum);
            sum -= arr[i - k];
        }
    }
    return maxValue;
}

// First negative number in window of size K
// deque is the best LIFO ds, it is altered implementation of stack
// front() , pop_front(), push_back();
// it's useless to store actual value in the deque as we have access to the array in the entirety of the code
// pushing indexes into  the queue is better and gives us more flexibility
vector<int> rev2(const vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> result;
    deque<int> que;
    int i = 0;
    for (; i < k; i++)
    {
        if (arr[i] < 0)
        {
            que.push_back(i);
        }
    }
    for (; i < n; i++)
    {
        if (arr[i] < 0)
        {
            que.push_back(i);
        }
        if (que.size() == 0)
        {
            result.push_back(0);
        }
        else
        {
            result.push_back(arr[que.front()]);
        }
        if (i >= k && !que.empty() && que.front() < i - k + 1)
        {
            que.pop_front();
        }
    }
    return result;
}

// q3 count occurences of anagrams
int rev3(string s, string p)
{
    int n = s.length();
    unordered_map<char, int> map;
    int k = p.length();
    int count = 0;
    int answer;
    for (auto c : s)
    {
        map[c]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (map.find(s[i]) != map.end())
        {
            map[s[i]]--;
            if (map[s[i]] == 0)
            {
                count++;
            }
        }
        if (count == map.size())
        {
            answer++;
        }
        if (i >= k)
        {
            if (map.find(s[i - k]) != map.end())
            {
                map[s[i - k]]++;
                if (map[s[i - k]] == 1)
                {
                    count--;
                }
            }
        }
    }
    return answer;
}

// q4 maximum of all subarrays of size K

int rev4(const vector<int> arr, int k)
{
    int n = arr.size();
    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    int maxValue = sum;
    for (int i = k; i < n; i++)
    {

        sum += arr[i] - arr[i - k];
        maxValue = max(maxValue, sum);
    }
    return maxValue;
}

// q6 - // variable size sliding window- largest subarray of sum K,return the size of the largest subarray that has sum k

int rev6(const vector<int> arr, int sum)
{
    int n = arr.size();
    int ourSum = 0;
    int maxLength = 0;
    int currentWindowIndex = 0;

    for (int i = 0; i < n; i++)
    {
        ourSum += arr[i];
        if (ourSum == sum)
        {
            maxLength = max(maxLength, i - currentWindowIndex + 1);
            ourSum -= arr[currentWindowIndex];
            currentWindowIndex++;
        }
        while (ourSum > sum)
        {
            ourSum -= arr[currentWindowIndex];
            currentWindowIndex++;
        }
    }
    return maxLength;
}

// q7 -  Longest substring with non-repeating characters

int rev7(string &s)
{
    int n = s.length();
    int maxLength = 0;
    int currentWindowIndex = 0;
    unordered_map<char, int> map;

    for (int i = 0; i < n; i++)
    {
        if (map.find(s[i]) != map.end())
        {
            // update maxlength, currentWindowIndex
            maxLength = max(maxLength, i - currentWindowIndex + 1);
            currentWindowIndex = map[s[i]] + 1;
        }
        map[s[i]] = i;
    }
    return maxLength;
}

// q8 start
// pick toys
// john goes to mall with his mother and sees a rack of toys
// mom gives him conditions - 1.toys picked should be continous in the rack
// 2. He can pick 2 type of toys - toys should belong to maximum 2 types
// john wants maximum no.of toys from the given rack
// so variable size sliding window
// IP - string where a letter represents a type of toy
// q8 end

int rev8(string &s)
{
    unordered_map<char, int> map;
    int n = s.length();
    int maxLength = 0;
    int currentWindowIndex = 0;

    for (int i = 0; i < n; i++)
    {
        if (map.size() == 2 && map.find(s[i]) == map.end())
        {
            // update currentWindowIndex to 1+last occurence of map pair with smallest int value, update maxLength
            maxLength = max(maxLength, i - currentWindowIndex + 1);
            int minIndex = INT_MAX;
            for (auto pair : map)
            {
                if (pair.second < minIndex)
                {
                    minIndex = pair.second;
                }
            }
            map.erase(s[minIndex]);
            currentWindowIndex = minIndex + 1;
        }
        map[s[i]] = i;
    }
    return maxLength;
}

// q9 - minimum window substring - shortest window that has all the character in second parameter string

int rev9(string s, string p)
{
    int n = s.length();
    int k = p.length();
    unordered_map<char, int> map;
    int currentWindowIndex = 0;
    int minLength = INT_MAX;

    for (auto c : p)
    {
        map[c]++;
    }

    int count = map.size();

    for (int i = 0; i < n; i++)
    {
        if (map.find(s[i]) == map.end())
        {
            map[s[i]]--;
            if (map[s[i]] == 0)
            {
                count--;
            }
        }

        while (count == 0)
        {
            minLength = min(minLength, i - currentWindowIndex + 1);

            if (map.find(s[currentWindowIndex]) != map.end())
            {
                map[currentWindowIndex]++;
                if (map[currentWindowIndex] == 1)
                {
                    count++;
                }
            }
            currentWindowIndex++;
        }
    }
    return minLength;
}

// restarting revision
// Q1- Maximum sum subarray of size K
// Q2 return collection of First negative number in window of size K
// q3 count occurences of anagrams - An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
// q4 maximum of all subarrays of size K

// variable size sliding window
// q6 - - largest subarray of sum K,return the size of the largest subarray that has sum k
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

int restart1(const vector<int> &arr, int k)
{
    int n = arr.size();
    int current = 0;
    int maxValue = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        current += arr[i];
        if (i > k)
        {
            current -= arr[i - k];
        }
        maxValue = current > maxValue ? current : maxValue;
    }
    return maxValue;
}

vector<int> restart2(const vector<int> &arr, int k)
{
    vector<int> negatives;
    vector<int> answer;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            negatives.push_back(arr[i]);
        }
        if (i >= k)
        {
            if (i > k && arr[i - k] < 0)
            {
                negatives.erase(negatives.begin());
            }
            if (negatives.size() == 0)
            {
                answer.push_back(0);
            }
            else
            {
                answer.push_back(negatives.front());
            }
        }
    }
    return answer;
}

int restart3(string s, string p)
{
    unordered_map<char, int> map;
    int n = s.size();
    int window = p.size();
    int current = 0;
    int formed = 0;
    int answer = 0;

    for (auto c : p)
    {
        if (map[c] != 0)
        {
            formed++;
        }
        map[c]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (i > window && map.find(s[i - window]) != map.end())
        {
            map[s[i - window]]--;
            if (map[s[i - window]] == 0)
            {
                current--;
            }
        }
        map[s[i]]++;
        if (map[s[i]] == 1)
        {
            current++;
        }
        if (current == formed)
        {
            answer++;
        }
    }
    return answer;
}

int restart4(const vector<int> &arr, int k)
{
    int maxOfall = 0;
    int n = arr.size();
    int current = 0;

    for (int i = 0; i < n; i++)
    {
        if (i >= k)
        {
            current -= arr[i - k];
        }
        current += arr[i];
        maxOfall = max(maxOfall, current);
    }
    return maxOfall;
}

int restart6(const vector<int> &arr, int k)
{
    int currentWindow = 0;
    int sum = 0;
    int n = arr.size();
    int maxWindow = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        while (sum > k && currentWindow < i)
        {
            sum -= arr[currentWindow];
            currentWindow++;
        }
        if (sum == k)
        {
            maxWindow = max(maxWindow, i - currentWindow + 1);
        }
    }
    return maxWindow;
}

int restart7(string s)
{
    int i = 0;
    unordered_map<char, int> map;
    int n = s.size();
    int maxSize = 0;
    int currentWindow = 0;
    for (i; i < n; i++)
    {
        if (map.find(s[i]) != map.end())
        {
            maxSize = max(maxSize, i - currentWindow + 1);
            while (currentWindow < i && !(map[s[i]] == 0))
            {
                map[currentWindow]--;
                currentWindow++;
            }
        }
        map[s[i]]++;
    }
    return maxSize;
}

int restart8(string s)
{
    int maxSize = 0;
    int i = 0;
    int n = s.size();
    int currentWindow = 0;
    unordered_map<char, int> map;
    for (int i = 0; i < n; i++)
    {
        if (map.size() == 2 && map.find(s[i]) == map.end())
        { // new entry
            maxSize = max(maxSize, i - currentWindow + 1);
            int smaller = INT_MIN;
            int charOfSmaller;
            for (auto pair : map)
            {
                if (smaller > pair.second)
                {
                    smaller = pair.second;
                    charOfSmaller = pair.first;
                }
            }
            currentWindow = smaller + 1;
            map.erase(charOfSmaller);
        }
        map[s[i]] = i;
    }
    return maxSize;
}

// q9 easy similar to q3 with formed and required but here it should be required > formed instead of required== formed