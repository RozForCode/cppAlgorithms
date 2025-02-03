// pick toys
// john goes to mall with his mother and sees a rack of toys
// mom gives him conditions - 1.toys picked should be continuous in the rack
// 2. He can pick 2 type of toys - toys should belong to maximum 2 types
// john wants maximum no.of toys from the given rack
// so variable size sliding window
// IP - string where a letter represents a type of toy

#include <iostream>
#include <unordered_map>
#include <string.h>
using namespace std;

// first implementation without any help
int answer1(string s)
{
    unordered_map<char, int> map;
    int maxToys = 0;
    int currentWindowIndex = 0;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (map.find(s[i]) != map.end())
        {
            map[s[i]] = i;
        }
        if (map.size() > 2)
        {
            map.erase(map.begin());
            maxToys = max(maxToys, i - currentWindowIndex + 1);
            currentWindowIndex = map.begin()->second;
        }
    }
    return maxToys;
}

// gpt review
//  maxToy should be tracked even when the map.size is less than 2
// we don't need to remove first element in the map
// the element that has to be removed is the min with the smallest index
int answer2(string s)
{
    unordered_map<char, int> map;

    int maxToys = 0;
    int currentWindowIndex = 0;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        map[s[i]] = i;
        if (map.size() > 2)
        {

            int minIndex = 2;
            char toyToRemove;

            // time complexity here is 0(1). so overall algo complexity remains 0(n)
            for (auto &pair : map)
            {
                if (pair.second < minIndex)
                {
                    minIndex = pair.second;
                    toyToRemove = pair.first;
                }
            }
            map.erase(toyToRemove);
            currentWindowIndex = minIndex + 1;
            maxToys = max(maxToys, i - currentWindowIndex + 1);
        }
    }
    return maxToys;
}
