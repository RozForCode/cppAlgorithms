// count occurences of anagrams
// anagrams - jumpbled forms of a word
#include <vector>
#include <iostream>
#include <climits>
#include <string.h>
#include <unordered_map>
using namespace std;

// mix of brute force and sliding window
int answer(string s, string ptr)
{
    int count = 0;
    int ptrLen = ptr.length();
    int n = s.size();
    vector<string> anagrams;

    // first find all anagrams and then look for anagrams

    // after finding anagrams apply sliding window
    string finder;
    for (int i = 0; i < ptrLen; i++)
    {
        finder.push_back(s[i]);
    }
    for (int i = ptrLen; i < n; i++)
    {
        for (int i = 0; i < anagrams.size(); i++)
        {
            if (anagrams[i] == finder)
            {
                count++;
            }
        }
        finder.erase(0, 1);
        finder.push_back(s[i]);
    }
    return count;
}

// sliding window - this problem requires a smart and efficient way to deal with anagrams.. implementing the sliding window itself is easy.
// need to make a map and implement a way as to not traverse that map again and again.

int countAnagrams(const string &s, const string &ptr)
{
    int ans;
    unordered_map<char, int> map;
    return ans;
}